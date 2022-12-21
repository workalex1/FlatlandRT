/*
 *  SPDX-FileCopyrightText: 2022 Julian Amann <dev@vertexwahn.de>
 *  SPDX-License-Identifier: Apache-2.0
 */

#include "core/exception.h"

DE_VERTEXWAHN_BEGIN_NAMESPACE

Exception::Exception(std::string_view message) : error_message_(message) {
}

Exception::~Exception() {}

const char *Exception::what() const throw() {
    return error_message_.c_str();
}

DE_VERTEXWAHN_END_NAMESPACE