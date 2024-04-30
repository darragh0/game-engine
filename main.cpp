#include <windows.h>
#include <cstdlib>
#include "entity.h"
#include <iostream>
#include <conio.h>


void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    cursorInfo.dwSize = 10;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main() {

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE),
        &csbi
    );

    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    Scene scene(columns, rows);
    Sprite sprite(10, 10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            sprite.setCell(i, j, 'O');
        }
    }

    scene.addSprite(sprite);
    sprite.move(2, 2);

    system("cls");
    scene.show();

    while (true) {
        do {} while( !_kbhit() );

        switch (tolower(_getch())) {
            case 'w': sprite.move(0, 1); scene.show(); break;
            case 'a': sprite.move(-1, 0); scene.show(); break;
            case 's': sprite.move(0, -1); scene.show(); break;
            case 'd': sprite.move(1, 0); scene.show(); break;
            case 27: goto endloop;
        }
    }

    endloop:

    // TODO: setCell should update the cells if sprite cells updated after added to scene
    // TODO: After remove scene... do what
    // TODO: Multiple return values (auto tuple etc etc)

    ShowConsoleCursor(false);

    return 0;
}
