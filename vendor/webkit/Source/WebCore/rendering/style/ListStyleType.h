/*
 * Copyright (C) 2023 Apple Inc.  All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <optional>
#include <wtf/Forward.h>
#include <wtf/text/AtomString.h>
#include <wtf/text/TextStream.h>


namespace WebCore {
struct ListStyleType {
    enum class Type : uint8_t {
        CounterStyle,
        String,
        None
    };

    bool isCircle() const;
    bool isSquare() const;
    bool isDisc() const;
    bool isDisclosureClosed() const;

    bool operator==(const ListStyleType& other) const { return type == other.type && identifier == other.identifier; }

    Type type { Type::None };
    // The identifier is the string when the type is String and is the @counter-style name when the type is CounterStyle.
    AtomString identifier;
};

TextStream& operator<<(TextStream&, ListStyleType::Type);
WTF::TextStream& operator<<(WTF::TextStream&, ListStyleType);


} // namespace WebCore

namespace WTF {

template<> struct EnumTraits<WebCore::ListStyleType::Type> {
    using values = EnumValues<
        WebCore::ListStyleType::Type,
        WebCore::ListStyleType::Type::CounterStyle,
        WebCore::ListStyleType::Type::String,
        WebCore::ListStyleType::Type::None
    >;
};

} // namespace WTF
