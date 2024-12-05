#pragma once
#include <vector>
#include <iostream>
#include <fstream>

#ifndef DAYFIVE_HPP
#define DAYFIVE_HPP

inline void readFile(std::vector<int>& arr) {
    std::ifstream file("../dayOne/input.txt");
    std::string word;

    while (file >> word) {
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == '|') {

            }
        }
    }

    file.close();
}

inline void dayFiveMain() {
    std::vector<int> rules;
}

#endif //DAYFIVE_HPP
