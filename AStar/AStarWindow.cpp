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
}

void AStarWindow::distributeObsticles(int distributionPercent) {
    srand(time(nullptr));
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            if (rand() % 100 <= distributionPercent) {
                tiles[x][y]->setObsticle();
            }
        }
    }
    getStart()->unsetObsticle();
    getFinish()->unsetObsticle();
}

Tile* AStarWindow::getTile(int x, int y) {
    if (x < 0 || x > gridSize ||
        y < 0 || y > gridSize) {
        return nullptr;
    } else {
        return tiles[x][y];
    }
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

















