#include "biz.h"


void updateInput(biz::Window &window, biz::Texture& tex) {
    if (window.is_key_pressed(BIZ_KEY_ESCAPE)) {
        window.close();
    }

    if (window.is_key_pressed(BIZ_KEY_W)) {
        tex.change_position(tex.get_position().x, tex.get_position().y - 2);
    }

    if (window.is_key_pressed(BIZ_KEY_S)) {
        tex.change_position(tex.get_position().x, tex.get_position().y + 2);
    }

    if (window.is_key_pressed(BIZ_KEY_A)) {
        tex.change_position(tex.get_position().x - 2, tex.get_position().y);
    }

    if (window.is_key_pressed(BIZ_KEY_D)) {
        tex.change_position(tex.get_position().x + 2, tex.get_position().y);
    }
}

int main() {
    // init glfw
    biz::Init();

    biz::Window window(640, 480, "BIZ", 0);


    biz::Texture tex;
    tex.set_rect(0, 0, 200, 200, &window);
    tex.set_path("res/images/samuele.png");
    tex.rotate(50.f);
    //tex.set_src_rect(200, 200, 600, 400);
    biz::Texture tex2;
    tex2.set_rect(300, 200, 300, 200, &window);
    tex2.set_path("res/images/obama.png");
    biz::ColorRect rect(0, 0, 200, 200, {255, 0, 0, 255}, &window);
    rect.rotate(10);
    biz::Font arial;
    arial.setup("res/fonts/Arial.ttf", &window);

    while (!window.should_close()) {
        window.poll_events();
        updateInput(window, tex);

        window.clear();
        tex.render();
        tex2.render();
        rect.render();
        arial.renderText("hello world", 0.f, 48.f, 1.f, {0, 255, 0, 255});
        arial.renderText(std::to_string(static_cast<int>(1.0 / window.get_elapsed_time())), 500.f, 480.f, 1.f, {0, 0, 255, 255});
        window.display();
    }

    window.quit();
    biz::Quit();

    return 0;
}