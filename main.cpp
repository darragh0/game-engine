//#include <windows.h>
#include "entity.h"

int main() {

//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//
//    GetConsoleScreenBufferInfo(
//        GetStdHandle(STD_OUTPUT_HANDLE),
//        &csbi
//    );
//
//    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    Scene scene(10, 10);
    Sprite sprite(5, 5);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            sprite.setCell(i, j, 'O');
        }
    }

    scene.addSprite(sprite);
    sprite.move(0, 1);
    scene.show();

    // TODO: setCell should update the cells if sprite cells updated after added to scene
    // TODO: After remove scene... do what
    // TODO: Multiple return values (auto tuple etc etc)

    return 0;
}
