#pragma once


enum Color {
    BLACK = 90,
    RED = 91,
    GREEN = 92,
    YELLOW = 93,
    BLUE = 94,
    MAGENTA = 95,
    CYAN = 96,
    WHITE = 97
};


class Grid {

    public:

        struct Cell;

        const int width;
        const int height;
        const int area;
        Cell* cells;

        Grid(int width, int height);
        ~Grid() = default;
        const Cell& getCell(int x, int y_coord) const;
        void setCell(int x_coord, int y_coord, const Cell& cell) const;
        void setCell(int x_coord, int y_coord, char character) const;
        void setCell(int x_coord, int y_coord, Color color) const;
        void setCell(int x_coord, int y_coord, char character, Color color) const;
        void clearCell(int x_coord, int y_coord) const;

};


struct Grid::Cell {
    char data;
    Color color = Color::WHITE;

    explicit Cell(char data = '.');
};
