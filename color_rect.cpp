//
// Created by edoardo biasio on 2021-01-21.
//

#include "color_rect.h"

namespace biz {
    ShaderProgram* ColorRect::color_shader = nullptr;

    ColorRect::ColorRect(int x, int y, int w, int h, Color color, const Window* window) {
        this->rectangle = Rect<int>(x, y, w, h);
        this->color = color;
        this->wnd = window;

        float f_x1 = (static_cast<float>(x) / wnd->width) * 2.f - 1.f;
        float f_y2 = 1.f - (static_cast<float>(y) / wnd->height) * 2.f;
        float f_x2 = (static_cast<float>(w) / wnd->width) * 2.f + f_x1;
        float f_y1 = (static_cast<float>(h) / wnd->height) * 2.f * (-1.f) + f_y2;
        //f_y1 *= -1.f;
        ColorFloat c = color.normalize();

        Vertex vertices[] = {
                glm::vec3(f_x1, f_y2, 0.f), glm::vec3(c.r, c.g, c.b), glm::vec2(0.f, 0.f),
                glm::vec3(f_x1, f_y1, 0.f), glm::vec3(c.r, c.g, c.b), glm::vec2(0.f, 0.f),
                glm::vec3(f_x2, f_y1, 0.f), glm::vec3(c.r, c.g, c.b), glm::vec2(0.f, 0.f),
                glm::vec3(f_x2, f_y2, 0.f), glm::vec3(c.r, c.g, c.b), glm::vec2(0.f, 0.f),
        };


        GLuint indices[] = {
                0, 1, 2,
                0, 2, 3
        };

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        //GLuint VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        GLuint EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, position));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, color));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
    }

    void ColorRect::change_position(int x, int y) {
        this->rectangle.position.x = x;
        this->rectangle.position.y = y;
        float f_x1 = (static_cast<float>(x) / wnd->width) * 2.f - 1.f;
        float f_y2 = 1.f - (static_cast<float>(y) / wnd->height) * 2.f;
        float f_x2 = (static_cast<float>(rectangle.size.x) / wnd->width) * 2.f + f_x1;
        float f_y1 = (static_cast<float>(rectangle.size.y) / wnd->height) * 2.f * (-1.f) + f_y2;

        Vertex vertices[] = {
                glm::vec3(f_x1, f_y2, 0.f), glm::vec3(1.f, 0.f, 0.f), glm::vec2(0.f, 1.f),
                glm::vec3(f_x1, f_y1, 0.f), glm::vec3(0.f, 1.f, 0.f), glm::vec2(0.f, 0.f),
                glm::vec3(f_x2, f_y1, 0.f), glm::vec3(0.f, 0.f, 1.f), glm::vec2(1.f, 0.f),
                glm::vec3(f_x2, f_y2, 0.f), glm::vec3(1.f, 1.f, 0.f), glm::vec2(1.f, 1.f),
        };

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, position));
        glEnableVertexAttribArray(0);
        glBindVertexArray(0);
    }

    void ColorRect::render() {
        color_shader->bind();

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
        color_shader->unbind();
    }
}