#include "masina.h"
#include <iostream>
#include <ctime>

/*int Masina::validAn() {
    int anul;
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
    while(1){
        std::cout<<"An: ";
        std::cin>>anul;
        if(anul >= 1970 && anul <= 1900 + pTInfo->tm_year)
            return anul;
    }
    return -1;
}

void Masina::citire() {
    std::cout<<"Masina cu ID: ";
    std::cin>>id;
    std::cout<<"Brand: ";
    std::cin>>brand;
    brand[0] = toupper(brand[0]);
    std::cout<<"Model: ";
    std::cin>>model;
    model[0] = toupper(model[0]);
    an = validAn();
}
*/
