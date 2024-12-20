#include <iostream>
#include <fstream>
#include <windows.h>

#include "dayFive/dayFive.hpp"
#include "dayFour/dayFour.hpp"
#include "dayOne/dayOne.hpp"
#include "dayThree/dayThree.hpp"
#include "dayTwo/dayTwo.hpp"

int main() {
    SetConsoleOutputCP( 65001 );

    int day;

    std::cout << "Hoł hoł hoł! Do którego dnia z kalendarza adwentowego potrzebujesz odpowiedzi?" << std::endl;
    std::cin >> day;

    switch (day) {
        case 1:
            dayOneMain();
            break;
        case 2:
            dayTwoMain();
            break;
        case 3:
            dayThreeMain();
            break;
        case 4:
            dayFourMain();
            break;
        case 5:
            dayFiveMain();
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        case 16:
            break;
        case 17:
            break;
        case 18:
            break;
        case 19:
            break;
        case 20:
            break;
        case 21:
            break;
        case 22:
            break;
        case 23:
            break;
        case 24:
            break;
        case 25:
            break;
        default:
            std::cout << "Coś nie pykło..." << std::endl;
            break;
    }
}