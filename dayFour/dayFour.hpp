#pragma once
#include <vector>
#include <Windows.h>
#include <iostream>
#include <fstream>

#ifndef DAYFOUR_HPP
#define DAYFOUR_HPP

inline void readFile(std::vector<std::string>& arr) {
    std::ifstream file("../dayFour/input.txt");
    std::string line;

    while (file >> line) {
        arr.push_back(line);
    }

    file.close();
}

inline int searchForWord(std::vector<std::string>& arr) {
    int occured = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 'X') {
                if (arr[i][j + 1] == 'M') {
                    if (arr[i][j + 2] == 'A' && arr[i][j + 3] == 'S') {
                        occured++;
                    }
                }
                if (arr[i][j - 1] == 'M') {
                    if (arr[i][j - 2] == 'A' && arr[i][j - 3] == 'S') {
                        occured++;
                    }
                }
                if (arr[i + 1][j] == 'M' && i + 3 < arr.size()) {
                    if (arr[i + 2][j] == 'A' && arr[i + 3][j] == 'S') {
                        occured++;
                    }
                }
                if (arr[i - 1][j] == 'M' && i - 3 >= 0) {
                    if (arr[i - 2][j] == 'A' && arr[i - 3][j] == 'S') {
                        occured++;
                    }
                }
            }
        }
    }

    return occured;
}

inline void dayFourMain() {
    std::vector<std::string> lines;
    readFile(lines);

    std::cout << searchForWord(lines) << std::endl;
}

#endif //DAYFOUR_HPP
