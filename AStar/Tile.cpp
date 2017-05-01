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
    
    int tileSize = window->getScale();
    int xPosition = (x * window->getScale()) + (window->getBorderWidth() * x);
    int yPosition = (y * window->getScale()) + (window->getBorderWidth() * y);
    
    background = new RectangleShape();
    background->setSize(Vector2f(tileSize, tileSize));
    background->setPosition(Vector2f(xPosition, yPosition));
    window->addDrawable(background);
    
    unsetObsticle();
}

void Tile::update() {
    
}

void Tile::setObsticle() {
    obsticle = true;
    background->setFillColor(Color(100,100,100));
}

void Tile::unsetObsticle() {
    obsticle = false;
    background->setFillColor(Color(255,255,255));
}

bool Tile::isObsticle() {
    return obsticle;
}

Tile* Tile::getRelativeTile(int relativeX, int relativeY) {
    return window->getTile(x + relativeX, y + relativeY);
}








