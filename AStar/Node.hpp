//
//  Node.hpp
//  AStar
//
//  Created by Sam Clark on 5/1/17.
//
//

#ifndef Node_hpp
#define Node_hpp

#include "Tile.hpp"

struct Node {
    Tile* tile;
    double gScore;
    double fScore;
    Node* cameFrom;
    
    Node(Tile* tile, double gScore, double fScore, Node* cameFrom) {
        this->tile = tile;
        this->gScore = gScore;
        this->fScore = fScore;
        this->cameFrom = cameFrom;
    }
};

#endif /* Node_hpp */
