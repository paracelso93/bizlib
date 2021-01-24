//
// Created by edoardo biasio on 2021-01-21.
//

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include "libs.h"
#include "color.h"

enum window_flags : unsigned int {
    BIZ_WINDOW_FULLSCREEN = 1 << 0,
    BIZ_WINDOW_RESIZABLE = 1 << 1,
};

enum key_codes : int {
    BIZ_KEY_UNKNOWN = -1,
    BIZ_KEY_SPACE = 32,
    BIZ_KEY_APOSTROPHE = 39,
    BIZ_KEY_COMMA = 44,
    BIZ_KEY_MINUS = 45,
    BIZ_KEY_PERIOD = 46,
    BIZ_KEY_SLASH = 47,
    BIZ_KEY_0 = 48,
    BIZ_KEY_1 = 49,
    BIZ_KEY_2 = 50,
    BIZ_KEY_3 = 51,
    BIZ_KEY_4 = 52,
    BIZ_KEY_5 = 53,
    BIZ_KEY_6 = 54,
    BIZ_KEY_7 = 55,
    BIZ_KEY_8 = 56,
    BIZ_KEY_9 = 57,
    BIZ_KEY_SEMICOLON = 59,
    BIZ_KEY_EQUAL = 61,
    BIZ_KEY_A = 65,
    BIZ_KEY_B = 66,
    BIZ_KEY_C,
    BIZ_KEY_D,
    BIZ_KEY_E,
    BIZ_KEY_F,
    BIZ_KEY_G,
    BIZ_KEY_H,
    BIZ_KEY_I,
    BIZ_KEY_J,
    BIZ_KEY_K,
    BIZ_KEY_L,
    BIZ_KEY_M,
    BIZ_KEY_N,
    BIZ_KEY_O,
    BIZ_KEY_P,
    BIZ_KEY_Q,
    BIZ_KEY_R,
    BIZ_KEY_S,
    BIZ_KEY_T,
    BIZ_KEY_U,
    BIZ_KEY_V,
    BIZ_KEY_W,
    BIZ_KEY_X,
    BIZ_KEY_Y,
    BIZ_KEY_Z,
    BIZ_KEY_LEFT_BRACKET,
    BIZ_KEY_BACKSLASH,
    BIZ_KEY_RIGHT_BRACKET,
    BIZ_KEY_GRAVE_ACCENT = 96,
    BIZ_KEY_WORLD_1 = 161,
    BIZ_KEY_WORLD_2 = 162,
    BIZ_KEY_ESCAPE = 256,
    BIZ_KEY_ENTER,
    BIZ_KEY_TAB,
    BIZ_KEY_BACKSPACE,
    BIZ_KEY_INSERT,
    BIZ_KEY_DELETE,
    BIZ_KEY_RIGHT,
    BIZ_KEY_LEFT,
    BIZ_KEY_DOWN,
    BIZ_KEY_UP,
    BIZ_KEY_PAGE_UP,
    BIZ_KEY_PAGE_DOWN,
    BIZ_KEY_HOME,
    BIZ_KEY_END,
    BIZ_KEY_CAPS_LOCK = 280,
    BIZ_KEY_SCROLL_LOCK,
    BIZ_KEY_NUM_LOCK,
    BIZ_KEY_PRINT_SCREEN,
    BIZ_KEY_PAUSE,
    BIZ_KEY_F1 = 290,
    BIZ_KEY_F2,
    BIZ_KEY_F3,
    BIZ_KEY_F4,
    BIZ_KEY_F5,
    BIZ_KEY_F6,
    BIZ_KEY_F7,
    BIZ_KEY_F8,
    BIZ_KEY_F9,
    BIZ_KEY_F10,
    BIZ_KEY_F11,
    BIZ_KEY_F12,
    BIZ_KEY_F13,
    BIZ_KEY_F14,
    BIZ_KEY_F15,
    BIZ_KEY_F16,
    BIZ_KEY_F17,
    BIZ_KEY_F18,
    BIZ_KEY_F19,
    BIZ_KEY_F20,
    BIZ_KEY_F21,
    BIZ_KEY_F22,
    BIZ_KEY_F23,
    BIZ_KEY_F24,
    BIZ_KEY_F25,
    BIZ_KEY_KP_0 = 320,
    BIZ_KEY_KP_1,
    BIZ_KEY_KP_2,
    BIZ_KEY_KP_3,
    BIZ_KEY_KP_4,
    BIZ_KEY_KP_5,
    BIZ_KEY_KP_6,
    BIZ_KEY_KP_7,
    BIZ_KEY_KP_8,
    BIZ_KEY_KP_9,
    BIZ_KEY_KP_DECIMAL,
    BIZ_KEY_KP_DIVIDE,
    BIZ_KEY_KP_MULTIPLY,
    BIZ_KEY_KP_SUBTRACT,
    BIZ_KEY_KP_ADD,
    BIZ_KEY_KP_ENTER,
    BIZ_KEY_KP_EQUAL,
    BIZ_KEY_KP_LEFT_SHIFT = 340,
    BIZ_KEY_KP_LEFT_CONTROL,
    BIZ_KEY_KP_LEFT_ALT,
    BIZ_KEY_KP_LEFT_SUPER,
    BIZ_KEY_KP_RIGHT_SHIFT,
    BIZ_KEY_KP_RIGHT_CONTROL,
    BIZ_KEY_KP_RIGHT_ALT,
    BIZ_KEY_KP_RIGHT_SUPER,
    BIZ_KEY_KP_MENU,
    BIZ_KEY_LAST,
};

namespace biz {
    class Window {
    public:
        Window(int width, int height, const std::string& title, unsigned int flags);
        void clear(Color color = Color());
        void display();
        void close();
        void quit();
        void poll_events();
        bool should_close();
        bool is_key_pressed(int key);
        double get_elapsed_time() const { return fps; }
        int width, height;
    private:
        GLFWwindow* window;
        std::chrono::time_point<std::chrono::system_clock> time_start;
        double fps;
    };

    inline static void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH) {
        glViewport(0, 0, fbW, fbH);
    }
}

#endif //OPENGL_WINDOW_H
