//
//  AStarWindow.cpp
//  AStar
//
//  Created by Sam Clark on 4/29/17.
//
//

#include "AStarWindow.hpp"

AStarWindow::AStarWindow(int gridSize, int scale, int borderWidth): BaseWindow((scale * gridSize) + (gridSize * borderWidth), (scale * gridSize) + (gridSize * borderWidth), "A* Window") {
        
    this->gridSize = gridSize;
    this->scale = scale;
    this->borderWidth = borderWidth;
    
    background->setFillColor(Color(0,0,0));
    
    resetTiles();
}

void AStarWindow::resetTiles() {
    tiles.clear();
    for (int x = 0; x < gridSize; x++) {
        tiles.push_back(vector<Tile*>());
        for (int y = 0; y < gridSize; y++) {
            tiles[x].push_back(new Tile(x, y, this));
        }
    }
    getStart()->setStart();
    getFinish()->setFinish();
}

void AStarWindow::distributeObsticles(int distributionPercent) {
    srand(time(nullptr));
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            if (rand() % 100 < distributionPercent) {
                tiles[x][y]->setObsticle();
            }
        }
    }
    getStart()->setStart();
    getFinish()->setFinish();
}

Tile* AStarWindow::getTile(int x, int y) {
    if (x < 0 || x > gridSize - 1 ||
        y < 0 || y > gridSize - 1) {
        return nullptr;
    } else {
        return tiles[x][y];
    }
}

int AStarWindow::getDistance(Tile* tile1, Tile* tile2) {
    int xRemainder = abs(tile1->getX() - tile2->getX());
    int yRemainder = abs(tile1->getY() - tile2->getY());
    return ((xRemainder > yRemainder) ? xRemainder : yRemainder);
}

void AStarWindow::updateTiles() {
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            tiles[x][y]->update();
        }
    }
}

void AStarWindow::resizeEvent(Event event) {
    int lowerDimension = ((event.size.width > event.size.height) ? event.size.height : event.size.width);
    scale = (lowerDimension - gridSize * borderWidth) / gridSize;
    updateTiles();
}

int AStarWindow::getScale() {
    return scale;
}

int AStarWindow::getGridSize() {
    return gridSize;
}

int AStarWindow::getBorderWidth() {
    return borderWidth;
}

Tile* AStarWindow::getStart() {
    return tiles[0][gridSize - 1];
}

Tile* AStarWindow::getFinish() {
    return tiles[gridSize - 1][0];
}

















