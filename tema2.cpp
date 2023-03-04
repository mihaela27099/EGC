#include "lab_m1/tema2/tema2.h"
#include "lab_m1/tema2/object3D.h"

#include <vector>
#include <string>
#include <iostream>
#include "lab_m1/tema2/transform3D.h"
#include "lab_m1//tema2/lab_camera.h"


using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


tema2::tema2()
{
}


tema2::~tema2()
{
}


void tema2::Init()
{
    puncteDrum =
    {
        glm::vec3(center + glm::vec3(-33.97,0.5,2.6)),
        glm::vec3(center + glm::vec3(-32.44,0.5,7.28)),
        glm::vec3(center + glm::vec3(-24.99,0.5,11.97)),
        glm::vec3(center + glm::vec3(-18.87,0.5,12.83)),
        glm::vec3(center + glm::vec3(-12.18,0.5,11.3)),
        glm::vec3(center + glm::vec3(-7.97,0.5,9.2)),
        glm::vec3(center + glm::vec3(-3.38,0.5,7.47)),
        glm::vec3(center + glm::vec3(0.54,0.5,6.9)),
        glm::vec3(center + glm::vec3(5.13,0.5,8.24)),
        glm::vec3(center + glm::vec3(10.67,0.5,9.96)),
        glm::vec3(center + glm::vec3(15,0.5,10)),
        glm::vec3(center + glm::vec3(18.22,0.5,10.25)),
        glm::vec3(center + glm::vec3(21.76,0.5,9)),
        glm::vec3(center + glm::vec3(24.91,0.5,6.14)),
        glm::vec3(center + glm::vec3(26.83,0.5,0.97)),
        glm::vec3(center + glm::vec3(28.26,0.5,-4.57)),
        glm::vec3(center + glm::vec3(26.25,0.5,-7.72)),
        glm::vec3(center + glm::vec3(20.9,0.5,-10.4)),
        glm::vec3(center + glm::vec3(16.88,0.5,-11.84)),
        glm::vec3(center + glm::vec3(9.05,0.5,-14.13)),
        glm::vec3(center + glm::vec3(3.41,0.5,-13.94)),
        glm::vec3(center + glm::vec3(0,0.5,-12.41)),
        glm::vec3(center + glm::vec3(-2.43,0.5,-11.07)),
        glm::vec3(center + glm::vec3(-6.06,0.5,-9.73)),
        glm::vec3(center + glm::vec3(-11.6,0.5,-8.97)),
        glm::vec3(center + glm::vec3(-15,0.5,-10)),
        glm::vec3(center + glm::vec3(-19.25,0.5,-10.4)),
        glm::vec3(center + glm::vec3(-23.26,0.5,-10.69)),
        glm::vec3(center + glm::vec3(-29,0.5,-10.69)),
        glm::vec3(center + glm::vec3(-31.49,0.5,-9.16)),
        glm::vec3(center + glm::vec3(-33.68,0.5,-6.86)),
        glm::vec3(center + glm::vec3(-36.27,0.5,-4.38)),
        glm::vec3(center + glm::vec3(-37.03,0.5,-1.32))
    };

   renderCameraTarget = false;
   projectionType = true;

    right = 10.f;
    left = .01f;
    bottom = .01f;
    top = 10.f;
    fov = 40.f;
    glm::vec3 center = glm::vec3(0, 0, 0);


   
    camera1 = new implemented::Camera();
    camera1->Set(glm::vec3(-25.05, 2.9, 13), glm::vec3(-18.87, 0.1, 12.83), glm::vec3(0, 1, 0));

    camera2 = new implemented::Camera();
    camera2->Set(camera1->GetTargetPosition() + glm::vec3(0, 10, 0), camera1->GetTargetPosition(), glm::vec3_right);

    positionCar = camera1->GetTargetPosition();
    angleCar = 0;
   {
        Mesh* drum = object3D::CreezDrum("drum",center, glm::vec3(0.2, 0.24, 0.24),true);
        AddMeshToList(drum);
   }
   {
       Mesh* iarba = object3D::CreezPatrat("iarba", center, 600, glm::vec3(0.420, 0.912, 0.398), true);
       AddMeshToList(iarba);
   }
   {
       Mesh* copac = object3D::CreezCopac("copac", center, glm::vec3(0.17, 0.1, 0.03),glm::vec3(0.04, 0.18, 0.03), true);
       AddMeshToList(copac);
   }
   {
       Mesh* copac1 = object3D::CreezCopac("copac1", glm::vec3(-23.05, 0.1, 17), glm::vec3(0.17, 0.1, 0.03), glm::vec3(0.04, 0.18, 0.03), true);
       AddMeshToList(copac1);
   }
   {
       Mesh* copac2 = object3D::CreezCopac("copac2", glm::vec3(-23.05, 0.1, 7), glm::vec3(0.17, 0.1, 0.03), glm::vec3(0.04, 0.18, 0.03), true);
       AddMeshToList(copac2);
   }
   {
       Mesh* copac3 = object3D::CreezCopac("copac3", glm::vec3(-12.05, 0.1, 5), glm::vec3(0.17, 0.1, 0.03), glm::vec3(0.04, 0.18, 0.03), true);
       AddMeshToList(copac3);
   }
   {
       Mesh* copac4 = object3D::CreezCopac("copac4", glm::vec3(-12.05, 0.1, 17), glm::vec3(0.17, 0.1, 0.03), glm::vec3(0.04, 0.18, 0.03), true);
       AddMeshToList(copac4);
   }
   {
       Mesh* copac2 = object3D::CreezCopac("copac2", glm::vec3(-23.05, 0.1, 7), glm::vec3(0.17, 0.1, 0.03), glm::vec3(0.04, 0.18, 0.03), true);
       AddMeshToList(copac2);
   }
   {
       Mesh* copac2 = object3D::CreezCopac("copac2", glm::vec3(-23.05, 0.1, 7), glm::vec3(0.17, 0.1, 0.03), glm::vec3(0.04, 0.18, 0.03), true);
       AddMeshToList(copac2);
   }
   {
       Mesh* bolid = object3D::CreezMasina("bolid", glm::vec3(-23.05,0.1,13), glm::vec3(0.98, 0.03, 0.8), true);
       AddMeshToList(bolid);

       //camera->GetTargetPosition()
   }
    // TODO(student): After you implement the changing of the projection
    // parameters, remove hardcodings of these parameters
    
    for (int i = 0; i < puncteDrum.size() - 1; i++)
    {
        int z = rand() % 100000;
        if (z < 26465)
        {
            glm::vec3 dir = puncteDrum[i + 1] - puncteDrum[i];
            glm::vec3 p = glm::normalize(glm::cross(dir, glm::vec3(0, 1, 0)));
            glm::vec3 pos = puncteDrum[i] + 10.f * dir;
            pozitiiPomi.push_back(pos);

        }
    }
}


void tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.29, 0.95, 0.95, 1);//vceru
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Sets the screen area where to draw
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}
void tema2::RenderScene() {
    modelMatrix = glm::mat4(1);
    RenderMesh(meshes["drum"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat4(1);
    RenderMesh(meshes["iarba"], shaders["VertexColor"], modelMatrix);


    srand(time(0));
    for (int i = 0; i < pozitiiPomi.size() - 1; i++)
    {

        modelMatrix = glm::mat4(1);
        modelMatrix *= transform3D::Translate(pozitiiPomi[i].x, pozitiiPomi[i].y, pozitiiPomi[i].z);
        RenderMesh(meshes["copac"], shaders["VertexColor"], modelMatrix);

    }

    {
        modelMatrix = glm::mat4(1);
        RenderMesh(meshes["copac1"], shaders["VertexColor"], modelMatrix);//3
        modelMatrix = glm::mat4(1);
        RenderMesh(meshes["copac2"], shaders["VertexColor"], modelMatrix);//4
        modelMatrix = glm::mat4(1);
        RenderMesh(meshes["copac3"], shaders["VertexColor"], modelMatrix);//5
        modelMatrix = glm::mat4(1);
        RenderMesh(meshes["copac4"], shaders["VertexColor"], modelMatrix);//6
    }
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(glm::mat4(1), -positionCar) * modelMatrix;
    modelMatrix = glm::rotate(glm::mat4(1), angleCar, glm::vec3_up) * modelMatrix;
    modelMatrix = glm::translate(glm::mat4(1), camera->GetTargetPosition()) * modelMatrix;  
    RenderMesh(meshes["bolid"], shaders["VertexColor"], modelMatrix);
}


void tema2::Update(float deltaTimeSeconds)
{
    glLineWidth(3);
    glPointSize(5);
    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

    // Sets the screen area where to draw
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
    camera = camera1;
    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
    RenderScene();
   // DrawCoordinateSystem();

    glClear(GL_DEPTH_BUFFER_BIT);
    miniViewportArea = ViewportArea(50, 50, resolution.x/5.f, resolution.y/5.f);
    glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);

    // TODO(student): render the scene again, in the new viewport
    //DrawCoordinateSystem()
    camera2->Set(camera1->GetTargetPosition() + glm::vec3(0, 15, 0), camera1->GetTargetPosition(), glm::vec3_right);
    camera = camera2;
    projectionMatrix = glm::ortho(-10.f, 10.f, -10.f, 10.f, 0.01f, 100.f);
    RenderScene();
}


void tema2::FrameEnd()
{
    //DrawCoordinateSystem(camera->GetViewMatrix(), projectionMatrix);
}


void tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void tema2::OnInputUpdate(float deltaTime, int mods)
{
    // move the camera only if MOUSE_RIGHT button is pressed
        // move the camera only if MOUSE_RIGHT button is pressed
        if (true)
        {
            float cameraSpeed = 7.0f;

            if (window->KeyHold(GLFW_KEY_W)) {
                // TODO(student): Translate the camera forward
                camera1->MoveForward(deltaTime * cameraSpeed);
            }

            if (window->KeyHold(GLFW_KEY_A)) {
                // TODO(student): Translate the camera to the left
                camera1->RotateFirstPerson_OY(deltaTime/2 * cameraSpeed);
                angleCar += deltaTime / 2 * cameraSpeed;
            }

            if (window->KeyHold(GLFW_KEY_S)) {
                // TODO(student): Translate the camera backward
                camera1->MoveForward(-deltaTime * cameraSpeed);
            }

            if (window->KeyHold(GLFW_KEY_D)) {
                // TODO(student): Translate the camera to the right
                camera1->RotateFirstPerson_OY(-deltaTime/2 * cameraSpeed);
                angleCar -= deltaTime / 2 * cameraSpeed;
            }
    }
}


void tema2::OnKeyPress(int key, int mods)
{
    // Add key press event
     // Add key press event
    if (key == GLFW_KEY_T)
    {
        renderCameraTarget = !renderCameraTarget;
    }
    // TODO(student): Switch projections
    if (key == GLFW_KEY_O)
    {
        projectionType = false;
        projectionMatrix = glm::ortho(left, right, bottom, top, Z_NEAR, Z_FAR);
    }
    if (key == GLFW_KEY_P)
    {
        projectionType = true;
        projectionMatrix = glm::perspective(RADIANS(fov), window->props.aspectRatio, Z_NEAR, Z_FAR);
    }      
   
}


void tema2::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event

    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        float sensivityOX = 0.001f;
        float sensivityOY = 0.001f;

        if (window->GetSpecialKeyState() == 0) {
            renderCameraTarget = false;
            // TODO(student): Rotate the camera in first-person mode around
            // OX and OY using `deltaX` and `deltaY`. Use the sensitivity
            // variables for setting up the rotation speed.
            camera->RotateFirstPerson_OX(sensivityOX * -deltaY);
            camera->RotateFirstPerson_OY(sensivityOY * -deltaX);
        }

        if (window->GetSpecialKeyState() & GLFW_MOD_CONTROL) {
            renderCameraTarget = true;
            // TODO(student): Rotate the camera in third-person mode around
            // OX and OY using `deltaX` and `deltaY`. Use the sensitivity
            // variables for setting up the rotation speed.
            camera->RotateThirdPerson_OX(sensivityOX * -deltaY);
            camera->RotateThirdPerson_OY(sensivityOY * -deltaX);
        }
    }
  
}


void tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void tema2::OnWindowResize(int width, int height)
{
}
