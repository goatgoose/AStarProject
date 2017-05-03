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
    openSet.push(new Node(start, 0, window->getEuclideanDistance(start, finish), nullptr));
    
    int count = 1;
    while (!openSet.isEmpty()) {
        Node* currentNode = openSet.pop();
        
        window->addTimer(new Timer(count, [=] {
            currentNode->tile->setStart();
        }));
        count++;
        
        if (currentNode->tile == finish) {
            cout << "found" << endl;
            break;
        }
        
        closedSet.insert(pair<Tile*, Node*>(currentNode->tile, currentNode));
        vector<Tile*> neighbors = currentNode->tile->getNeighbors();
        for (int i = 0; i < neighbors.size(); i++) {
            Tile* neighbor = neighbors[i];
            if (closedSet.find(neighbor) == closedSet.end()) {
                int tentativeGScore = currentNode->gScore + 1;
                if (!openSet.contains(neighbor)) {
                    openSet.push(new Node(neighbor, tentativeGScore, tentativeGScore + window->getEuclideanDistance(neighbor, finish), currentNode));
                }
            }
        }
        
        cout << "current queue: " << endl;
        cout << openSet << endl;
    }
}
