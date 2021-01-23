#version 410

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_color;
layout (location = 2) in vec2 vertex_texcoord;

out vec2 TexCoords;


void main() {
    gl_Position = vec4(vertex_position, 1.0);
    TexCoords = vertex_texcoord;
}