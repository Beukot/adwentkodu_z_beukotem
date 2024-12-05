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

inline bool checkBounds(std::vector<std::string>& arr, int X, int Y) {
    if (X >= 0 && Y >= 0 && X < arr.size() && Y < arr[0].size()) {
        return true;
    }

    return false;
}

inline bool checkCharRecursive(std::vector<std::string>& arr, std::string word, int startX, int startY, int dirX, int dirY, int index) {
    if (!checkBounds(arr, startX + dirX, startY + dirY))  {
        return false;
    }

    if (index == word.size()) {
        return true;
    }

    if (word[index] == arr[startX + dirX][startY + dirY]) {
        startX += dirX;
        startY += dirY;
        index += 1;

        return checkCharRecursive(arr, word, startX, startY, dirX, dirY, index);
    }

    return false;
}

inline int searchForWord(std::vector<std::string>& arr) {
    int occured = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == 'X') {
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (l != 0 && k != 0) {
                            if (checkCharRecursive(arr, "MAS", i, j, k, l, 0)) {
                                occured++;
                            }
                        }
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
    std::string word = "XMAS";

    std::cout << searchForWord(lines) << std::endl;
}

#endif //DAYFOUR_HPP
