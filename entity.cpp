#include "entity.h"
#include <iostream>

Entity::Entity(int width, int height)
    : grid(width, height) {}


void Sprite::setParent(Scene *scene) {
    this->parent = scene;
    this->setPos(0, 0);
}


Sprite::Sprite(int width, int height, Scene* parent)
        : Entity(width, height), parent(parent) {

    this->setPos(0, 0);
}


Sprite::Sprite(int width, int height)
        : Entity(width, height), parent(nullptr) {}


int Sprite::getX() const {
    return this->x;
}

int Sprite::getY() const {
    return this->y;
}


const Grid::Cell& Sprite::getCell(int x_coord, int y_coord) const {
    return this->grid.getCell(x_coord, y_coord);
}

void Sprite::setCell(int x_coord, int y_coord, const Grid::Cell& cell) const {
    this->grid.setCell(x_coord, y_coord, cell);
}


void Sprite::setCell(int x_coord, int y_coord, char character, Color color) const {
    this->grid.setCell(x_coord, y_coord, character, color);
}


void Sprite::setCell(int x_coord, int y_coord, char character) const {
    this->grid.setCell(x_coord, y_coord, character);
}


void Sprite::setCell(int x_coord, int y_coord, Color color) const {
    this->grid.setCell(x_coord, y_coord, color);
}


void Sprite::clearCell(int x_coord, int y_coord) const {
    this->grid.clearCell(x_coord, y_coord);
}


void Sprite::setPos(const int x_coord, const int y_coord) {

    if (this->x != -1 && this->y != -1) {
        for (int _x = this->x; _x < this->grid.width + this->x; _x++) {
            for (int _y = this->y; _y < this->grid.height + this->y; _y++) {
                this->parent->grid.clearCell(_x, _y);
            }
        }
    }

    for (int _x = 0; _x < this->grid.width; _x++) {
        for (int _y = 0; _y < this->grid.height; _y++) {
            Grid::Cell cell = this->grid.getCell(_x, _y);
            this->parent->grid.setCell(_x + x_coord, _y + y_coord, cell);
        }
    }

    this->x = x_coord;
    this->y = y_coord;
}


Scene::Scene(int width, int height)
    : Entity(width, height) {}


void Scene::addSprite(Sprite &sprite) {
    sprite.setParent(this);
}


void Scene::show() {

    // \033[nA   -> Moves the cursor up n columns
    // \033[?25l -> Hides cursor

    std::cout << "\r\033[" + std::to_string(this->grid.height - 1) + "A\033[?25l";

    for (int y = this->grid.height - 1; y > -1; y--) {
        const char* str;
        for (int x = 0; x < this->grid.width; x++) {
            Grid::Cell cell = this->grid.getCell(x, y);
            str = ("\033[" + std::to_string(cell.color) + "m" + cell.data + "\033[0;0m").c_str();
            std::cout.write(str, sizeof (str));
        }

        if (y != 0)
            std::cout << '\n';
    }

    std::cout.flush();

}


void Sprite::move(int dx, int dy) {
    // FIXME: MAKE MORE EFFICIENT
    this->setPos(this->x + dx, this->y + dy);
}
