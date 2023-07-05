// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from egl.xml and egl_angle_ext.xml.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// egl_ext_stubs_autogen.h: Stubs for EXT extension entry points.

#ifndef LIBGLESV2_EGL_EXT_STUBS_AUTOGEN_H_
#define LIBGLESV2_EGL_EXT_STUBS_AUTOGEN_H_

#include <EGL/egl.h>
#include <EGL/eglext.h>

#include "common/PackedEGLEnums_autogen.h"
#include "common/PackedEnums.h"

namespace gl
{
class Context;
}  // namespace gl

namespace egl
{
class AttributeMap;
class Device;
class Display;
class Image;
class Stream;
class Surface;
class Sync;
class Thread;
struct Config;

EGLint ClientWaitSyncKHR(Thread *thread,
                         egl::Display *dpyPacked,
                         egl::SyncID syncPacked,
                         EGLint flags,
                         EGLTimeKHR timeout);
EGLImageKHR CreateImageKHR(Thread *thread,
                           egl::Display *dpyPacked,
                           gl::ContextID ctxPacked,
                           EGLenum target,
                           EGLClientBuffer buffer,
                           const AttributeMap &attrib_listPacked);
EGLClientBuffer CreateNativeClientBufferANDROID(Thread *thread,
                                                const AttributeMap &attrib_listPacked);
EGLSurface CreatePlatformPixmapSurfaceEXT(Thread *thread,
                                          egl::Display *dpyPacked,
                                          egl::Config *configPacked,
                                          void *native_pixmap,
                                          const AttributeMap &attrib_listPacked);
EGLSurface CreatePlatformWindowSurfaceEXT(Thread *thread,
                                          egl::Display *dpyPacked,
                                          egl::Config *configPacked,
                                          void *native_window,
                                          const AttributeMap &attrib_listPacked);
EGLStreamKHR CreateStreamKHR(Thread *thread,
                             egl::Display *dpyPacked,
                             const AttributeMap &attrib_listPacked);
EGLSyncKHR CreateSyncKHR(Thread *thread,
                         egl::Display *dpyPacked,
                         EGLenum type,
                         const AttributeMap &attrib_listPacked);
EGLint DebugMessageControlKHR(Thread *thread,
                              EGLDEBUGPROCKHR callback,
                              const AttributeMap &attrib_listPacked);
EGLBoolean DestroyImageKHR(Thread *thread, egl::Display *dpyPacked, ImageID imagePacked);
EGLBoolean DestroyStreamKHR(Thread *thread, egl::Display *dpyPacked, egl::Stream *streamPacked);
EGLBoolean DestroySyncKHR(Thread *thread, egl::Display *dpyPacked, egl::SyncID syncPacked);
EGLint DupNativeFenceFDANDROID(Thread *thread, egl::Display *dpyPacked, egl::SyncID syncPacked);
EGLBoolean GetMscRateANGLE(Thread *thread,
                           egl::Display *dpyPacked,
                           SurfaceID surfacePacked,
                           EGLint *numerator,
                           EGLint *denominator);
EGLClientBuffer GetNativeClientBufferANDROID(Thread *thread, const struct AHardwareBuffer *buffer);
EGLDisplay GetPlatformDisplayEXT(Thread *thread,
                                 EGLenum platform,
                                 void *native_display,
                                 const AttributeMap &attrib_listPacked);
EGLBoolean GetSyncAttribKHR(Thread *thread,
                            egl::Display *dpyPacked,
                            egl::SyncID syncPacked,
                            EGLint attribute,
                            EGLint *value);
EGLint LabelObjectKHR(Thread *thread,
                      egl::Display *displayPacked,
                      ObjectType objectTypePacked,
                      EGLObjectKHR object,
                      EGLLabelKHR label);
EGLBoolean LockSurfaceKHR(Thread *thread,
                          egl::Display *dpyPacked,
                          SurfaceID surfacePacked,
                          const AttributeMap &attrib_listPacked);
EGLBoolean PostSubBufferNV(Thread *thread,
                           egl::Display *dpyPacked,
                           SurfaceID surfacePacked,
                           EGLint x,
                           EGLint y,
                           EGLint width,
                           EGLint height);
EGLBoolean PresentationTimeANDROID(Thread *thread,
                                   egl::Display *dpyPacked,
                                   SurfaceID surfacePacked,
                                   EGLnsecsANDROID time);
EGLBoolean GetCompositorTimingSupportedANDROID(Thread *thread,
                                               egl::Display *dpyPacked,
                                               SurfaceID surfacePacked,
                                               CompositorTiming namePacked);
EGLBoolean GetCompositorTimingANDROID(Thread *thread,
                                      egl::Display *dpyPacked,
                                      SurfaceID surfacePacked,
                                      EGLint numTimestamps,
                                      const EGLint *names,
                                      EGLnsecsANDROID *values);
EGLBoolean GetNextFrameIdANDROID(Thread *thread,
                                 egl::Display *dpyPacked,
                                 SurfaceID surfacePacked,
                                 EGLuint64KHR *frameId);
EGLBoolean GetFrameTimestampSupportedANDROID(Thread *thread,
                                             egl::Display *dpyPacked,
                                             SurfaceID surfacePacked,
                                             Timestamp timestampPacked);
EGLBoolean GetFrameTimestampsANDROID(Thread *thread,
                                     egl::Display *dpyPacked,
                                     SurfaceID surfacePacked,
                                     EGLuint64KHR frameId,
                                     EGLint numTimestamps,
                                     const EGLint *timestamps,
                                     EGLnsecsANDROID *values);
EGLBoolean QueryDebugKHR(Thread *thread, EGLint attribute, EGLAttrib *value);
EGLBoolean QueryDeviceAttribEXT(Thread *thread,
                                egl::Device *devicePacked,
                                EGLint attribute,
                                EGLAttrib *value);
const char *QueryDeviceStringEXT(Thread *thread, egl::Device *devicePacked, EGLint name);
EGLBoolean QueryDisplayAttribEXT(Thread *thread,
                                 egl::Display *dpyPacked,
                                 EGLint attribute,
                                 EGLAttrib *value);
EGLBoolean QueryDmaBufFormatsEXT(Thread *thread,
                                 egl::Display *dpyPacked,
                                 EGLint max_formats,
                                 EGLint *formats,
                                 EGLint *num_formats);
EGLBoolean QueryDmaBufModifiersEXT(Thread *thread,
                                   egl::Display *dpyPacked,
                                   EGLint format,
                                   EGLint max_modifiers,
                                   EGLuint64KHR *modifiers,
                                   EGLBoolean *external_only,
                                   EGLint *num_modifiers);
EGLBoolean QueryStreamKHR(Thread *thread,
                          egl::Display *dpyPacked,
                          egl::Stream *streamPacked,
                          EGLenum attribute,
                          EGLint *value);
EGLBoolean QueryStreamu64KHR(Thread *thread,
                             egl::Display *dpyPacked,
                             egl::Stream *streamPacked,
                             EGLenum attribute,
                             EGLuint64KHR *value);
EGLBoolean QuerySurface64KHR(Thread *thread,
                             egl::Display *dpyPacked,
                             SurfaceID surfacePacked,
                             EGLint attribute,
                             EGLAttribKHR *value);
EGLBoolean QuerySurfacePointerANGLE(Thread *thread,
                                    egl::Display *dpyPacked,
                                    SurfaceID surfacePacked,
                                    EGLint attribute,
                                    void **value);
void SetBlobCacheFuncsANDROID(Thread *thread,
                              egl::Display *dpyPacked,
                              EGLSetBlobFuncANDROID set,
                              EGLGetBlobFuncANDROID get);
EGLBoolean SetDamageRegionKHR(Thread *thread,
                              egl::Display *dpyPacked,
                              SurfaceID surfacePacked,
                              EGLint *rects,
                              EGLint n_rects);
EGLBoolean SignalSyncKHR(Thread *thread,
                         egl::Display *dpyPacked,
                         egl::SyncID syncPacked,
                         EGLenum mode);
EGLBoolean StreamAttribKHR(Thread *thread,
                           egl::Display *dpyPacked,
                           egl::Stream *streamPacked,
                           EGLenum attribute,
                           EGLint value);
EGLBoolean StreamConsumerAcquireKHR(Thread *thread,
                                    egl::Display *dpyPacked,
                                    egl::Stream *streamPacked);
EGLBoolean StreamConsumerGLTextureExternalKHR(Thread *thread,
                                              egl::Display *dpyPacked,
                                              egl::Stream *streamPacked);
EGLBoolean StreamConsumerGLTextureExternalAttribsNV(Thread *thread,
                                                    egl::Display *dpyPacked,
                                                    egl::Stream *streamPacked,
                                                    const AttributeMap &attrib_listPacked);
EGLBoolean StreamConsumerReleaseKHR(Thread *thread,
                                    egl::Display *dpyPacked,
                                    egl::Stream *streamPacked);
EGLBoolean SwapBuffersWithDamageKHR(Thread *thread,
                                    egl::Display *dpyPacked,
                                    SurfaceID surfacePacked,
                                    const EGLint *rects,
                                    EGLint n_rects);
EGLBoolean UnlockSurfaceKHR(Thread *thread, egl::Display *dpyPacked, SurfaceID surfacePacked);
EGLint WaitSyncKHR(Thread *thread, egl::Display *dpyPacked, egl::SyncID syncPacked, EGLint flags);
EGLDeviceEXT CreateDeviceANGLE(Thread *thread,
                               EGLint device_type,
                               void *native_device,
                               const EGLAttrib *attrib_list);
EGLBoolean ReleaseDeviceANGLE(Thread *thread, egl::Device *devicePacked);
EGLBoolean CreateStreamProducerD3DTextureANGLE(Thread *thread,
                                               egl::Display *dpyPacked,
                                               egl::Stream *streamPacked,
                                               const AttributeMap &attrib_listPacked);
EGLBoolean StreamPostD3DTextureANGLE(Thread *thread,
                                     egl::Display *dpyPacked,
                                     egl::Stream *streamPacked,
                                     void *texture,
                                     const AttributeMap &attrib_listPacked);
EGLBoolean GetSyncValuesCHROMIUM(Thread *thread,
                                 egl::Display *dpyPacked,
                                 SurfaceID surfacePacked,
                                 EGLuint64KHR *ust,
                                 EGLuint64KHR *msc,
                                 EGLuint64KHR *sbc);
EGLint ProgramCacheGetAttribANGLE(Thread *thread, egl::Display *dpyPacked, EGLenum attrib);
void ProgramCacheQueryANGLE(Thread *thread,
                            egl::Display *dpyPacked,
                            EGLint index,
                            void *key,
                            EGLint *keysize,
                            void *binary,
                            EGLint *binarysize);
void ProgramCachePopulateANGLE(Thread *thread,
                               egl::Display *dpyPacked,
                               const void *key,
                               EGLint keysize,
                               const void *binary,
                               EGLint binarysize);
EGLint ProgramCacheResizeANGLE(Thread *thread, egl::Display *dpyPacked, EGLint limit, EGLint mode);
const char *QueryStringiANGLE(Thread *thread, egl::Display *dpyPacked, EGLint name, EGLint index);
EGLBoolean SwapBuffersWithFrameTokenANGLE(Thread *thread,
                                          egl::Display *dpyPacked,
                                          SurfaceID surfacePacked,
                                          EGLFrameTokenANGLE frametoken);
EGLBoolean PrepareSwapBuffersANGLE(EGLDisplay dpy, EGLSurface surface);
void ReleaseHighPowerGPUANGLE(Thread *thread, egl::Display *dpyPacked, gl::ContextID ctxPacked);
void ReacquireHighPowerGPUANGLE(Thread *thread, egl::Display *dpyPacked, gl::ContextID ctxPacked);
void HandleGPUSwitchANGLE(Thread *thread, egl::Display *dpyPacked);
void ForceGPUSwitchANGLE(Thread *thread,
                         egl::Display *dpyPacked,
                         EGLint gpuIDHigh,
                         EGLint gpuIDLow);
EGLBoolean QueryDisplayAttribANGLE(Thread *thread,
                                   egl::Display *dpyPacked,
                                   EGLint attribute,
                                   EGLAttrib *value);
EGLBoolean ExportVkImageANGLE(Thread *thread,
                              egl::Display *dpyPacked,
                              ImageID imagePacked,
                              void *vk_image,
                              void *vk_image_create_info);
void *CopyMetalSharedEventANGLE(Thread *thread, egl::Display *dpyPacked, egl::SyncID syncPacked);
void WaitUntilWorkScheduledANGLE(Thread *thread, egl::Display *dpyPacked);
}  // namespace egl
#endif  // LIBGLESV2_EGL_EXT_STUBS_AUTOGEN_H_