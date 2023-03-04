#include "object3D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object3D::CreezDrum(
    const std::string& name,
    glm::vec3 centru,
    glm::vec3 culoare,
    bool fill)
{
    glm::vec3 center = centru;
    std::vector<VertexFormat> puncteDrum =
    {
        VertexFormat(center + glm::vec3(-33.97,0.5,2.6),culoare),
        VertexFormat(center + glm::vec3(-32.44,0.5,7.28),culoare),
        VertexFormat(center + glm::vec3(-24.99,0.5,11.97),culoare),
        VertexFormat(center + glm::vec3(-18.87,0.5,12.83),culoare),
        VertexFormat(center + glm::vec3(-12.18,0.5,11.3),culoare),
        VertexFormat(center + glm::vec3(-7.97,0.5,9.2),culoare),
        VertexFormat(center + glm::vec3(-3.38,0.5,7.47),culoare),
        VertexFormat(center + glm::vec3(0.54,0.5,6.9),culoare),
        VertexFormat(center + glm::vec3(5.13,0.5,8.24),culoare),
        VertexFormat(center + glm::vec3(10.67,0.5,9.96),culoare),
        VertexFormat(center + glm::vec3(15,0.5,10),culoare),
        VertexFormat(center + glm::vec3(18.22,0.5,10.25),culoare),
        VertexFormat(center + glm::vec3(21.76,0.5,9),culoare),
        VertexFormat(center + glm::vec3(24.91,0.5,6.14),culoare),
        VertexFormat(center + glm::vec3(26.83,0.5,0.97),culoare),
        VertexFormat(center + glm::vec3(28.26,0.5,-4.57),culoare),
        VertexFormat(center + glm::vec3(26.25,0.5,-7.72),culoare),
        VertexFormat(center + glm::vec3(20.9,0.5,-10.4),culoare),
        VertexFormat(center + glm::vec3(16.88,0.5,-11.84),culoare),
        VertexFormat(center + glm::vec3(9.05,0.5,-14.13),culoare),
        VertexFormat(center + glm::vec3(3.41,0.5,-13.94),culoare),
        VertexFormat(center + glm::vec3(0,0.5,-12.41),culoare),
        VertexFormat(center + glm::vec3(-2.43,0.5,-11.07),culoare),
        VertexFormat(center + glm::vec3(-6.06,0.5,-9.73),culoare),
        VertexFormat(center + glm::vec3(-11.6,0.5,-8.97),culoare),
        VertexFormat(center + glm::vec3(-15,0.5,-10),culoare),
        VertexFormat(center + glm::vec3(-19.25,0.5,-10.4),culoare),
        VertexFormat(center + glm::vec3(-23.26,0.5,-10.69),culoare),
        VertexFormat(center + glm::vec3(-29,0.5,-10.69),culoare),
        VertexFormat(center + glm::vec3(-31.49,0.5,-9.16),culoare),
        VertexFormat(center + glm::vec3(-33.68,0.5,-6.86),culoare),
        VertexFormat(center + glm::vec3(-36.27,0.5,-4.38),culoare),
        VertexFormat(center + glm::vec3(-37.03,0.5,-1.32),culoare)
    };
    glm::vec3 Up = glm::vec3(0, 1, 0);
    std::vector<VertexFormat> vertices;
    for (int i = 0; i < 32; i++)
    {
        glm::vec3 D = puncteDrum[i + 1].position - puncteDrum[i].position;
        glm::vec3 P = normalize(cross(D, Up));
        glm::vec3 R = puncteDrum[i].position + (4.0f * P);
        glm::vec3 A = puncteDrum[i].position - (4.0f * P);
        vertices.push_back(VertexFormat(R, culoare));
        vertices.push_back(VertexFormat(A, culoare));
    }
    Mesh* drum = new Mesh(name);
    std::vector<unsigned int> indices;
    for (int i = 0; i < 62; i++) {
        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }
    indices.push_back(63);
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(63);
    indices.push_back(62);
    indices.push_back(0);

    drum->InitFromData(vertices, indices);
    return drum;
}

