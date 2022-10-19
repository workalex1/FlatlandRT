/*
 *  SPDX-FileCopyrightText: 2022 Julian Amann <dev@vertexwahn.de>
 *  SPDX-License-Identifier: Apache-2.0
 */

#include "core/object_factory.h"

#include "fmt/core.h"

DE_VERTEXWAHN_BEGIN_NAMESPACE

const char *ObjectFactoryException::what() const throw() {
    return error_message_.c_str();
}

ObjectFactoryClassDoesNotExist::ObjectFactoryClassDoesNotExist(std::string_view class_name) {
    error_message_ = fmt::format("Class with name '{}' does not exist registered",
                                 class_name);
}

ObjectFactoryClassAlreadyRegisteredException::ObjectFactoryClassAlreadyRegisteredException(
        std::string_view class_name) {
    error_message_ = fmt::format("Class with name '{}' was already registered",
                                 class_name);
}

DE_VERTEXWAHN_END_NAMESPACE