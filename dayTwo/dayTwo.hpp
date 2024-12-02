#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

#ifndef DAYTWO_HPP
#define DAYTWO_HPP

inline bool determineSafety(std::vector<int> arr) {
    int diff = 0;
    bool increasing = false;
    bool decreasing = false;

    for (int i = 0; i < arr.size() - 1; i++) {
        diff = abs(arr[i] - arr[i + 1]);

        if  (arr[i] < arr[i + 1]) {
            increasing = true;
        }

        if (arr[i] > arr[i + 1]) {
            decreasing = true;
        }

        if (arr[i] == arr[i + 1]) {
            return false;
        }

        if (diff < 1 || diff > 3) {
            return false;
        }
    }

    if (increasing && decreasing) {
        return false;
    }

    return true;
}

inline int readFile() {
    std::ifstream file("../dayTwo/input.txt");
    std::string word;
    std::string line;
    std::vector<int> levels;

    int safeReports = 0;

    while (std::getline(file, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ' && line[i] != '\n') {
                word += line[i];
            } else {
                levels.push_back(std::stoi(word));
                word = "";
            }
        }

        levels.push_back(std::stoi(word));
        word = "";
        line = "";

        if (determineSafety(levels)) {
            safeReports++;
        }

        levels.clear();
    }

    file.close();

    return safeReports;
}

inline void dayTwoMain() {
    int res = readFile();

    std::cout << "Część pierwsza zadania 2:" << std::endl;
    std::cout << "Bezpiecznych raportów: " << res << std::endl;
}

#endif //DAYTWO_HPP
