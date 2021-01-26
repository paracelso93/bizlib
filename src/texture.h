//
// Created by edoardo biasio on 2021-01-21.
//

#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

#include "shader.h"
#include "vertex.h"
#include "maths.h"
#include "window.h"

namespace biz {
#define BIZ_TEXTURE_SIZE -1
    class Texture {
    private:
        GLuint VAO;
        GLuint VBO;
        GLuint EBO;
        unsigned int texture;
        int width;
        int height;
        unsigned char *image;
        Rect<int> rect;
        Rect<float> src_rect;
        const Window* wnd;
        glm::mat4 rotation_mat;
        glm::mat4 center_mat;
        Vector2<float> decenter;
        float rotation;
        void calculate_vertices(Vertex vertices[4]);
    public:
        void set_rect(int x, int y, int w, int h, const Window* window);
        void set_path(const std::string &file_path);
        Texture(int x, int y, int w, int h, const std::string& path, const Window* window);
        void set_src_rect(int x, int y, int w, int h);
        Vector2<int> get_texture_size();
        void render();
        void rotate(float value);
        void change_position(int new_x, int new_y);
        void change_size(int new_w, int new_h);
        Vector2<int> get_position() const { return rect.position; }
        static ShaderProgram* texture_shader;
    };
}


#endif //OPENGL_TEXTURE_H
