//
// Created by ey025171 on 12/14/2023.
//

#include "iostream"
#include "unordered_map"
#include <queue>


//MAIN METHOD IS IMPLEMENTED HERE
//MAXIMUM VERTEX COUNT IS 100 TO PREVENT STACK OVER FLOW ERROR

class Graph {
public:
    Graph(int vertexCount);

    void addWord(const std::string& word);
    void addEdge(const std::string& word1, const std::string& word2);

    void BFS(const std::string& startWord, const std::string& endWord);
    void Dijkstra(const std::string& startWord, const std::string& endWord);

private:
    int vertexCount;
    static const int Max_Vertices = 100;
    int adjacencyMatrix[Max_Vertices][Max_Vertices];
    std::unordered_map<std::string, int> wordToIndex;
    std::string indexToWord[Max_Vertices];

    int getWordIndex(const std::string& word);
    int* reconstructPath(int *previous, int endNode);
};

Graph::Graph(int vertexCount) : vertexCount(vertexCount){
    for(int i = 0; i < Max_Vertices; i++){
        for(int j = 0; j < Max_Vertices; j++){
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void Graph::addWord(const std::string &word) {
    int index = getWordIndex(word);
    if(index == -1){
        index = wordToIndex.size();
        wordToIndex[word] = index;
        indexToWord[index] = word;
    }
}

void Graph::addEdge(const std::string &word1, const std::string &word2) {
    int index1 = getWordIndex(word1);
    int index2 = getWordIndex(word2);

    if(index1 != -1 && index2 != -1){
        adjacencyMatrix[index1][index2] = 1;
        adjacencyMatrix[index2][index1] = 1;
    }
}

void Graph::Dijkstra(const std::string &startWord, const std::string &endWord) {
    int startIndex = getWordIndex(startWord);
    int endIndex = getWordIndex(endWord);

    if(startIndex == -1 || endIndex == -1){
        std::cout << "not found \n";
        return;
    }

    int distance[Max_Vertices];
    bool visited[Max_Vertices] = {false};
    int previous[Max_Vertices];
    for(int i = 0; i < Max_Vertices; i++){
        distance[i] = Max_Vertices + 1;
        previous[i] = -1;
    }

    distance[startIndex] = 0;

    for(int count = 0; count < vertexCount - 1; count++){
        int minDistance = Max_Vertices + 1;
        int minIndex = -1;

        for(int v = 0; v < vertexCount; v++){
            if(!visited[v] && distance[v] < minDistance){
                minDistance = distance[v];
                minIndex = v;
            }
        }

        if(minIndex == -1){
            break;
        }

        visited[minIndex] = true;

        for(int n = 0; n < vertexCount; n++){
            if(!visited[n] && adjacencyMatrix[minIndex][n] && distance[minIndex] + 1 < distance[n]){
                distance[n] = distance[minIndex] + 1;
                previous[n] = minIndex;
            }
        }
    }

    if(distance[endIndex] != Max_Vertices + 1){
        int* path = reconstructPath(previous, endIndex);

        std::cout << "shortest path: ";
        for(int i = 0; path[i] != -1; i++){
            std::cout << indexToWord[path[i]] << " ";
        }

        std::cout << "\n";
        delete[] path;
    }else{
        std::cout << "not path found \n";
    }
}

void Graph::BFS(const std::string &startWord, const std::string &endWord) {
    int startIndex = getWordIndex(startWord);
    int endIndex = getWordIndex(endWord);

    if(startIndex == -1 || endIndex == -1){
        std::cout << "not found \n";
        return;
    }

    bool visited[Max_Vertices] = {false};
    std::queue<int> q;

    int previous [Max_Vertices];
    for(int i = 0; i < Max_Vertices; i++){
        previous[i] = -1;
    }

    visited[startIndex] = true;
    q.push(startIndex);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int n = 0; n < vertexCount; n++){
            if(adjacencyMatrix[current][n] == 1 && !visited[n]){
                visited[n] = true;
                q.push(n);
                previous[n] =current;

                if(n == endIndex){
                    int* path = reconstructPath(previous, endIndex);

                    std::cout << "shortest path: ";
                    for(int i = 0; path[i] != -1; i++){
                        std::cout << indexToWord[path[i]] << " ";
                    }
                    std::cout << "\n";
                    delete[] path;
                    return;
                }
            }
        }
    }
    std::cout << "not found \n";
}

int Graph::getWordIndex(const std::string &word) {
    auto a = wordToIndex.find(word);
    if(a != wordToIndex.end()){
        return a->second;
    }
    return  -1;
}

int* Graph::reconstructPath(int *previous, int endNode) {
    int* path = new int[Max_Vertices];
    int current = endNode;
    int index = 0;

    while(current != -1){
        path[index++] = current;
        current = previous[current];
    }

    path[index] = -1;
    return path;
}


int main() {
    // ------------------------------------
    // DO THE NECESSARY CHANGES ACCORDING TO YOUR IMPLEMENTATION
    // ------------------------------------
    // Test Case: Adding Edges with One-Letter Difference (3 letter words)
    Graph graph3(4);
    graph3.addWord("cat");
    graph3.addWord("cot");
    graph3.addWord("cog");
    graph3.addWord("dog");
    graph3.addEdge("cat", "cot");
    graph3.addEdge("cot", "cog");
    graph3.addEdge("cog","dog");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (3 letter words)\n";
    std::cout << "Shortest Path from 'dog' to 'cat' (BFS):\n";
    graph3.BFS("cat", "dog");
    std::cout << "Shortest Path from 'dog' to 'cat' (Dijkstra):\n";
    graph3.Dijkstra("cat", "dog");
    std::cout << "------------------------------------------\n";

    // Test Case: Adding Edges with One-Letter Difference (4 letter words)
    Graph graph4(3);
    graph4.addWord("dark");
    graph4.addWord("bark");
    graph4.addWord("barn");
    graph4.addEdge("dark", "bark");
    graph4.addEdge("bark", "barn");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (4 letter words)\n";
    std::cout << "Shortest Path from 'barn' to 'dark' (BFS):\n";
    graph4.BFS("dark", "barn");
    std::cout << "Shortest Path from 'barn' to 'dark' (Dijkstra):\n";
    graph4.Dijkstra("dark", "barn");
    std::cout << "------------------------------------------\n";

    // Test Case: Adding Edges with One-Letter Difference (5 letter words)
    Graph graph5(3);
    graph5.addWord("stone");
    graph5.addWord("store");
    graph5.addWord("score");
    graph5.addEdge("stone", "store");
    graph5.addEdge("store", "score");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (5 letter words)\n";
    std::cout << "Shortest Path from 'score' to 'stone' (BFS):\n";
    graph5.BFS("stone", "score");
    std::cout << "Shortest Path from 'score' to 'stone' (Dijkstra):\n";
    graph5.Dijkstra("stone", "score");
    std::cout << "------------------------------------------\n";

    return 0;
}
