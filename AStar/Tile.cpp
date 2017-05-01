//
//  Tile.cpp
//  AStar
//
//  Created by Sam Clark on 4/29/17.
//
//

#include "Tile.hpp"
#include "AStarWindow.hpp"

Tile::Tile(int x, int y, AStarWindow* window) {
    this->x = x;
    this->y = y;
    this->window = window;
    
    background = new RectangleShape();
    window->addDrawable(background);
    
    unsetObsticle();
    update();
}

void Tile::update() {
    int tileSize = window->getScale();
    int xPosition = (x * window->getScale()) + (window->getBorderWidth() * x);
    int yPosition = (y * window->getScale()) + (window->getBorderWidth() * y);
    
    background->setSize(Vector2f(tileSize, tileSize));
    background->setPosition(Vector2f(xPosition, yPosition));
}

void Tile::setObsticle() {
    obsticle = true;
    background->setFillColor(Color(100,100,100));
}

void Tile::unsetObsticle() {
    obsticle = false;
    background->setFillColor(Color(255,255,255));
}

void Tile::setStart() {
    obsticle = false;
    background->setFillColor(Color(0,255,0));
}

void Tile::setFinish() {
    obsticle = false;
    background->setFillColor(Color(255,0,0));
}

bool Tile::isObsticle() {
    return obsticle;
}

Tile* Tile::getRelativeTile(int relativeX, int relativeY) {
    return window->getTile(x + relativeX, y + relativeY);
}








