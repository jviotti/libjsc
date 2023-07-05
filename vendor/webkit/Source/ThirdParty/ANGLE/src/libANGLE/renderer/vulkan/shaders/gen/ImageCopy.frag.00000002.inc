// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/ImageCopy.frag.00000002.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kImageCopy_frag_00000002[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x7d,0x97,0xdb,0x6f,0x55,0x45,
    0x14,0xc6,0x67,0xce,0x39,0x6d,0xb9,0x16,0xb0,0xad,0x0a,0x69,0xa4,0xe5,0x26,0x5a,
    0x28,0xb7,0x72,0xb3,0x1c,0xa0,0x16,0x69,0x8d,0x08,0xd2,0x86,0x04,0x11,0x95,0x2a,
    0xa2,0x40,0xe0,0x05,0x5f,0x48,0x90,0x8b,0x42,0x20,0x82,0x48,0x23,0xda,0xc6,0x08,
    0xd1,0xc8,0x03,0x88,0xf4,0x45,0x50,0x68,0x34,0x04,0x8d,0x40,0xa2,0x34,0x51,0x2a,
    0xfc,0x05,0x46,0x22,0xf1,0xc2,0x03,0xe1,0xa2,0x0d,0xce,0x9a,0xfd,0x5b,0x3d,0xcb,
    0x13,0xb1,0xc9,0x64,0xf6,0x7c,0xeb,0xfe,0xcd,0x5a,0xfb,0xec,0xa6,0x53,0x23,0x8b,
    0x9c,0xf3,0xae,0x9f,0xeb,0xe3,0xe6,0x79,0x17,0xff,0x86,0xb8,0x94,0x93,0xc7,0xfe,
    0xae,0x30,0xee,0x0d,0x0b,0x9a,0x17,0x54,0x6f,0x78,0x75,0x65,0x75,0xcd,0xd4,0x89,
    0x22,0x2f,0x76,0xe9,0xa8,0x27,0xb2,0x41,0xae,0xc8,0x65,0xc2,0x2e,0x6b,0x5d,0xcb,
    0xea,0xf5,0x82,0x8f,0x09,0xeb,0x72,0x58,0x83,0x83,0x9e,0xe0,0x45,0xe2,0x23,0x3c,
    0x8d,0x89,0x3e,0xc5,0xc6,0xb9,0x46,0x57,0xe0,0xc6,0x25,0xe1,0xdc,0x48,0x76,0xc5,
    0x3c,0x58,0x1f,0x83,0xa5,0xc0,0x06,0x1b,0x2c,0x0d,0x56,0x6a,0xb0,0x0c,0xd8,0xfd,
    0x06,0x2b,0x00,0x2b,0x37,0x58,0x21,0x58,0x85,0xc1,0x8a,0xc0,0x46,0x19,0xac,0x0f,
    0xd8,0x58,0x83,0xf5,0x05,0x1b,0x67,0xb0,0x7e,0x60,0x13,0x0d,0xd6,0x1f,0xac,0xc6,
    0x60,0x03,0xc0,0x66,0x18,0x6c,0x20,0xd8,0xac,0xc8,0x53,0xba,0xb7,0x5e,0xe1,0x6c,
    0x59,0xd8,0x47,0xc0,0x8f,0x9e,0x2b,0xcd,0x59,0x78,0x7e,0x80,0x73,0x49,0xb0,0x4a,
    0x45,0x79,0x3a,0x72,0x23,0xcf,0xf7,0x86,0xa7,0x42,0xea,0xac,0x0a,0xfa,0x85,0xc4,
    0x2b,0xaf,0x7e,0xb2,0xb6,0x34,0x68,0x14,0x1b,0xbc,0x24,0xac,0xa6,0x93,0x0b,0xeb,
    0xf4,0x2c,0x1c,0x2e,0x59,0xf2,0xd3,0x6c,0x3d,0x0f,0x0b,0x2b,0xdb,0x6f,0xe7,0x1c,
    0x3d,0x0b,0x9f,0x1d,0x0d,0x2d,0xd9,0xb2,0x70,0xae,0x20,0x86,0xdc,0xdd,0x7d,0xe1,
    0x5c,0xc9,0x39,0xc5,0x79,0x14,0x9c,0x67,0x22,0x9e,0x71,0xa3,0xd1,0x15,0xbc,0x96,
    0xf3,0x18,0x63,0xff,0x20,0xfa,0x62,0x2f,0xfe,0xab,0xf0,0xe7,0x62,0xbd,0x83,0x23,
    0x47,0x95,0xac,0x8a,0xde,0xfa,0xfe,0x7f,0x55,0xf4,0xee,0x19,0x37,0x9e,0x7b,0x1c,
    0x47,0x7c,0x39,0x57,0x83,0x55,0x51,0xcf,0x04,0xf2,0x11,0xfd,0x89,0xc8,0x2a,0x8d,
    0x7c,0x9a,0xa9,0x67,0x7a,0xaf,0x6d,0x22,0x97,0xfd,0x11,0xf2,0x55,0xfd,0x7a,0x7a,
    0x51,0xe5,0x8f,0xe3,0x5f,0xe5,0x0b,0xb9,0x9b,0xa1,0xc1,0xd3,0x52,0xea,0x67,0x24,
    0x7b,0xff,0xf4,0x2c,0x31,0x9f,0xe6,0x79,0x29,0x35,0xc8,0x79,0x59,0x5e,0xcc,0xe5,
    0x79,0xe7,0x16,0x38,0x15,0xfb,0x17,0xc8,0xb9,0xc2,0xc8,0x57,0xd1,0xcb,0x7a,0xde,
    0x44,0x1e,0x72,0x27,0x3b,0x78,0x4e,0x1b,0xf9,0x1e,0xe6,0x46,0x7b,0x62,0xbf,0x89,
    0x27,0xe7,0x8f,0xe2,0x69,0x4b,0xbd,0xd8,0x1f,0x82,0x9f,0x8c,0xb1,0x3f,0xc2,0x8c,
    0xe9,0xf9,0x44,0xde,0x1d,0x9c,0x61,0x66,0x24,0xdf,0x4b,0xc4,0x3e,0x44,0xbd,0x97,
    0x78,0xcf,0xa4,0xe3,0x5d,0x14,0xc4,0xba,0x32,0xc4,0x17,0xec,0x66,0x40,0x84,0xef,
    0x2c,0xfd,0x37,0x96,0x1e,0x5b,0x14,0x32,0x96,0xfe,0x7a,0x08,0x6c,0xac,0xe1,0x76,
    0x3d,0xbd,0xfb,0x30,0xf2,0xba,0xe0,0x41,0xee,0x7e,0x12,0xfd,0x31,0x01,0x7f,0xa2,
    0x33,0x19,0xfc,0xf5,0xa0,0x23,0xe7,0x29,0xd8,0x4d,0xc6,0x6e,0x3a,0x73,0x5e,0x4d,
    0xaf,0x64,0xb9,0xf7,0x99,0xe0,0x47,0x83,0x4e,0x71,0xac,0x25,0xc1,0xa4,0x5f,0x6e,
    0x84,0xcc,0xb3,0xe4,0x73,0x3b,0xe8,0xd7,0xf2,0x5e,0xc8,0x52,0x8f,0x3c,0x2f,0x0e,
    0x76,0xc2,0xcd,0x5c,0x62,0xca,0xdf,0x66,0xf8,0xaa,0x03,0x6f,0x0a,0xec,0x4b,0x4e,
    0x43,0x7d,0x82,0xa9,0xde,0xad,0xe0,0x43,0x7d,0xc9,0x7e,0x3d,0x70,0x11,0x6b,0xf1,
    0x89,0x4e,0x01,0x36,0xb3,0x4c,0x0d,0xf3,0xa8,0xa1,0xde,0xd4,0xf0,0x18,0xb8,0xd6,
    0x30,0x1f,0x4c,0x6b,0x68,0x34,0x35,0xcc,0x8f,0xef,0x2a,0x17,0x31,0x89,0xdb,0x60,
    0x6a,0x78,0x82,0xd8,0xde,0xd4,0xb0,0x00,0x5c,0x6b,0x28,0xf7,0x09,0xa6,0x7a,0x52,
    0x83,0xfa,0x6a,0x34,0x35,0x4c,0xf1,0x89,0x4e,0x16,0x9b,0x06,0x53,0xc3,0x22,0x6a,
    0x58,0x68,0x6a,0x78,0x0a,0x5c,0x6b,0x58,0x0c,0xa6,0x35,0x34,0x9b,0x1a,0x16,0xc7,
    0x7c,0x5c,0xc4,0x24,0x6e,0x13,0x7d,0x24,0x71,0x97,0x10,0x7b,0x8a,0xcf,0xcd,0xa7,
    0xe4,0xa8,0xba,0xcd,0x26,0xc7,0x1a,0xf4,0x1a,0xb1,0x6b,0x22,0x1f,0x99,0xe1,0x67,
    0x98,0x5f,0xed,0xb9,0x67,0xc9,0x79,0xb9,0xe9,0xb9,0xe7,0xc0,0xb7,0xd2,0x73,0x2b,
    0xc0,0x6a,0x7c,0x62,0x27,0x33,0xfd,0x22,0x76,0x2d,0xd8,0x09,0xa7,0x2b,0xc1,0x9f,
    0x0f,0x79,0xc8,0x2c,0xbc,0x44,0xbc,0x15,0xbc,0x0f,0x56,0x1a,0xae,0x5e,0xc6,0x7e,
    0x95,0xe1,0xea,0x15,0x70,0xe5,0x6a,0x35,0x98,0x72,0xb5,0xd6,0x70,0x25,0xb2,0x35,
    0x61,0xad,0xa5,0xfe,0x35,0xdc,0x77,0x61,0x9c,0xaf,0x24,0xb6,0xc3,0xee,0x1a,0xcf,
    0x7f,0x85,0x67,0xf1,0xf5,0x33,0x36,0xb2,0x7f,0x49,0xac,0x5f,0xb0,0x1b,0x88,0xcd,
    0x9f,0x26,0x96,0xc8,0xae,0x84,0x75,0x15,0xbb,0xab,0xf1,0x7d,0x51,0x14,0x63,0xfd,
    0xc6,0x4c,0x0f,0xc3,0x5e,0x7e,0xcf,0x76,0x90,0xc7,0xef,0xc8,0x45,0xf6,0x06,0xd8,
    0x1f,0xe0,0xe5,0xdc,0xdf,0x35,0x7c,0x5e,0x31,0x76,0xbf,0xe2,0xab,0x24,0x4f,0x47,
    0x72,0xba,0x13,0xa2,0xdd,0x04,0xbb,0x4e,0x0e,0x53,0x7d,0xe2,0xf7,0x2a,0xb6,0x57,
    0xe8,0x6b,0xb9,0x83,0xe1,0x3e,0x91,0x2b,0x1f,0xca,0xd1,0x06,0x38,0xf2,0xd4,0x9b,
    0xf6,0xff,0xe6,0xe8,0x06,0x31,0x6f,0x18,0x8e,0x6e,0x61,0xa7,0x1c,0xa5,0x7c,0x8e,
    0xa3,0x5b,0x71,0x77,0xae,0x07,0xbb,0x1e,0xc3,0xd1,0x1d,0xc3,0xd1,0x86,0x3c,0x8e,
    0x44,0x70,0x27,0x8f,0x23,0xef,0x13,0x5c,0x39,0x92,0xdc,0xc4,0xe7,0x6d,0x63,0xf7,
    0x37,0xbe,0x4a,0xf2,0x74,0x52,0x3e,0xc7,0x91,0x60,0xca,0xd1,0x74,0x9f,0xf8,0xed,
    0xc1,0xf6,0xb6,0xe1,0x68,0x84,0x4f,0xe4,0xc3,0x99,0x2d,0xe5,0x68,0x23,0x1c,0xa5,
    0xa8,0xb7,0x2c,0x8f,0xa3,0xbe,0xc4,0x94,0x5d,0x39,0xea,0xef,0x13,0x3b,0xe5,0xa8,
    0xd4,0x70,0x24,0xb2,0x01,0x61,0x0d,0xc2,0x4e,0x76,0xe5,0x68,0x88,0xcf,0x71,0xb4,
    0x31,0x8f,0xa3,0x7b,0x7c,0x22,0xb7,0x1c,0x95,0xf8,0x04,0x57,0x8e,0xca,0xf0,0x29,
    0xfe,0xd5,0xae,0x98,0x5c,0x4a,0xf2,0x74,0x4a,0x0d,0x47,0x65,0x86,0xa3,0x99,0x3e,
    0xf1,0x2b,0x79,0x15,0x93,0xab,0x72,0x34,0xda,0x27,0x72,0xe1,0x2a,0x85,0x3f,0x9d,
    0xbd,0xb5,0xf4,0x62,0xfc,0xce,0xa2,0xd7,0x9a,0xb1,0x29,0xf3,0xb9,0x99,0x7f,0x8d,
    0x99,0xdf,0x64,0x66,0x7e,0x33,0xb8,0xce,0xfc,0x16,0x30,0x9d,0xf9,0x6d,0x66,0x0e,
    0xb7,0xc4,0x77,0x92,0x73,0xbb,0x89,0xbb,0xdb,0xbc,0x4f,0xde,0xc2,0xf7,0x1e,0xe3,
    0x7b,0x2f,0xb8,0xfa,0x7e,0x1b,0x4c,0x7d,0xb7,0x1a,0xdf,0x22,0xdb,0x17,0x56,0x2b,
    0xbe,0xf7,0x99,0x3e,0x78,0x87,0xba,0xe4,0xf7,0xbe,0x13,0x5f,0xef,0x82,0xef,0x87,
    0x0b,0xb5,0x6b,0x85,0x0b,0xd1,0x79,0x8f,0x98,0xbb,0xd1,0xdf,0x47,0xdc,0x76,0x13,
    0x57,0x74,0xda,0xc2,0x6a,0xc7,0xbe,0xcd,0xc4,0x7d,0xdf,0xc4,0x5d,0x14,0xbe,0x60,
    0xe4,0xdb,0xe8,0x03,0xb0,0x5a,0x9f,0xfb,0x9e,0x48,0xc5,0xdf,0x94,0xc2,0x28,0x3f,
    0x80,0x9d,0xae,0x5d,0xc1,0x97,0xe0,0x07,0xb1,0x3d,0x10,0x7d,0xf5,0x8d,0x77,0xf5,
    0x21,0xbe,0x0e,0xf2,0x4d,0x53,0x60,0xbe,0xbd,0xa4,0x26,0xcd,0xa9,0xdd,0xdc,0xef,
    0x6c,0x62,0xb7,0x62,0xdf,0x86,0xee,0x36,0x74,0xb7,0x9a,0xfc,0xb7,0xff,0x47,0xfe,
    0x3b,0xef,0x92,0xff,0x5e,0xf2,0xdc,0x85,0xce,0x76,0x93,0xe7,0x9b,0xd8,0xec,0xba,
    0x4b,0x9e,0x1a,0x7b,0x9b,0xc9,0x33,0xeb,0x93,0x5c,0xdb,0xb1,0xdf,0x4a,0x0c,0x91,
    0x7d,0x8c,0x5c,0xbe,0x1b,0xd7,0xf1,0xcd,0x78,0x18,0x5c,0xfb,0xe9,0x13,0xfa,0xe9,
    0x88,0xe9,0xa7,0xa3,0xe0,0xda,0x4f,0x9f,0x82,0x69,0x3f,0x75,0x98,0x7b,0x15,0xd9,
    0xb1,0xb0,0x8e,0x93,0xdb,0x71,0xe3,0xfb,0x73,0x7c,0x9f,0x30,0xbe,0xbf,0x00,0x57,
    0xdf,0x27,0xc1,0xd4,0x77,0xa7,0xf1,0x2d,0xb2,0x53,0x61,0x9d,0xc6,0xf7,0x69,0x97,
    0xfb,0x5d,0xfe,0x1a,0xdf,0x67,0xcc,0xef,0xf2,0x37,0xe0,0xe7,0xf8,0x1e,0xfa,0x16,
    0xac,0xc5,0xc4,0x3b,0x0b,0xbe,0x9c,0x78,0xe7,0x4d,0xbc,0xb3,0xd1,0xd6,0x45,0x4c,
    0xe2,0x9d,0xe3,0xdd,0x29,0xbc,0x8d,0xf7,0x49,0x8e,0x87,0x5d,0xee,0xbb,0x49,0xf5,
    0xce,0x73,0x1f,0xa2,0x37,0xc7,0x27,0x3a,0xa7,0xb1,0x39,0x67,0xf2,0xf9,0x8e,0x7c,
    0xa6,0x99,0x7c,0xbe,0x07,0xd7,0x7c,0xba,0x4c,0x3e,0x22,0xbb,0x10,0x56,0x17,0x71,
    0x2e,0x98,0x7c,0x26,0x90,0xcf,0x1c,0xf3,0x9e,0x52,0xbd,0x2e,0x93,0xcf,0x5c,0x9f,
    0xe8,0x9c,0xc7,0xe6,0x82,0xc9,0xe7,0x07,0xf2,0x39,0x62,0xf2,0xf9,0x11,0x5c,0xf3,
    0xe9,0x36,0xf9,0x88,0xec,0x62,0x58,0xdd,0xc4,0xb9,0x68,0xf2,0x99,0xe4,0x93,0xff,
    0xc1,0xe6,0xfa,0x5c,0xbf,0xaa,0x5e,0xb7,0xc9,0xa7,0xde,0x27,0x3a,0x5d,0xd8,0x5c,
    0x44,0xb7,0x13,0xdd,0x53,0xcc,0x95,0xf4,0xca,0x57,0xf0,0x9d,0x36,0x71,0xaa,0x7c,
    0x0e,0x77,0x79,0xb6,0x9d,0x26,0xce,0xa3,0x3e,0x89,0xd5,0x8d,0xcd,0x29,0x74,0x3b,
    0xd0,0x3d,0xc6,0xdc,0x89,0xee,0x67,0xf8,0x3b,0xcc,0xdc,0x15,0x31,0xab,0xe9,0x3c,
    0x9b,0x0e,0xe3,0xbf,0xce,0x27,0x31,0x3a,0xb1,0x17,0x7f,0xb3,0x83,0xc5,0x65,0x64,
    0x3d,0xa1,0x4b,0x66,0x84,0xf5,0x0f,0xb7,0x23,0xca,0x37,0x14,0x12,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_EXT_samplerless_texture_functions : require