Mesh* object3D::CreezPatrat(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner+glm::vec3(-5000,0.1,1000),color),
        VertexFormat(corner+glm::vec3(-4000,0.1,-5000),color),
        VertexFormat(corner+glm::vec3(4000,0.1,-5000),color),
        VertexFormat(corner+glm::vec3(5000,0.1,5300),color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object3D::CreezCopac(
    const std::string& name,
    glm::vec3 loc,
    glm::vec3 cul1,
    glm::vec3 cul2,
    bool fill
)
{
    glm::vec3 locPom = loc;
    std::vector<VertexFormat> vertices = {
        VertexFormat(loc + glm::vec3(0.300,0.1,0.300),cul1),
        VertexFormat(loc + glm::vec3(0.300,0.1,-0.300),cul1),
        VertexFormat(loc + glm::vec3(-0.300,0.1,-0.300),cul1),
        VertexFormat(loc + glm::vec3(-0.300,0.1,0.300),cul1),
        VertexFormat(loc + glm::vec3(0.300,3,0.300),cul1),
        VertexFormat(loc + glm::vec3(0.300,3,-0.300),cul1),
        VertexFormat(loc + glm::vec3(-0.300,3,-0.300),cul1),
        VertexFormat(loc + glm::vec3(-0.300,3,0.300),cul1),

        VertexFormat(loc + glm::vec3(2,3,2),cul2),
        VertexFormat(loc + glm::vec3(2,3,-2),cul2),
        VertexFormat(loc + glm::vec3(-2,3,-2),cul2),
        VertexFormat(loc + glm::vec3(-2,3,2),cul2),

        VertexFormat(loc + glm::vec3(2,6,2),cul2),
        VertexFormat(loc + glm::vec3(2,6,-2),cul2),
        VertexFormat(loc + glm::vec3(-2,6,-2),cul2),
        VertexFormat(loc + glm::vec3(-2,6,2),cul2)
};
    Mesh* pom = new Mesh(name);
    std::vector<unsigned int> indices{
        0,1,2,
        2,3,0,
        1,2,6,
        6,5,1,
        0,3,7,
        7,4,0,
        2,6,7,
        7,4,0,
        0,1,5,
        5,4,0,
        8,9,10,
        10,11,8,
        12,13,14,
        14,15,12,
        9,10,14,
        14,13,9,
        8,11,15,
        15,12,8,
        10,14,15,
        15,12,8,
        8,9,13,
        13,12,8
    };
    pom->InitFromData(vertices, indices);
    return pom;
}
Mesh* object3D::CreezMasina(
    const std::string& name,
    glm::vec3 loc,
    glm::vec3 cul,
    bool fill
)
{
   /* glm::vec3 locMasina = loc;
    std::vector<VertexFormat> vertices = {
       VertexFormat(loc + glm::vec3(0.100,0.1,0.100),cul),
       VertexFormat(loc + glm::vec3(0.100,0.1,-0.100),cul),
       VertexFormat(loc + glm::vec3(-0.100,0.1,-0.100),cul),
       VertexFormat(loc + glm::vec3(-0.100,0.1,0.100),cul),
       VertexFormat(loc + glm::vec3(0.100,2,0.100),cul),
       VertexFormat(loc + glm::vec3(0.100,2,-0.100),cul),
       VertexFormat(loc + glm::vec3(-0.100,2,-0.100),cul),
       VertexFormat(loc + glm::vec3(-0.100,2,0.100),cul),

       VertexFormat(loc + glm::vec3(1,0.5,1),cul),
       VertexFormat(loc + glm::vec3(1,0.5,-1),cul),
       VertexFormat(loc + glm::vec3(-1,0.5,-1),cul),
       VertexFormat(loc + glm::vec3(-1,0.5,1),cul),

       VertexFormat(loc + glm::vec3(1,1.5,1),cul),
       VertexFormat(loc + glm::vec3(1,1.5,-1),cul),
       VertexFormat(loc + glm::vec3(-1,1.5,-1),cul),
       VertexFormat(loc + glm::vec3(-1,1.5,1),cul)
    };
    Mesh* bolid = new Mesh(name);
    std::vector<unsigned int> indices{
        
        8,9,10,
        10,11,8,
        12,13,14,
        14,15,12,
        9,10,14,
        14,13,9,
        8,11,15,
        15,12,8,
        10,14,15,
        15,12,8,
        8,9,13,
        13,12,8
    };
    bolid->InitFromData(vertices, indices);
    return bolid;*/
    std::vector<VertexFormat> vertices = {
       VertexFormat(loc + glm::vec3(-1,0.5,1),cul),
       VertexFormat(loc + glm::vec3(1,0.5,1),cul),
       VertexFormat(loc + glm::vec3(-1,0.5,-1),cul),
       VertexFormat(loc + glm::vec3(1,0.5,-1),cul),

       VertexFormat(loc + glm::vec3(-1,1.5,1),cul),
       VertexFormat(loc + glm::vec3(1,1.5,1),cul),
       VertexFormat(loc + glm::vec3(-1,1.5,-1),cul),
       VertexFormat(loc + glm::vec3(1,1.5,-1),cul)
    };
    Mesh* bolid = new Mesh(name);
    std::vector<unsigned int> indices{
        0,1,2,
        2,3,1,
        4,5,6,
        6,7,5,
        0,4,1,
        1,5,4,
        6,2,7,
        7,3,2,
        0,4,2,
        2,6,4,
        1,3,5,
        5,7,3
    };
    bolid->InitFromData(vertices, indices);
    return bolid; 
}



