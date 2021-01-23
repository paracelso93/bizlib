//
// Created by edoardo biasio on 2021-01-21.
//

#ifndef OPENGL_COLOR_RECT_H
#define OPENGL_COLOR_RECT_H

#include "maths.h"
#include "shader.h"
#include "vertex.h"
#include "color.h"
#include "window.h"

namespace biz {
    class ColorRect {
    public:
        ColorRect(int x, int y, int w, int h, Color color, const Window* window);
        void change_position(int x, int y);
        void rotate(float value);
        void render();
        static ShaderProgram* color_shader;
    private:
        Rect<int> rectangle;
        Color color;
        const Window* wnd;
        unsigned int VAO;
        unsigned int VBO;
        glm::mat4 rotation_mat;
        glm::mat4 center_mat;
        Vector2<float> decenter;
        float rotation;
    };
}

#endif //OPENGL_COLOR_RECT_H
