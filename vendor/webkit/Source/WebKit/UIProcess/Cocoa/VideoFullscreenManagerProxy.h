/*
 * Copyright (C) 2014 Apple Inc. All rights reserved.
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

#pragma once

#if ENABLE(VIDEO_PRESENTATION_MODE)

#include "LayerHostingContext.h"
#include "MessageReceiver.h"
#include "PlaybackSessionContextIdentifier.h"
#include "ShareableBitmap.h"
#include <WebCore/AudioSession.h>
#include <WebCore/MediaPlayerIdentifier.h>
#include <WebCore/PlatformLayer.h>
#include <WebCore/PlatformView.h>
#include <WebCore/VideoFullscreenModel.h>
#include <wtf/HashMap.h>
#include <wtf/HashSet.h>
#include <wtf/Observer.h>
#include <wtf/RefPtr.h>
#include <wtf/WeakHashSet.h>
#include <wtf/text/WTFString.h>

#if PLATFORM(IOS_FAMILY)
#include <WebCore/VideoFullscreenInterfaceAVKit.h>
typedef WebCore::VideoFullscreenInterfaceAVKit PlatformVideoFullscreenInterface;
#else
#include <WebCore/VideoFullscreenInterfaceMac.h>
typedef WebCore::VideoFullscreenInterfaceMac PlatformVideoFullscreenInterface;
#endif

OBJC_CLASS WKLayerHostView;
OBJC_CLASS WebAVPlayerLayer;
OBJC_CLASS WebAVPlayerLayerView;

namespace WebKit {

constexpr size_t DefaultMockPictureInPictureWindowWidth = 100;
constexpr size_t DefaultMockPictureInPictureWindowHeight = 100;

class WebPageProxy;
class PlaybackSessionManagerProxy;
class PlaybackSessionModelContext;
class VideoFullscreenManagerProxy;

class VideoFullscreenModelContext final
    : public WebCore::VideoFullscreenModel  {
public:
    static Ref<VideoFullscreenModelContext> create(VideoFullscreenManagerProxy& manager, PlaybackSessionModelContext& playbackSessionModel, PlaybackSessionContextIdentifier contextId)
    {
        return adoptRef(*new VideoFullscreenModelContext(manager, playbackSessionModel, contextId));
    }
    virtual ~VideoFullscreenModelContext();

    void invalidate() { m_manager = nullptr; }

    PlatformView *layerHostView() const { return m_layerHostView.get(); }
    void setLayerHostView(RetainPtr<PlatformView>&& layerHostView) { m_layerHostView = WTFMove(layerHostView); }

    WebAVPlayerLayer *playerLayer() const { return m_playerLayer.get(); }
    void setPlayerLayer(RetainPtr<WebAVPlayerLayer>&& playerLayer) { m_playerLayer = WTFMove(playerLayer); }

#if PLATFORM(IOS_FAMILY)
    WebAVPlayerLayerView *playerView() const { return m_playerView.get(); }
    void setPlayerView(RetainPtr<WebAVPlayerLayerView>&& playerView) { m_playerView = WTFMove(playerView); }
#endif

    void requestCloseAllMediaPresentations(bool finishedWithMedia, CompletionHandler<void()>&&);

private:
    friend class VideoFullscreenManagerProxy;
    VideoFullscreenModelContext(VideoFullscreenManagerProxy&, PlaybackSessionModelContext&, PlaybackSessionContextIdentifier);

    void setVideoDimensions(const WebCore::FloatSize&);

    // VideoFullscreenModel
    void addClient(WebCore::VideoFullscreenModelClient&) override;
    void removeClient(WebCore::VideoFullscreenModelClient&) override;
    void requestFullscreenMode(WebCore::HTMLMediaElementEnums::VideoFullscreenMode, bool finishedWithMedia = false) override;
    void setVideoLayerFrame(WebCore::FloatRect) override;
    void setVideoLayerGravity(WebCore::MediaPlayerEnums::VideoGravity) override;
    void fullscreenModeChanged(WebCore::HTMLMediaElementEnums::VideoFullscreenMode) override;
    bool hasVideo() const override { return m_hasVideo; }
    WebCore::FloatSize videoDimensions() const override { return m_videoDimensions; }
#if PLATFORM(IOS_FAMILY)
    UIViewController *presentingViewController() final;
    RetainPtr<UIViewController> createVideoFullscreenViewController(AVPlayerViewController*) final;
#endif
    void willEnterPictureInPicture() final;
    void didEnterPictureInPicture() final;
    void failedToEnterPictureInPicture() final;
    void willExitPictureInPicture() final;
    void didExitPictureInPicture() final;
    void requestRouteSharingPolicyAndContextUID(CompletionHandler<void(WebCore::RouteSharingPolicy, String)>&&) final;

    void requestUpdateInlineRect() final;
    void requestVideoContentLayer() final;
    void returnVideoContentLayer() final;
    void returnVideoView() final;
    void didSetupFullscreen() final;
    void failedToEnterFullscreen() final;
    void didEnterFullscreen(const WebCore::FloatSize&) final;
    void willExitFullscreen() final;
    void didExitFullscreen() final;
    void didCleanupFullscreen() final;
    void fullscreenMayReturnToInline() final;

#if !RELEASE_LOG_DISABLED
    const void* logIdentifier() const final;
    const void* nextChildIdentifier() const final;
    const Logger* loggerPtr() const final;

    const char* logClassName() const { return "VideoFullscreenModelContext"; };
    WTFLogChannel& logChannel() const;
#endif

    VideoFullscreenManagerProxy* m_manager;
    Ref<PlaybackSessionModelContext> m_playbackSessionModel;
    PlaybackSessionContextIdentifier m_contextId;
    RetainPtr<PlatformView> m_layerHostView;
    RetainPtr<WebAVPlayerLayer> m_playerLayer;

#if PLATFORM(IOS_FAMILY)
    RetainPtr<WebAVPlayerLayerView> m_playerView;
#endif

    HashSet<WebCore::VideoFullscreenModelClient*> m_clients;
    WebCore::FloatSize m_videoDimensions;
    bool m_hasVideo { false };

#if !RELEASE_LOG_DISABLED
    mutable uint64_t m_childIdentifierSeed { 0 };
#endif
};

class VideoFullscreenManagerProxy : public RefCounted<VideoFullscreenManagerProxy>, private IPC::MessageReceiver {
public:
    static Ref<VideoFullscreenManagerProxy> create(WebPageProxy&, PlaybackSessionManagerProxy&);
    virtual ~VideoFullscreenManagerProxy();

    void invalidate();

    void requestHideAndExitFullscreen();
    bool hasMode(WebCore::HTMLMediaElementEnums::VideoFullscreenMode) const;
    bool mayAutomaticallyShowVideoPictureInPicture() const;
    void applicationDidBecomeActive();
    bool isVisible() const;

    void setMockVideoPresentationModeEnabled(bool enabled) { m_mockVideoPresentationModeEnabled = enabled; }

    void requestRouteSharingPolicyAndContextUID(PlaybackSessionContextIdentifier, CompletionHandler<void(WebCore::RouteSharingPolicy, String)>&&);

    bool isPlayingVideoInEnhancedFullscreen() const;

    PlatformVideoFullscreenInterface* controlsManagerInterface();
    using VideoInPictureInPictureDidChangeObserver = WTF::Observer<void(bool)>;
    void addVideoInPictureInPictureDidChangeObserver(const VideoInPictureInPictureDidChangeObserver&);

    void forEachSession(Function<void(VideoFullscreenModelContext&, PlatformVideoFullscreenInterface&)>&&);

    void requestBitmapImageForCurrentTime(PlaybackSessionContextIdentifier, CompletionHandler<void(ShareableBitmap::Handle&&)>&&);

#if PLATFORM(IOS_FAMILY)
    AVPlayerViewController *playerViewController(PlaybackSessionContextIdentifier) const;
    RetainPtr<WebAVPlayerLayerView> createViewWithID(PlaybackSessionContextIdentifier, WebKit::LayerHostingContextID videoLayerID, const WebCore::FloatSize& initialSize, const WebCore::FloatSize& nativeSize, float hostingScaleFactor);
#endif

    PlatformLayerContainer createLayerWithID(PlaybackSessionContextIdentifier, WebKit::LayerHostingContextID videoLayerID, const WebCore::FloatSize& initialSize, const WebCore::FloatSize& nativeSize, float hostingScaleFactor);

    void willRemoveLayerForID(PlaybackSessionContextIdentifier);

private:
    friend class VideoFullscreenModelContext;

    explicit VideoFullscreenManagerProxy(WebPageProxy&, PlaybackSessionManagerProxy&);
    void didReceiveMessage(IPC::Connection&, IPC::Decoder&) override;

    typedef std::tuple<RefPtr<VideoFullscreenModelContext>, RefPtr<PlatformVideoFullscreenInterface>> ModelInterfaceTuple;
    ModelInterfaceTuple createModelAndInterface(PlaybackSessionContextIdentifier);
    ModelInterfaceTuple& ensureModelAndInterface(PlaybackSessionContextIdentifier);
    VideoFullscreenModelContext& ensureModel(PlaybackSessionContextIdentifier);
    PlatformVideoFullscreenInterface& ensureInterface(PlaybackSessionContextIdentifier);
    PlatformVideoFullscreenInterface* findInterface(PlaybackSessionContextIdentifier) const;
    void ensureClientForContext(PlaybackSessionContextIdentifier);
    void addClientForContext(PlaybackSessionContextIdentifier);
    void removeClientForContext(PlaybackSessionContextIdentifier);

    void hasVideoInPictureInPictureDidChange(bool);

    RetainPtr<WKLayerHostView> createLayerHostViewWithID(PlaybackSessionContextIdentifier, WebKit::LayerHostingContextID videoLayerID, const WebCore::FloatSize& initialSize, float hostingScaleFactor);

    // Messages from VideoFullscreenManager
    void setupFullscreenWithID(PlaybackSessionContextIdentifier, WebKit::LayerHostingContextID videoLayerID, const WebCore::FloatRect& screenRect, const WebCore::FloatSize& initialSize, const WebCore::FloatSize& videoDimensions, float hostingScaleFactor, WebCore::HTMLMediaElementEnums::VideoFullscreenMode, bool allowsPictureInPicture, bool standby, bool blocksReturnToFullscreenFromPictureInPicture);
    void setInlineRect(PlaybackSessionContextIdentifier, const WebCore::FloatRect& inlineRect, bool visible);
    void setHasVideoContentLayer(PlaybackSessionContextIdentifier, bool value);
    void setHasVideo(PlaybackSessionContextIdentifier, bool);
    void setVideoDimensions(PlaybackSessionContextIdentifier, const WebCore::FloatSize&);
    void enterFullscreen(PlaybackSessionContextIdentifier);
    void exitFullscreen(PlaybackSessionContextIdentifier, WebCore::FloatRect finalRect, CompletionHandler<void(bool)>&&);
    void cleanupFullscreen(PlaybackSessionContextIdentifier);
    void preparedToReturnToInline(PlaybackSessionContextIdentifier, bool visible, WebCore::FloatRect inlineRect);
    void preparedToExitFullscreen(PlaybackSessionContextIdentifier);
    void exitFullscreenWithoutAnimationToMode(PlaybackSessionContextIdentifier, WebCore::HTMLMediaElementEnums::VideoFullscreenMode);
    void setPlayerIdentifier(PlaybackSessionContextIdentifier, std::optional<WebCore::MediaPlayerIdentifier>);
    void textTrackRepresentationUpdate(PlaybackSessionContextIdentifier, ShareableBitmap::Handle&& textTrack);
    void textTrackRepresentationSetContentsScale(PlaybackSessionContextIdentifier, float scale);
    void textTrackRepresentationSetHidden(PlaybackSessionContextIdentifier, bool hidden);

    // Messages to VideoFullscreenManager
    void requestFullscreenMode(PlaybackSessionContextIdentifier, WebCore::HTMLMediaElementEnums::VideoFullscreenMode, bool finishedWithMedia = false);
    void requestUpdateInlineRect(PlaybackSessionContextIdentifier);
    void requestVideoContentLayer(PlaybackSessionContextIdentifier);
    void returnVideoContentLayer(PlaybackSessionContextIdentifier);
    void returnVideoView(PlaybackSessionContextIdentifier);
    void didSetupFullscreen(PlaybackSessionContextIdentifier);
    void willExitFullscreen(PlaybackSessionContextIdentifier);
    void didExitFullscreen(PlaybackSessionContextIdentifier);
    void failedToEnterFullscreen(PlaybackSessionContextIdentifier);
    void didEnterFullscreen(PlaybackSessionContextIdentifier, const WebCore::FloatSize&);
    void didCleanupFullscreen(PlaybackSessionContextIdentifier);
    void setVideoLayerFrame(PlaybackSessionContextIdentifier, WebCore::FloatRect);
    void setVideoLayerGravity(PlaybackSessionContextIdentifier, WebCore::MediaPlayerEnums::VideoGravity);
    void fullscreenModeChanged(PlaybackSessionContextIdentifier, WebCore::HTMLMediaElementEnums::VideoFullscreenMode);
    void fullscreenMayReturnToInline(PlaybackSessionContextIdentifier);

    void requestCloseAllMediaPresentations(PlaybackSessionContextIdentifier, bool finishedWithMedia, CompletionHandler<void()>&&);
    void callCloseCompletionHandlers();

#if !RELEASE_LOG_DISABLED
    const Logger& logger() const;
    const void* logIdentifier() const;
    const char* logClassName() const;
    WTFLogChannel& logChannel() const;
#endif

    bool m_mockVideoPresentationModeEnabled { false };
    WebCore::FloatSize m_mockPictureInPictureWindowSize { DefaultMockPictureInPictureWindowWidth, DefaultMockPictureInPictureWindowHeight };

    WebPageProxy* m_page;
    Ref<PlaybackSessionManagerProxy> m_playbackSessionManagerProxy;
    HashMap<PlaybackSessionContextIdentifier, ModelInterfaceTuple> m_contextMap;
    HashMap<PlaybackSessionContextIdentifier, int> m_clientCounts;
    Vector<CompletionHandler<void()>> m_closeCompletionHandlers;
    WeakHashSet<VideoInPictureInPictureDidChangeObserver> m_pipChangeObservers;
};

} // namespace WebKit

#endif // ENABLE(VIDEO_PRESENTATION_MODE)