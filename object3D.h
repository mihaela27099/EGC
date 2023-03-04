#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object3D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreezDrum(const std::string& name, glm::vec3 center, glm::vec3 color, bool fill= true );
    Mesh* CreezPatrat(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreezCopac(const std::string& name, glm::vec3 center, glm::vec3 cul1, glm::vec3 cul2, bool fill = true);
    Mesh* CreezMasina(const std::string& name, glm::vec3 center, glm::vec3 cul1, bool fill = true);

}