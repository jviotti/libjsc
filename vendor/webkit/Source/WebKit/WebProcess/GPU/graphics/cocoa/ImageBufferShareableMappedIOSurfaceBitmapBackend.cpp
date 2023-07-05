/*
 * Copyright (C) 2020-2023 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "ImageBufferShareableMappedIOSurfaceBitmapBackend.h"

#if ENABLE(GPU_PROCESS) && HAVE(IOSURFACE)

#include "Logging.h"
#include <WebCore/GraphicsContextCG.h>
#include <WebCore/IOSurfacePool.h>
#include <wtf/IsoMallocInlines.h>
#include <wtf/StdLibExtras.h>
#include <wtf/spi/cocoa/IOSurfaceSPI.h>

namespace WebKit {
using namespace WebCore;

WTF_MAKE_ISO_ALLOCATED_IMPL(ImageBufferShareableMappedIOSurfaceBitmapBackend);

std::unique_ptr<ImageBufferShareableMappedIOSurfaceBitmapBackend> ImageBufferShareableMappedIOSurfaceBitmapBackend::create(const Parameters& parameters, const ImageBufferCreationContext& creationContext)
{
    IntSize backendSize = ImageBufferIOSurfaceBackend::calculateSafeBackendSize(parameters);
    if (backendSize.isEmpty())
        return nullptr;

    auto surface = IOSurface::create(creationContext.surfacePool, backendSize, parameters.colorSpace, IOSurface::Name::ImageBuffer, IOSurface::formatForPixelFormat(parameters.pixelFormat));
    if (!surface)
        return nullptr;

    auto lockAndContext = surface->createBitmapPlatformContext();
    if (!lockAndContext)
        return nullptr;
    CGContextClearRect(lockAndContext->context.get(), FloatRect(FloatPoint::zero(), backendSize));
    return makeUnique<ImageBufferShareableMappedIOSurfaceBitmapBackend>(parameters, WTFMove(surface), WTFMove(*lockAndContext), creationContext.surfacePool);
}

ImageBufferShareableMappedIOSurfaceBitmapBackend::ImageBufferShareableMappedIOSurfaceBitmapBackend(const Parameters& parameters, std::unique_ptr<IOSurface> surface, IOSurface::LockAndContext&& lockAndContext, IOSurfacePool* ioSurfacePool)
    : ImageBufferCGBackend(parameters)
    , m_surface(WTFMove(surface))
    , m_lock(WTFMove(lockAndContext.lock))
    , m_ioSurfacePool(ioSurfacePool)
{
    m_context = makeUnique<GraphicsContextCG>(lockAndContext.context.get());
    applyBaseTransform(*m_context);
}

ImageBufferBackendHandle ImageBufferShareableMappedIOSurfaceBitmapBackend::createBackendHandle(SharedMemory::Protection) const
{
    return ImageBufferBackendHandle(m_surface->createSendRight());
}

GraphicsContext& ImageBufferShareableMappedIOSurfaceBitmapBackend::context()
{
    if (!m_context) {
        auto lockAndContext = m_surface->createBitmapPlatformContext();
        if (lockAndContext) {
            m_lock = WTFMove(lockAndContext->lock);
            m_context = makeUnique<GraphicsContextCG>(lockAndContext->context.get());
        } else
            m_context = makeUnique<GraphicsContextCG>(nullptr);
        applyBaseTransform(*m_context);
    }
    return *m_context;
}

void ImageBufferShareableMappedIOSurfaceBitmapBackend::setOwnershipIdentity(const WebCore::ProcessIdentity& resourceOwner)
{
    m_surface->setOwnershipIdentity(resourceOwner);
}

IntSize ImageBufferShareableMappedIOSurfaceBitmapBackend::backendSize() const
{
    return m_surface->size();
}

unsigned ImageBufferShareableMappedIOSurfaceBitmapBackend::bytesPerRow() const
{
    return m_surface->bytesPerRow();
}

RefPtr<NativeImage> ImageBufferShareableMappedIOSurfaceBitmapBackend::copyNativeImage(BackingStoreCopy copyBehavior)
{
    ASSERT_NOT_REACHED(); // Not applicable for LayerBacking.
    return nullptr;
}

RefPtr<NativeImage> ImageBufferShareableMappedIOSurfaceBitmapBackend::copyNativeImageForDrawing(GraphicsContext&)
{
    ASSERT_NOT_REACHED(); // Not applicable for LayerBacking.
    return nullptr;
}

RefPtr<NativeImage> ImageBufferShareableMappedIOSurfaceBitmapBackend::sinkIntoNativeImage()
{
    ASSERT_NOT_REACHED(); // Not applicable for LayerBacking.
    return nullptr;
}

bool ImageBufferShareableMappedIOSurfaceBitmapBackend::isInUse() const
{
    return m_surface->isInUse();
}

void ImageBufferShareableMappedIOSurfaceBitmapBackend::releaseGraphicsContext()
{
    m_context = nullptr;
    m_lock = std::nullopt;
}

bool ImageBufferShareableMappedIOSurfaceBitmapBackend::setVolatile()
{
    if (m_surface->isInUse())
        return false;

    setVolatilityState(VolatilityState::Volatile);
    m_surface->setVolatile(true);
    return true;
}

SetNonVolatileResult ImageBufferShareableMappedIOSurfaceBitmapBackend::setNonVolatile()
{
    setVolatilityState(VolatilityState::NonVolatile);
    return m_surface->setVolatile(false);
}

VolatilityState ImageBufferShareableMappedIOSurfaceBitmapBackend::volatilityState() const
{
    return m_volatilityState;
}

void ImageBufferShareableMappedIOSurfaceBitmapBackend::setVolatilityState(VolatilityState volatilityState)
{
    m_volatilityState = volatilityState;
}

void ImageBufferShareableMappedIOSurfaceBitmapBackend::transferToNewContext(const ImageBufferCreationContext&)
{
    ASSERT_NOT_REACHED(); // Not applicable for LayerBacking.
}

void ImageBufferShareableMappedIOSurfaceBitmapBackend::getPixelBuffer(const IntRect&, PixelBuffer&)
{
    ASSERT_NOT_REACHED(); // Not applicable for LayerBacking.
}

void ImageBufferShareableMappedIOSurfaceBitmapBackend::putPixelBuffer(const PixelBuffer&, const IntRect&, const IntPoint&, AlphaPremultiplication)
{
    ASSERT_NOT_REACHED(); // Not applicable for LayerBacking.
}

} // namespace WebKit

#endif // ENABLE(GPU_PROCESS) && HAVE(IOSURFACE)
