//
// Created by ey025171 on 12/14/2023.
//

#include "Graph.h"
#include "Queue.h"

Graph::Graph(int vertexCount){
        edges = new EdgeList[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = EdgeList();
        }
    }

    void Graph::addEdge(int from, int to) {
        Edge* edge = new Edge(from, to, 1);
        edges[from].insert(edge);
    }

    void Graph::addEdge(int from, int to, int weight) {
        Edge* edge = new Edge(from, to, weight);
        edges[from].insert(edge);
    }

    Graph::~Graph() {
        delete[] edges;
    }

void Graph::breadthFirstSearch(bool *visited, int startNode) {
    Edge* edge;
    int fromNode, toNode;
    Queue queue = Queue();
    queue.enqueue(new Node(startNode));
    while (!queue.isEmpty()){
        fromNode = queue.dequeue()->getData();
        edge = edges[fromNode].getHead();
        while (edge != nullptr) {
            toNode = edge->getTo();
            if (!visited[toNode]){
                visited[toNode] = true;
                queue.enqueue(new Node(toNode));
            }
            edge = edge->getNext();
        }
    }
}

int Graph::connectedComponentsBfs(){
    int component = 0;
    bool* visited = new bool[vertexCount];
    for (int vertex = 0; vertex < vertexCount; vertex++){
        if (! visited [vertex]){
            visited [vertex] = true;
            breadthFirstSearch(visited, vertex );
            component++;
        }
    }
    return component;
}

