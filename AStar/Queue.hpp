//
//  Queue.hpp
//  AStar
//
//  Created by Sam Clark on 5/1/17.
//
//

#ifndef Queue_hpp
#define Queue_hpp

template <typename T>
class Queue {
public:
    Queue();
    void push(T obj);
    T pop();
    T peek();
    bool isEmpty();
    bool exists(T obj);
    
private:
    template <typename R>
    struct Node {
        R data;
        Node<R>* next;
        
        Node(R data) {
            this->data = data;
            this->next = nullptr;
        }
    };
    
    Node<T>* head;
    Node<T>* tail;
};

template <typename T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void Queue<T>::push(T obj) {
    if (head == nullptr) {
        head = new Node<T>(obj);
        tail = head;
    } else {
        tail->next = new Node<T>(obj);
        tail = tail->next;
    }
}

template <typename T>
T Queue<T>::pop() {
    Node<T>* temp = head;
    if (temp == nullptr) {
        cout << "queue is empty" << endl;
    }
    head = head->next;
    return temp->data;
}

template <typename T>
T Queue<T>::peek() {
    if (head == nullptr) {
        cout << "queue is empty" << endl;
    }
    return head->data;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return ((head == nullptr) ? true : false);
}

template <typename T>
bool Queue<T>::exists(T obj) {
    Node<T>* currentNode = head;
    while (head != nullptr) {
        if (currentNode->data == obj) {
            return true;
        }
    }
    return false;
}





#endif /* Queue_hpp */
