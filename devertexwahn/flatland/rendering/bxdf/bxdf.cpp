/*
 *  SPDX-FileCopyrightText: 2022 Julian Amann <dev@vertexwahn.de>
 *  SPDX-License-Identifier: Apache-2.0
 */

#include "flatland/rendering/bxdf/bxdf.h"

DE_VERTEXWAHN_BEGIN_NAMESPACE

BxDF::BxDF(const PropertySet &ps) {
    refraction_index_ = ps.get_property<float>("refraction_index", 1.f);

    std::string interface_interaction = ps.get_property<std::string>("interface_interaction",
                                                                     "specular_transmission");

    if (interface_interaction == "specular_transmission") {
        interface_interaction_ = InterfaceInteraction::SpecularTransmission;
    } else if (interface_interaction == "mirror_reflection") {
        interface_interaction_ = InterfaceInteraction::MirrorReflection;
    } else {
        interface_interaction_ = InterfaceInteraction::SpecularTransmission;
    }
}

float BxDF::refraction_index() const {
    return refraction_index_;
}

InterfaceInteraction BxDF::interface_interaction_type() const {
    return interface_interaction_;
}

DE_VERTEXWAHN_END_NAMESPACE
