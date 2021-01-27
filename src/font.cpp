//
// Created by edoardo biasio on 2021-01-22.
//

#include "font.h"

namespace biz {
    ShaderProgram* Font::font_shader = nullptr;
    Font::Font(const std::string& file_path, unsigned int size, Window* window) {
        wnd = window;

        FT_Library library;
        if (FT_Init_FreeType(&library)) {
            std::cout << "ERROR::FONT.CPP::SETUP::FT_INIT_FREETYPE_FAILED" << std::endl;
        }

        FT_Face font_face;

        if (FT_New_Face(library, file_path.c_str(), 0, &font_face)) {
            std::cout << "FONT::SETUP::FT_NEW_FACE_FAILED" << std::endl;
        }


        FT_Set_Pixel_Sizes(font_face, 0, size);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        for (unsigned char c = 0; c < 128; c++) {
            if (FT_Load_Char(font_face, c, static_cast<unsigned int>(FT_LOAD_RENDER))) {
                std::cout << "ERROR::FONT.CPP::SETUP::FAILED_TO_LOAD_GLYPH" << std::endl;
                continue;
            }

            unsigned int texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(
                    GL_TEXTURE_2D,
                    0,
                    GL_RED,
                    font_face->glyph->bitmap.width,
                    font_face->glyph->bitmap.rows,
                    0,
                    GL_RED,
                    GL_UNSIGNED_BYTE,
                    font_face->glyph->bitmap.buffer
                    );
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            Character character = {
                    texture,
                    Vector2<int>(font_face->glyph->bitmap.width, font_face->glyph->bitmap.rows),
                    Vector2<int>(font_face->glyph->bitmap_left, font_face->glyph->bitmap_top),
                    static_cast<unsigned int>(font_face->glyph->advance.x)
            };
            characters[c] = character;
        }
        FT_Done_Face(font_face);
        FT_Done_FreeType(library);

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, nullptr, GL_DYNAMIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        unsigned int indices[] = {
                0, 1, 2,
                0, 2, 3
        };
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, indices, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, position));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, color));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, texcoord));
        glEnableVertexAttribArray(2);
        glBindVertexArray(0);
    }

    void Font::renderText(std::string text, int x, int y, Color color) {
        font_shader->bind();
        ColorFloat cf = color.normalize();
        glUniform3f(font_shader->get_uniform("textColor"), cf.r, cf.g, cf.b);
        glActiveTexture(GL_TEXTURE0);
        glBindVertexArray(VAO);

        std::string::const_iterator c;
        for (c = text.begin(); c != text.end(); c++) {
            Character ch = characters[*c];

            float x_pos = x + ch.bearing.x;
            float y_pos = y - (ch.size.y - ch.bearing.y);

            float w = ch.size.x;
            float h = ch.size.y;

            float f_x1 = (static_cast<float>(x_pos) / wnd->width) * 2.f - 1.f;
            float f_y2 = 1.f - (static_cast<float>(y_pos - h) / wnd->height) * 2.f;
            float f_x2 = (static_cast<float>(w) / wnd->width) * 2.f + f_x1;
            float f_y1 = (static_cast<float>(h) / wnd->height) * 2.f * (-1.f) + f_y2;

            Vertex vertices[] = {
                    glm::vec3(f_x1, f_y2, 0.f), glm::vec3(1.f, 0.f, 0.f), glm::vec2(0.f, 0.f),
                    glm::vec3(f_x1, f_y1, 0.f), glm::vec3(0.f, 1.f, 0.f), glm::vec2(0.f, 1.f),
                    glm::vec3(f_x2, f_y1, 0.f), glm::vec3(0.f, 0.f, 1.f), glm::vec2(1.f, 1.f),
                    glm::vec3(f_x2, f_y2, 0.f), glm::vec3(1.f, 1.f, 0.f), glm::vec2(1.f, 0.f),
            };

            glBindTexture(GL_TEXTURE_2D, ch.textureID);
            glUniform1i(font_shader->get_uniform("text"), 0);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            x += ch.advance / 64;
        }
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
        font_shader->unbind();
    }
}
