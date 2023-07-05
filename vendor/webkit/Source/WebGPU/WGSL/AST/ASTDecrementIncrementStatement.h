/*
 * Copyright (C) 2023 Apple Inc. All rights reserved.
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

#include "ASTExpression.h"
#include "ASTStatement.h"

namespace WGSL::AST {

class DecrementIncrementStatement final : public Statement {
    WGSL_AST_BUILDER_NODE(DecrementIncrementStatement);
public:
    enum class Operation : uint8_t {
        Decrement,
        Increment,
    };

    NodeKind kind() const override;
    Expression& expression() { return m_expression; }
    Operation operation() const { return m_operation; }

private:
    DecrementIncrementStatement(SourceSpan span, Expression::Ref&& expression, Operation operation)
        : Statement(span)
        , m_expression(WTFMove(expression))
        , m_operation(operation)
    { }

    Expression::Ref m_expression;
    Operation m_operation;
};

void printInternal(PrintStream&, DecrementIncrementStatement::Operation);

} // namespace WGSL::AST

SPECIALIZE_TYPE_TRAITS_WGSL_AST(DecrementIncrementStatement)
