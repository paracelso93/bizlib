#version 410

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_color;

out vec3 vt_position;
out vec3 vt_color;

uniform mat4 trans;

void main() {
    vt_position = vertex_position;
    vt_color = vertex_color;

    gl_Position = trans * vec4(vertex_position, 1.f);
}