#pragma once

#include "components/simple_scene.h"
#include "lab_m1/tema2/lab_camera.h"

#define Z_FAR		(200.f)
#define Z_NEAR		(.01f)

namespace m1
{
    class tema2 : public gfxc::SimpleScene
    {
    public:
        struct ViewportArea
        {
            ViewportArea() : x(0), y(0), width(1), height(1) {}
            ViewportArea(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };
        tema2();
        ~tema2();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix) override;
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderScene();

    protected:
        implemented::Camera* camera;
        implemented::Camera* camera1;
        implemented::Camera* camera2;
        glm::mat4 projectionMatrix;
        bool renderCameraTarget;
        bool projectionType;
        glm::mat4 modelMatrix;
        glm::vec3 center = glm::vec3(0, 0, 0);

        // TODO(student): If you need any other class variables, define them here.
        GLfloat right;
        GLfloat left;
        GLfloat bottom;
        GLfloat top;
        GLfloat fov;
        float translateX, translateY, translateZ;
        float scaleX, scaleY, scaleZ;
        float angularStepOX, angularStepOY, angularStepOZ;
        GLenum polygonMode;

        GLfloat translateZSine, translateXSine, translateYSine;
        GLfloat angleX, angleZ;
        GLfloat posX, posZ, angle;
        GLfloat angleJump;

        glm::vec3 positionCar;
        float angleCar;
        std::vector<glm::vec3> puncteDrum;
        std::vector<glm::vec3> pozitiiPomi;
        ViewportArea miniViewportArea;
    };
}   // namespace m1
