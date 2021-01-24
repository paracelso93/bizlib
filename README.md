# bizlib
Simple C++ 2D library written in OpenGL with glfw.

# Documentation
biz::Window base window class,
<br>biz::Texture base sprite class,
<br>biz::ColorRect drawable colored rectangle,
<br>biz::Init() initializes library,
<br>biz::Quit() quits library,
<br>A simple example:
<br>
```c++
#include "biz.h"

int main() {
    biz::Init();
    
    biz::Window window(400, 400, "Window", 0);
    
    biz::ColorRect rect(100, 100, 200, 200, {255, 0, 0, 255}, &window);
    
    while (!window.should_close()) {
        window.poll_events();
        if (window.is_key_pressed(BIZ_KEY_ESCAPE) {
            window.close();
        }
        window.clear();
        
        rect.render();
        
        window.display();
    }
    
    biz::Quit();
    return 0;
}
```

This examples create a red rectangle at position 100, 100 and with a size of 200, 200. It draws it to the screen and, if
the escape key is pressed, it quits the game.

# Install
### Windows
work in progress

### MacOS
To compile it from source install glfw (https://www.glfw.org), glew (http://glew.sourceforge.net), glm (https://github.com/g-truc/glm), SOIL2 (https://github.com/SpartanJ/SOIL2), freetype (https://www.freetype.org) and irrKlang (https://www.ambiera.com/irrklang/).<br>
Then move to the main directory of the project, create a folder (build) where you can put the compiled source, move to it and run:
```$xslt
cmake ..
make
./opengl
```

### Linux
Similar to MacOS, isn't tested yet
