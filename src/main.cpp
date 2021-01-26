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
    biz::Init();

    biz::Window window(640, 480, "BIZ", 0);


    biz::Texture tex(0, 0, 200, 200, "res/images/samuele.png", &window);
    //biz::Texture tex(0, 0, BIZ_TEXTURE_SIZE, BIZ_TEXTURE_SIZE, "res/images/samuele.png", &window);
    biz::Texture tex2(300, 200, 300, 200, "res/images/obama.png", &window);
    biz::ColorRect rect(0, 0, 200, 200, {255, 0, 0, 255}, &window);
    //rect.rotate(10);
    //rect.change_size(500, 500);
    biz::Font arial;
    arial.setup("res/fonts/Arial.ttf", 48, &window);

    biz::Sound mus("res/music/music.wav");
    mus.set_looped(true);
    mus.play();

    while (!window.should_close()) {
        window.poll_events();
        updateInput(window, tex);

        window.clear();
        tex.render();
        tex2.render();
        rect.render();
        arial.renderText("hello world", 0, 48, {0, 255, 0, 255});
        arial.renderText(std::to_string(static_cast<int>(1.0 / window.get_elapsed_time())), 500, 480, {0, 0, 255, 255});
        window.display();
    }

    window.quit();
    biz::Quit();

    return 0;
}