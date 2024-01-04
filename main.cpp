//
// Created by ey025171 on 12/14/2023.
//
#include <iostream>
#include <fstream>
#include "Graph.h"

//static bool isOneLetterApart(std::string word1, std::string word2);

/*int main() {
    std::ifstream inputFile("C:/Users/TEMP.OZUN/Desktop/dict.txt");
    if(!inputFile.is_open())
        std::cerr << "Error opening file!"<< std::endl;
    int wordCount3 = 0;
    int wordCount4 = 0;
    int wordCount5 = 0;
    std::string word;
    while(inputFile >> word){
        if(word.length() == 3)
            wordCount3++;
        if(word.length() == 4)
            wordCount4++;
        if(word.length() == 5)
            wordCount5++;
    }
    inputFile.close();

    Graph* graph3 = new Graph(wordCount3);
    Graph* graph4 = new Graph(wordCount4);
    Graph* graph5 = new Graph(wordCount5);

    std::ifstream read("C:/Users/TEMP.OZUN/Desktop/dict.txt");
    if(!read.is_open())
        std::cerr << "Error opening file!"<< std::endl;

    int size = wordCount3+wordCount4+wordCount5;
    std::string s_array[size];
    int i = 0;
    while(read >> word && i < size){
        s_array[i] = word;
        ++i;
    }
    read.close();
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(isOneLetterApart(s_array[i],s_array[j])){
                if(s_array[i].length() == 3)
                    graph3->addEdge(i,j);
                else if(s_array[i].length() == 4)
                    graph3->addEdge(i,j);
                else if(s_array[i].length() == 5)
                    graph3->addEdge(i,j);
            }
        }
    }
}

static bool isOneLetterApart(std::string word1, std::string word2){
    int differences = 0;

    if(word1.length() != word2.length())
        return false;

    for(int i = 0; i < word1.length();++i){
        if(word1[i] != word2[i])
            ++differences;
    }
    return differences == 1;
}
*/
