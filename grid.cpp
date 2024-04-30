#include "grid.h"


Grid::Grid(int width, int height)
    : width(width),
      height(height),
      area(width * height),
      cells(new Cell[this->area]) {}


Grid::Cell::Cell(char data)
    : data(data) {}


const Grid::Cell& Grid::getCell(const int x_coord, const int y_coord) const {
    return this->cells[x_coord * this->height + y_coord];
}


void Grid::setCell(int x_coord, int y_coord, const Cell& cell) const {
    this->cells[x_coord * this->height + y_coord].data = cell.data;
    this->cells[x_coord * this->height + y_coord].color = cell.color;
}


void Grid::setCell(const int x_coord, const int y_coord, char character) const {
    this->cells[x_coord * this->height + y_coord].data = character;
}


void Grid::setCell(const int x_coord, const int y_coord, Color color) const {
    this->cells[x_coord * this->height + y_coord].color = color;
}


void Grid::setCell(const int x_coord, const int y_coord, char character, Color color) const {
    this->setCell(x_coord, y_coord, character);
    this->setCell(x_coord, y_coord, color);
}


void Grid::clearCell(const int x, const int y) const {
    this->cells[x * this->height + y].data = '.';
    this->cells[x * this->height + y].color = Color::WHITE;
}
