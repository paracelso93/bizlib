cmake_minimum_required(VERSION 3.13)
project(opengl)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_executable(opengl main.cpp shader.cpp texture.cpp color_rect.cpp window.cpp biz.cpp)
target_link_libraries(opengl "-framework OpenGL" glfw glew soil2-debug)