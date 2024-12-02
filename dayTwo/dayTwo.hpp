#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

#ifndef DAYTWO_HPP
#define DAYTWO_HPP

inline bool determineSafety(std::vector<int> arr) {
    int diff = 0;

    for (int i = 0; i < arr.size() - 1; i++) {
        diff = abs(arr[i] - arr[i + 1]);

        std::cout << arr[i] << "-" << arr[i + 1] << " diff: " << diff << "\t";

        if (diff < 1 || diff > 3) {
            return false;
        }
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
            std::cout << line[i] << " ";
            if (line[i] != ' ' && line[i] != '\n') {
                word += line[i];
            } else {
                levels.push_back(std::stoi(word));
                word = "";
            }
        }

        std::cout << std::endl;

        for (int i = 0; i < levels.size(); i++) {
            std::cout << levels[i] << "\t";
        }

        std::cout << std::endl;

        if (determineSafety(levels)) {
            safeReports++;
        }
        std::cout << "\n";

        word = "";
        line = "";
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
