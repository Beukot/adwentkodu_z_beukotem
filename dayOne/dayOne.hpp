#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

#ifndef DAYONE_HPP
#define DAYONE_HPP

inline void readFile(std::vector<int>* leftList, std::vector<int>* rightList) {
    std::ifstream file("../dayOne/input.txt");
    std::string word;
    int column = 0;

    while (file >> word) {
        int element = std::stoi(word);

        if (column == 1) {
            rightList->push_back(element);
            column = 0;
        } else {
            leftList->push_back(element);
            column++;
        }
    }

    file.close();
}

template <typename T>
void bubbleSort(T& arr, std::size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

inline void dayOneMain() {
    int sum = 0;
    std::vector<int> leftList, rightList;

    readFile(&leftList, &rightList);

    bubbleSort(leftList, leftList.size());
    bubbleSort(rightList, rightList.size());



    for (int i = 0; i < leftList.size(); i++) {
        sum += abs(leftList[i] - rightList[i]);
    }

    std::cout << "Rozwiązaniem zadania 1 jest: " << sum << "." << std::endl;
}

#endif //DAYONE_HPP
