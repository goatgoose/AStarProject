//
//  AStar.hpp
//  AStar
//
//  Created by Sam Clark on 5/1/17.
//
//

#ifndef AStar_hpp
#define AStar_hpp

#include "AStarWindow.hpp"
#include "OpenSetQueue.hpp"
#include <unordered_map>

class AStar {
public:
    static void search(Tile* start, Tile* finish, AStarWindow* window);
    
private:
    static vector<Tile*> recontructPath(Node* finish);
};

#endif /* AStar_hpp */
