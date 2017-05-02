//
//  OpenSetQueue.cpp
//  AStar
//
//  Created by Sam Clark on 5/1/17.
//
//

#include "OpenSetQueue.hpp"

OpenSetQueue::OpenSetQueue() {
    head = nullptr;
    tail = nullptr;
}

void OpenSetQueue::push(Node* node) {
    InternalNode* newNode = new InternalNode(node);
    if (isEmpty()) {
        head = newNode;
        tail = head;
    } else {
        InternalNode* current = head;
        while (node->fScore > current->node->fScore && current->next != nullptr) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
}

Node* OpenSetQueue::pop() {
    if (isEmpty()) {
        return nullptr;
    }
    InternalNode* temp = head;
    head = head->next;
    return temp->node;
}

Node* OpenSetQueue::peek() {
    if (isEmpty()) {
        return nullptr;
    }
    return head->node;
}

bool OpenSetQueue::isEmpty() {
    return ((head == nullptr) ? true : false);
}

bool OpenSetQueue::contains(Tile* tile) {
    InternalNode* current = head;
    while (current != nullptr) {
        if (current->node->tile == tile) {
            return true;
        }
        current = current->next;
    }
    return false;
}
