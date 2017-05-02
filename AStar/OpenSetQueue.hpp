//
//  OpenSetQueue.hpp
//  AStar
//
//  Created by Sam Clark on 5/1/17.
//
//

#ifndef OpenSetQueue_hpp
#define OpenSetQueue_hpp

#include "Node.hpp"

class OpenSetQueue {
public:
    OpenSetQueue();
    void push(Node* node);
    Node* pop();
    Node* peek();
    bool isEmpty();
    bool contains(Tile* tile);
    
private:
    struct InternalNode {
        Node* node;
        InternalNode* next;
        
        InternalNode(Node* node) {
            this->node = node;
            this->next = nullptr;
        }
    };
    
    InternalNode* head;
    InternalNode* tail;
};

#endif /* OpenSetQueue_hpp */
