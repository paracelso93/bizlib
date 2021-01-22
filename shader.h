//
// Created by edoardo biasio on 2021-01-21.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include "libs.h"

namespace biz {
    const std::string base_path = "/Users/edoardobiasio/CLionProjects/opengl/";

    class ShaderProgram {
    public:
        void bind();
        bool load(const std::string &vertex, const std::string &fragment);
        void unbind();
        GLint get_uniform(const std::string &uniform_name);
        void delete_program();

    private:
        GLuint program;
        bool load_shader(const std::string &name, GLenum type, GLuint &result);
    };
}


#endif //OPENGL_SHADER_H
