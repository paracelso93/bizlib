//
// Created by edoardo biasio on 2021-01-22.
//

#ifndef OPENGL_GLYPH_H
#define OPENGL_GLYPH_H

#include "texture.h"
#include "maths.h"

namespace biz {
    struct Character {
        unsigned int textureID;
        Vector2<int> size;
        Vector2<int> bearing;
        unsigned int advance;
    };

    class Font {
    private:
        glm::mat4 projection;
        std::map<char, Character> characters;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        Window* wnd;
    public:
        bool setup(const std::string& file_path, Window* window);
        void renderText(std::string text, float x, float y, float scale, Color color);
        static ShaderProgram* font_shader;
    };
}

#endif //OPENGL_GLYPH_H
