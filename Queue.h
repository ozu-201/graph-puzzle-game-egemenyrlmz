//
// Created by ey025171 on 12/21/2023.
//

#ifndef GRAPH_PUZZLE_GAME_EGEMENYRLMZ_QUEUE_H
#define GRAPH_PUZZLE_GAME_EGEMENYRLMZ_QUEUE_H

#include "Node.h"

class Queue {
private:
    Node* first;
    Node* last;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    Node* dequeue();
    void enqueue(Node* newNode);
};


#endif //GRAPH_PUZZLE_GAME_EGEMENYRLMZ_QUEUE_H
