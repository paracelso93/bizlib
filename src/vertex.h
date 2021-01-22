//
// Created by edoardo biasio on 2021-01-20.
//

#ifndef OPENGL_VERTEX_H
#define OPENGL_VERTEX_H

#include "libs.h"

namespace biz {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 color;
        glm::vec2 texcoord;
    };
}

#endif //OPENGL_VERTEX_H
