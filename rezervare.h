#ifndef OOP_REZERVARE_H
#define OOP_REZERVARE_H
#include <iostream>
#include "client.h"
#include "masina.h"
#include <ctime>

class Rezervare {
private:
    int zi;
    int luna;
    int an;
    std::vector<Client> clients;
public:
    explicit Rezervare(int zi, int luna, int an);
    void adauga(const Client &c);
    friend std::ostream &operator<<(std::ostream &os, const Rezervare &r);

};

#endif //OOP_REZERVARE_H
