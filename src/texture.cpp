//
// Created by edoardo biasio on 2021-01-21.
//

#include "texture.h"

namespace biz {
    ShaderProgram* Texture::texture_shader = nullptr;

    Texture::Texture(int x, int y, int w, int h, const std::string& path, const Window* window) {
        set_rect(x, y, w, h, window);
        set_path(path);
    }

    void Texture::set_rect(int x, int y, int w, int h, const Window* window) {
        this->rect.size.x = w;
        this->rect.size.y = h;
        this->rect.position.x = x;
        this->rect.position.y = y;
        this->wnd = window;
        src_rect.position.x = 0.f;
        src_rect.position.y = 0.f;
        src_rect.size.x = 1.f;
        src_rect.size.y = 1.f;

        Vertex vertices[4];
        calculate_vertices(vertices);

        GLuint indices[] = {
                0, 1, 2,
                0, 2, 3
        };

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, position));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, color));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, texcoord));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
    }

    void Texture::set_src_rect(int x, int y, int w, int h) {
        float u_x = static_cast<float>(x) / width;
        float u_y = static_cast<float>(y) / height;
        float u_w = u_x + static_cast<float>(w) / width;
        float u_h = u_y + static_cast<float>(h) / height;
        src_rect.position.x = u_x;
        src_rect.position.y = u_y;
        src_rect.size.x = u_w;
        src_rect.size.y = u_h;

        Vertex vertices[4];
        calculate_vertices(vertices);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) offsetof(Vertex, position));
        glEnableVertexAttribArray(0);
        glBindVertexArray(0);
    }
    void Texture::calculate_vertices(Vertex vertices[4]) {
        float f_x1 = (static_cast<float>(this->rect.position.x) / wnd->width) * 2.f - 1.f;
        float f_y2 = 1.f - (static_cast<float>(this->rect.position.y) / wnd->height) * 2.f;
        float f_x2 = (static_cast<float>(this->rect.size.x) / wnd->width) * 2.f + f_x1;
        float f_y1 = (static_cast<float>(this->rect.size.y) / wnd->height) * 2.f * (-1.f) + f_y2;

        vertices[0] = {glm::vec3(f_x1, f_y2, 0.f), glm::vec3(1.f, 0.f, 0.f), glm::vec2(src_rect.position.x, src_rect.size.y)};
        vertices[1] = {glm::vec3(f_x1, f_y1, 0.f), glm::vec3(0.f, 1.f, 0.f), glm::vec2(src_rect.position.x, src_rect.position.y)};
        vertices[2] = {glm::vec3(f_x2, f_y1, 0.f), glm::vec3(0.f, 0.f, 1.f), glm::vec2(src_rect.size.x, src_rect.position.y)};
        vertices[3] = {glm::vec3(f_x2, f_y2, 0.f), glm::vec3(1.f, 1.f, 0.f), glm::vec2(src_rect.size.x, src_rect.size.y)};

        rotation_mat = glm::mat4(1.f);
        center_mat = glm::mat4(1.f);
        center_mat = glm::translate(center_mat, glm::vec3(-f_x1 - (f_x2 - f_x1) / 2.f, -f_y1 - (f_y2 - f_y1) / 2.f, 0.f));
        decenter = Vector2<float>(f_x1 + (f_x2 - f_x1) / 2.f, f_y1 + (f_y2 - f_y1) / 2.f);
    }

    void Texture::change_position(int new_x, int new_y) {
        this->rect.position.x = new_x;
        this->rect.position.y = new_y;

        Vertex vertices[4];
        calculate_vertices(vertices);

        rotation_mat = glm::rotate(rotation_mat, glm::radians(rotation), glm::vec3(0, 0, 1.f));
        rotation_mat = rotation_mat * center_mat;
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

    void Texture::change_size(int new_w, int new_h) {
        this->rect.size.x = new_w;
        this->rect.size.y = new_h;
        Vertex vertices[4];
        calculate_vertices(vertices);


        rotation_mat = glm::rotate(rotation_mat, glm::radians(rotation), glm::vec3(0, 0, 1.f));
        rotation_mat = rotation_mat * center_mat;
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

    void Texture::rotate(float value) {
        rotation = value;
        glm::mat4 mat = glm::mat4(1.f);
        mat = glm::rotate(mat, glm::radians(value), glm::vec3(0, 0, 1.f));

        rotation_mat = mat;
        rotation_mat = mat * center_mat;
        glm::mat4 decenter_mat = glm::mat4(1.f);
        decenter_mat = glm::translate(decenter_mat, glm::vec3(decenter.x, decenter.y, 0.f));
        rotation_mat = decenter_mat * rotation_mat;
    }

    void Texture::set_path(const std::string &file_path) {
        const char *file = file_path.c_str();
        image = SOIL_load_image(file, &width, &height, nullptr, SOIL_LOAD_RGBA);
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        if (image) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cout << "ERROR::TEXTURE_LOADING_FAILED" << std::endl;
        }


        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, 0);
        SOIL_free_image_data(image);
    }

    Vector2<int> Texture::get_texture_size() {
        return Vector2<int>(width, height);
    }

    void Texture::render() {
        texture_shader->bind();

        glUniform1i(texture_shader->get_uniform("texture_sample"), 0);
        glUniformMatrix4fv(texture_shader->get_uniform("trans"), 1, GL_FALSE, glm::value_ptr(rotation_mat));

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
        texture_shader->unbind();
        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}