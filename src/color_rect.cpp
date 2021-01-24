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

        rotation_mat = glm::mat4(1.f);
        center_mat = glm::mat4(1.f);
        center_mat = glm::translate(center_mat,
                                    glm::vec3(-f_x1 - (f_x2 - f_x1) / 2.f, -f_y1 - (f_y2 - f_y1) / 2.f, 0.f));
        decenter = Vector2<float>(f_x1 + (f_x2 - f_x1) / 2.f, f_y1 + (f_y2 - f_y1) / 2.f);

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

        GLuint EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, position));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, color));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
    }

    void ColorRect::rotate(float value) {
        rotation = value;
        glm::mat4 mat = glm::mat4(1.f);
        mat = glm::rotate(mat, glm::radians(value), glm::vec3(0, 0, 1.f));

        rotation_mat = mat;
        rotation_mat = mat * center_mat;
        glm::mat4 decenter_mat = glm::mat4(1.f);
        decenter_mat = glm::translate(decenter_mat, glm::vec3(decenter.x, decenter.y, 0.f));
        rotation_mat = decenter_mat * rotation_mat;
    }

    void ColorRect::change_position(int x, int y) {
        this->rectangle.position.x = x;
        this->rectangle.position.y = y;
        float f_x1 = (static_cast<float>(x) / wnd->width) * 2.f - 1.f;
        float f_y2 = 1.f - (static_cast<float>(y) / wnd->height) * 2.f;
        float f_x2 = (static_cast<float>(rectangle.size.x) / wnd->width) * 2.f + f_x1;
        float f_y1 = (static_cast<float>(rectangle.size.y) / wnd->height) * 2.f * (-1.f) + f_y2;
        ColorFloat c = color.normalize();
        glm::vec3 cc = glm::vec3(c.r, c.g, c.b);

        Vertex vertices[] = {
                glm::vec3(f_x1, f_y2, 0.f), cc, glm::vec2(0.f, 1.f),
                glm::vec3(f_x1, f_y1, 0.f), cc, glm::vec2(0.f, 0.f),
                glm::vec3(f_x2, f_y1, 0.f), cc, glm::vec2(1.f, 0.f),
                glm::vec3(f_x2, f_y2, 0.f), cc, glm::vec2(1.f, 1.f),
        };

        center_mat = glm::mat4(1.f);
        center_mat = glm::translate(center_mat, glm::vec3(-f_x1 - (f_x2 - f_x1) / 2.f, -f_y1 - (f_y2 - f_y1) / 2.f, 0.f));

        rotation_mat = glm::mat4(1.f);
        rotation_mat = glm::rotate(rotation_mat, glm::radians(rotation), glm::vec3(0, 0, 1.f));
        rotation_mat = rotation_mat * center_mat;
        decenter = Vector2<float>(f_x1 + (f_x2 - f_x1) / 2.f, f_y1 + (f_y2 - f_y1) / 2.f);
        glm::mat4 decenter_mat = glm::mat4(1.f);
        decenter_mat = glm::translate(decenter_mat, glm::vec3(decenter.x, decenter.y, 0.f));
        rotation_mat = decenter_mat * rotation_mat;

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, position));
        glEnableVertexAttribArray(0);
        glBindVertexArray(0);
    }

    void ColorRect::change_size(int w, int h) {
        this->rectangle.size.x = w;
        this->rectangle.size.y = h;
        float f_x1 = (static_cast<float>(rectangle.position.x) / wnd->width) * 2.f - 1.f;
        float f_y2 = 1.f - (static_cast<float>(rectangle.position.y) / wnd->height) * 2.f;
        float f_x2 = (static_cast<float>(rectangle.size.x) / wnd->width) * 2.f + f_x1;
        float f_y1 = (static_cast<float>(rectangle.size.y) / wnd->height) * 2.f * (-1.f) + f_y2;
        ColorFloat c = color.normalize();
        glm::vec3 cc = glm::vec3(c.r, c.g, c.b);

        Vertex vertices[] = {
                glm::vec3(f_x1, f_y2, 0.f), cc, glm::vec2(0.f, 1.f),
                glm::vec3(f_x1, f_y1, 0.f), cc, glm::vec2(0.f, 0.f),
                glm::vec3(f_x2, f_y1, 0.f), cc, glm::vec2(1.f, 0.f),
                glm::vec3(f_x2, f_y2, 0.f), cc, glm::vec2(1.f, 1.f),
        };

        center_mat = glm::mat4(1.f);
        center_mat = glm::translate(center_mat, glm::vec3(-f_x1 - (f_x2 - f_x1) / 2.f, -f_y1 - (f_y2 - f_y1) / 2.f, 0.f));

        rotation_mat = glm::mat4(1.f);
        rotation_mat = glm::rotate(rotation_mat, glm::radians(rotation), glm::vec3(0, 0, 1.f));
        rotation_mat = rotation_mat * center_mat;
        decenter = Vector2<float>(f_x1 + (f_x2 - f_x1) / 2.f, f_y1 + (f_y2 - f_y1) / 2.f);
        glm::mat4 decenter_mat = glm::mat4(1.f);
        decenter_mat = glm::translate(decenter_mat, glm::vec3(decenter.x, decenter.y, 0.f));
        rotation_mat = decenter_mat * rotation_mat;

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, position));
        glEnableVertexAttribArray(0);
        glBindVertexArray(0);
    }

    void ColorRect::render() {
        color_shader->bind();

        glUniformMatrix4fv(color_shader->get_uniform("trans"), 1, GL_FALSE, glm::value_ptr(rotation_mat));

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
        color_shader->unbind();
    }
}