#version 410

in vec3 vt_position;
in vec3 vt_color;

out vec4 fs_color;

void main() {
    fs_color = vec4(vt_color, 1.f);
}