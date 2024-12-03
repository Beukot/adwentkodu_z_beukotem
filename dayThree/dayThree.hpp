#pragma once
#include <vector>
#include <Windows.h>
#include <iostream>
#include <fstream>

#ifndef DAYTHREE_HPP
#define DAYTHREE_HPP

inline std::string readFile() {
    std::ifstream file("../dayThree/input.txt");
    std::string word;
    char c;

    while (file >> std::noskipws >> c) {
        word += c;
    }

    file.close();

    return word;
}

inline int checkSum(std::string& word) {
    int sum = 0;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'm' &&
            word[i + 1] == 'u' &&
            word[i + 2] == 'l' &&
            word[i + 3] == '(' &&
            (word[i + 4] >= 48 && word[i + 4] <= 57)) {
            std::string num1String;
            std::string num2String;

            int j = i + 4;
            while (word[j] >= 48 && word[j] <= 57) {
                num1String += word[j];
                j++;
            }

            if (word[j] == ',') {
                j++;
                while (word[j] >= 48 && word[j] <= 57) {
                    num2String += word[j];
                    j++;
                }

                if (word[j] == ')') {
                    int num1 = std::stoi(num1String);
                    int num2 = std::stoi(num2String);

                    sum += num1 * num2;

                    num1String = "";
                    num2String = "";
                }
            }
        }
    }

    return sum;
}

inline int checkSumDoDont(std::string& word) {
    int sum = 0;
    bool shouldDo = true;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'd' && word[i + 1] == 'o' && word[i + 2] == '(' && word[i + 3] == ')') {
            shouldDo = true;
        } else if (word[i] == 'd' &&
            word[i + 1] == 'o' &&
            word[i + 2] == 'n' &&
            word[i + 3] == 39 &&
            word[i + 4] == 't' &&
            word[i + 5] == '(' &&
            word[i + 6] == ')') {
            shouldDo = false;
        }

        if (word[i] == 'm' &&
            word[i + 1] == 'u' &&
            word[i + 2] == 'l' &&
            word[i + 3] == '(' &&
            (word[i + 4] >= 48 && word[i + 4] <= 57)) {
            std::string num1String;
            std::string num2String;

            int j = i + 4;
            while (word[j] >= 48 && word[j] <= 57) {
                num1String += word[j];
                j++;
            }

            if (word[j] == ',') {
                j++;
                while (word[j] >= 48 && word[j] <= 57) {
                    num2String += word[j];
                    j++;
                }

                if (word[j] == ')' && shouldDo) {
                    int num1 = std::stoi(num1String);
                    int num2 = std::stoi(num2String);

                    sum += num1 * num2;

                    num1String = "";
                    num2String = "";
                }
            }
        }
    }

    return sum;
}

inline void dayThreeMain() {
    std::string word = readFile();

    std::cout << "Część pierwsza zadania 3:" << std::endl;
    std::cout << "Suma z nieskorumpowanej pamięci: " << checkSum(word) << std::endl;
    std::cout << "Część druga zadania 3:" << std::endl;
    std::cout << "Suma z nieskorumpowanej pamięci z włączaniem i wyłączaniem: " << checkSumDoDont(word) << std::endl;
}

#endif //DAYTHREE_HPP
