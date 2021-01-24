//
// Created by edoardo biasio on 2021-01-21.
//

#include "window.h"
#include "texture.h"
#include "color_rect.h"
#include "font.h"

namespace biz {
    Window::Window(int width, int height, const std::string& title, unsigned int flags) : fps(0.0) {
        if ((flags & BIZ_WINDOW_RESIZABLE) != 0) {
            glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        } else {
            glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        }
        this->width = width;
        this->height = height;
        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (window == nullptr) {
            std::cout << "ERROR::WINDOW::GLFW_CREATE_WINDOW_FAILED" << std::endl;
            glfwTerminate();
        }
        int framebufferWidth = 0, framebufferHeight = 0;
        if ((flags & BIZ_WINDOW_RESIZABLE) != 0) {
            glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
            glViewport(0, 0, framebufferWidth, framebufferHeight);
        } else {
            glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
        }

        glfwMakeContextCurrent(window);

        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            std::cout << "ERROR::WINDOW::GLEW_INIT_FAILED" << std::endl;
            glfwTerminate();
        }

        //glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CCW);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        biz::Texture::texture_shader = new biz::ShaderProgram();
        biz::Texture::texture_shader->load(base_path + "bizlib/res/shaders/texture_shader/vertex_core.glsl", base_path + "bizlib/res/shaders/texture_shader/fragment_core.glsl");

        biz::ColorRect::color_shader = new biz::ShaderProgram();
        biz::ColorRect::color_shader->load(base_path + "bizlib/res/shaders/color_shader/vertex_core.glsl", base_path + "bizlib/res/shaders/color_shader/fragment_core.glsl");

        biz::Font::font_shader = new biz::ShaderProgram();
        biz::Font::font_shader->load(base_path + "bizlib/res/shaders/font_shader/vertex_core.glsl", base_path + "bizlib/res/shaders/font_shader/fragment_core.glsl");

        Music::sound_engine = irrklang::createIrrKlangDevice();
        if (!Music::sound_engine) {
            std::cout << "ERROR::WINDOW::CREATE_IRRKLANG_DEVICE_FAILED" << std::endl;
        }
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

        auto new_time = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_time = new_time - time_start;
        fps = elapsed_time.count();
    }

    void Window::close() {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    void Window::quit() {
        Music::sound_engine->drop();
        close();
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::poll_events() {
        glfwPollEvents();

        time_start = std::chrono::system_clock::now();
    }

    bool Window::should_close() {
        return glfwWindowShouldClose(window);
    }

    bool Window::is_key_pressed(int key) {
        return glfwGetKey(window, key) == GLFW_PRESS;
    }
}