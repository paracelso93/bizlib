//
// Created by edoardo biasio on 2021-01-21.
//

#ifndef OPENGL_BIZ_H
#define OPENGL_BIZ_H

#include "shader.h"
#include "color_rect.h"
#include "texture.h"
#include "window.h"

namespace biz {
    inline static void Init() {

        if (glfwInit() != GLFW_TRUE) {
            std::cout << "ERROR::MAIN.CPP::GLFW_INIT_FAILED" << std::endl;
            glfwTerminate();
        }

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    }

    inline static void Quit() {
        Texture::texture_shader->delete_program();
        ColorRect::color_shader->delete_program();
        glfwTerminate();
    }
}

#endif //OPENGL_BIZ_H
