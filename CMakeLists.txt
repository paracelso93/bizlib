cmake_minimum_required(VERSION 3.13)
project(opengl)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include /usr/local/include/freetype2)
link_directories(/usr/local/lib)
add_executable(opengl src/main.cpp src/shader.cpp src/texture.cpp src/color_rect.cpp src/window.cpp src/biz.cpp src/font.cpp src/sound.cpp src/sound.h)
target_link_libraries(opengl "-framework OpenGL" glfw glew soil2-debug freetype irrklang)