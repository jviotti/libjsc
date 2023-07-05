/*
 * Copyright (C) 2020-2021 Apple Inc. All rights reserved.
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

#import "config.h"
#import "_WKAuthenticatorAttestationResponse.h"

#import "_WKAuthenticationExtensionsClientOutputs.h"
#import "_WKAuthenticatorResponseInternal.h"
#import <wtf/RetainPtr.h>

@implementation _WKAuthenticatorAttestationResponse

- (instancetype)initWithClientDataJSON:(NSData *)clientDataJSON rawId:(NSData *)rawId extensions:(RetainPtr<_WKAuthenticationExtensionsClientOutputs>&&)extensions attestationObject:(NSData *)attestationObject attachment:(_WKAuthenticatorAttachment)attachment transports:(NSArray<NSNumber *> *)transports
{
    if (!(self = [super initWithClientDataJSON:clientDataJSON rawId:rawId extensions:WTFMove(extensions) attachment:attachment]))
        return nil;

    _attestationObject = [attestationObject retain];
    _transports = [transports copy];
    return self;
}

- (instancetype)initWithClientDataJSON:(NSData *)clientDataJSON rawId:(NSData *)rawId extensionOutputsCBOR:(NSData *)extensionOutputsCBOR attestationObject:(NSData *)attestationObject attachment:(_WKAuthenticatorAttachment)attachment transports:(NSArray<NSNumber *> *)transports
{
    if (!(self = [super initWithClientDataJSON:clientDataJSON rawId:rawId extensionOutputsCBOR:WTFMove(extensionOutputsCBOR) attachment:attachment]))
        return nil;

    _attestationObject = [attestationObject retain];
    _transports = [transports copy];
    return self;
}

- (void)dealloc
{
    [_attestationObject release];
    [_transports release];
    [super dealloc];
}

@end
