//
// Created by ey025171 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_EGEMENYRLMZ_GRAPH_H
#define GRAPH_PUZZLE_GAME_EGEMENYRLMZ_GRAPH_H


//#include <rpcndr.h>
#include "EdgeList.h"


    class Graph{
    private:
        int vertexCount;
        EdgeList *edges;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void breadthFirstSearch(bool* visited, int startNode);
        int connectedComponentsBfs();
    };




#endif //GRAPH_PUZZLE_GAME_EGEMENYRLMZ_GRAPH_H