//
// layout(set = 0, binding = 0)uniform texture2D src;
// layout(location = 0)out uvec4 dst;
//
// layout(push_constant)uniform PushConstants {
//
//     ivec2 srcOffset;
//     ivec2 dstOffset;
//     int srcMip;
//     int srcLayer;
//
//     bool flipX;
//     bool flipY;
//
//     bool premultiplyAlpha;
//     bool unmultiplyAlpha;
//
//     bool dstHasLuminance;
//     bool dstIsAlpha;
//
//     bool srcIsSRGB;
//     bool dstIsSRGB;
//
//     int dstDefaultChannelsMask;
//     bool rotateXY;
// } params;
//
// float linearToSRGB(float linear)
// {
//
//     if(linear <= 0.0031308)
//     {
//         return linear * 12.92;
//     }
//     else
//     {
//         return pow(linear,(1.0f / 2.4f))* 1.055f - 0.055f;
//     }
// }
//
// void main()
// {
//     ivec2 dstSubImageCoords = ivec2(gl_FragCoord . xy)- params . dstOffset;
//
//     ivec2 srcSubImageCoords = dstSubImageCoords;
//
//     if(params . flipX)
//     {
//         srcSubImageCoords . x = - srcSubImageCoords . x;
//     }
//     if(params . flipY)
//     {
//         srcSubImageCoords . y = - srcSubImageCoords . y;
//     }
//     if(params . rotateXY)
//     {
//         srcSubImageCoords . xy = srcSubImageCoords . yx;
//     }
//
//           vec4 srcValue = texelFetch(src, params . srcOffset + srcSubImageCoords, params . srcMip);
//
//     if(params . srcIsSRGB)
//     {
//
//         srcValue . r = linearToSRGB(srcValue . r);
//         srcValue . g = linearToSRGB(srcValue . g);
//         srcValue . b = linearToSRGB(srcValue . b);
//     }
//
//     if(params . premultiplyAlpha)
//     {
//         srcValue . rgb *= srcValue . a;
//     }
//     else if(params . unmultiplyAlpha && srcValue . a > 0)
//     {
//         srcValue . rgb /= srcValue . a;
//     }
//
//     srcValue *= 255.0;
//
//            uvec4 dstValue = uvec4(srcValue);
//
//     if(params . dstHasLuminance)
//     {
//         dstValue . rg = dstValue . ra;
//     }
//     else if(params . dstIsAlpha)
//     {
//         dstValue . r = dstValue . a;
//     }
//     else
//     {
//         int defaultChannelsMask = params . dstDefaultChannelsMask;
//         if((defaultChannelsMask & 2)!= 0)
//         {
//             dstValue . g = 0;
//         }
//         if((defaultChannelsMask & 4)!= 0)
//         {
//             dstValue . b = 0;
//         }
//         if((defaultChannelsMask & 8)!= 0)
//         {
//             dstValue . a = 1;
//         }
//     }
//
//     dst = dstValue;
// }