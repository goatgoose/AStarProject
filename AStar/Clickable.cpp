//
//  Clickable.cpp
//  AStar
//
//  Created by Sam Clark on 4/29/17.
//
//

#include "Clickable.hpp"
#include "BaseWindow.hpp"

Clickable::Clickable(BaseWindow* window) {
    this->window = window;
    this->window->addClickable(this);
}

Clickable::~Clickable() {
    this->window->removeClickable(this);
}

bool Clickable::isInBounds(int x, int y) {
    return (x > getX1() &&
            x < getX2() &&
            y > getY1() &&
            y < getY2());
}

void Clickable::pressEvent() {
    
}

void Clickable::releaseEvent() {
    
}

void Clickable::hoverEvent() {
    
}

void Clickable::unhoverEvent() {
    
}
