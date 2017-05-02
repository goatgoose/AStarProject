//
//  AStar.cpp
//  AStar
//
//  Created by Sam Clark on 5/1/17.
//
//

#include "AStar.hpp"

void AStar::search(Tile* start, Tile* finish, AStarWindow* window) {
    unordered_map<Tile*, Node*> closedSet = unordered_map<Tile*, Node*>();
    OpenSetQueue openSet = OpenSetQueue();
    openSet.push(new Node(start, 0, window->getDistance(start, finish), nullptr));
    
    while (!openSet.isEmpty()) {
        Node* currentNode = openSet.pop();
        cout << currentNode->tile->getX() << ", " << currentNode->tile->getY() << endl;
        if (currentNode->tile == finish) {
            cout << "found" << endl;
        }
        
        closedSet.insert(pair<Tile*, Node*>(currentNode->tile, currentNode));
        vector<Tile*> neighbors = currentNode->tile->getNeighbors();
        for (int i = 0; i < neighbors.size(); i++) {
            Tile* neighbor = neighbors[i];
            cout << *neighbor << endl;
            if (closedSet.find(neighbor) != closedSet.end()) {
                int tentativeGScore = currentNode->gScore + 1;
                if (!openSet.contains(neighbor)) {
                    openSet.push(new Node(neighbor, tentativeGScore, tentativeGScore + window->getDistance(neighbor, finish), currentNode));
                }
            }
        }
        cout << openSet.peek()->tile->getX() << endl;
    }
}
