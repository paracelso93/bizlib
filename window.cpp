//
// Created by edoardo biasio on 2021-01-21.
//

#include "window.h"
#include "texture.h"
#include "color_rect.h"

namespace biz {
    Window::Window(int width, int height, const std::string& title, unsigned int flags) {
        // create window
        if ((flags & BIZ_WINDOW_RESIZABLE) != 0) {
            glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        } else {
            glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        }
        this->width = width;
        this->height = height;
        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (window == nullptr) {
            std::cout << "ERROR::MAIN.CPP::GLFW_CREATE_WINDOW_FAILED" << std::endl;
            glfwTerminate();
        }
        int framebufferWidth = 0, framebufferHeight = 0;
        if ((flags & BIZ_WINDOW_RESIZABLE) != 0) {
            glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
            glViewport(0, 0, framebufferWidth, framebufferHeight);
        } else {
            // OBAMAPIRAMIDE
            glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
        }

        glfwMakeContextCurrent(window); // IMPORTANT

        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            std::cout << "ERROR::MAIN.CPP::GLEW_INIT_FAILED" << std::endl;
            glfwTerminate();
        }

        // OPTIONS
        //glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CCW);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        // TODO: move this crap in create window
        biz::Texture::texture_shader = new biz::ShaderProgram();
        biz::Texture::texture_shader->load(base_path + "bizlib/res/shaders/texture_shader/vertex_core.glsl", base_path + "bizlib/res/shaders/texture_shader/fragment_core.glsl");

        biz::ColorRect::color_shader = new biz::ShaderProgram();
        biz::ColorRect::color_shader->load(base_path + "bizlib/res/shaders/color_shader/vertex_core.glsl", base_path + "bizlib/res/shaders/color_shader/fragment_core.glsl");
    }

    void Window::clear(Color color) {
        ColorFloat f = color.normalize();
        glClearColor(f.r, f.g, f.b, f.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }

    void Window::display() {
        glfwSwapBuffers(window);
        glFlush();

        glBindVertexArray(0);
        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void Window::close() {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    void Window::quit() {
        close();
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::poll_events() {
        glfwPollEvents();
    }

    bool Window::should_close() {
        return glfwWindowShouldClose(window);
    }

    bool Window::is_key_pressed(int key) {
        return glfwGetKey(window, key) == GLFW_PRESS;
    }
}