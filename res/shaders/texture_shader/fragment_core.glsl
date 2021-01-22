#version 410

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;

out vec4 fs_color;

uniform sampler2D texture_sample;

void main() {
    fs_color = texture(texture_sample, vs_texcoord);
}