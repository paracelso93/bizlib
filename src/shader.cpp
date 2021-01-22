//
// Created by edoardo biasio on 2021-01-21.
//

#include "shader.h"

namespace biz {
    void ShaderProgram::bind() {
        glUseProgram(program);
    }

    bool ShaderProgram::load(const std::string &vertex, const std::string &fragment) {

        bool loadSuccess = true;

        GLuint vertexShader;
        if (!load_shader(vertex, GL_VERTEX_SHADER, vertexShader)) {
            loadSuccess = false;
        }

        GLuint fragmentShader;
        if (!load_shader(fragment, GL_FRAGMENT_SHADER, fragmentShader)) {
            loadSuccess = false;
        }

        // Program
        program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);

        glLinkProgram(program);
        char infoLog[512];
        GLint success;

        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(program, 512, nullptr, infoLog);
            std::cout << "ERROR::LOADSHADERS::COULD_NOT_LINK_PROGRAM" << std::endl;
            std::cout << infoLog << std::endl;
            loadSuccess = false;
        }

        unbind();
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return loadSuccess;
    }

    void ShaderProgram::unbind() {
        glUseProgram(0);
    }

    void ShaderProgram::delete_program() {
        glDeleteProgram(program);
    }

    GLint ShaderProgram::get_uniform(const std::string &uniform_name) {
        const GLchar *name = uniform_name.c_str();
        return glGetUniformLocation(program, name);
    }

    bool ShaderProgram::load_shader(const std::string &name, GLenum type, GLuint &result) {
        bool load_success = true;
        std::string temp;
        std::string src;
        char infoLog[512];
        GLint success;

        std::ifstream in_file;

        // Vertex
        in_file.open(name);

        if (in_file.is_open()) {
            while (std::getline(in_file, temp)) {
                src += temp + "\n";
            }
        } else {
            std::cout << "ERROR::LOADSHADER::COULD_NOT_OPEN_FILE" << std::endl;
            load_success = false;
        }

        in_file.close();

        result = glCreateShader(type);
        const GLchar *vertSrc = src.c_str();
        glShaderSource(result, 1, &vertSrc, nullptr);
        glCompileShader(result);

        glGetShaderiv(result, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(result, 512, nullptr, infoLog);
            std::cout << "ERROR::LOADSHADERS::COULD_NOT_COMPILE_SHADER" << std::endl;
            if (type == GL_VERTEX_SHADER) {
                std::cout << "TYPE: VERTEX_SHADER" << std::endl;
            } else {
                std::cout << "TYPE: FRAGMENT_SHADER" << std::endl;
            }
            std::cout << infoLog << std::endl;
            load_success = false;
        }

        return load_success;
    }
}