//
// Created by ey025171 on 12/14/2023.
//
#include <iostream>
#include <fstream>

using namespace std;
int main() {
    string line;
    ifstream file("filePath/dict.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    }
    return 0;
}
