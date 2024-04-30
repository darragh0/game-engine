#pragma once


#include "grid.h"


class Entity {

    protected:
        Grid grid;
        Entity(int width, int height);

};


class Scene;


class Sprite : public Entity {

    protected:

        Scene* parent;
        int x = -1;
        int y = -1;

    public:

        Sprite(int width, int height, Scene* parent);
        Sprite(int width, int height);
        ~Sprite() = default;

        void setPos(int x_coord, int y_coord);
        void move(int dx, int dy);
        int getX() const;
        int getY() const;
        void setParent(Scene* scene);
        const Grid::Cell& getCell(int x_coord, int y_coord) const;
        void setCell(int x_coord, int y_coord, const Grid::Cell& cell) const;
        void setCell(int x_coord, int y_coord, char character) const;
        void setCell(int x_coord, int y_coord, Color color) const;
        void setCell(int x_coord, int y_coord, char character, Color color) const;
        void clearCell(int x_coord, int y_coord) const;

};


class Scene : public Entity {

    public:
        Scene(int width, int height);
        void show();
        void addSprite(Sprite& sprite);

        friend class Sprite;
};
