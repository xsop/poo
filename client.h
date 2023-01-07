#ifndef OOP_CLIENT_H
#define OOP_CLIENT_H
#include <iostream>
#include <ctime>
#include <memory>
#include "masina.h"
#include <vector>

class Client {
private:
    int id;
    int varsta;
    std::string nume;
    std::string prenume;
    unsigned long telefon;
    std::vector<std::shared_ptr<Masina>> cars;

public:
    int pretMasina() const;
    Client(int id, int varsta,  std::string nume, std::string prenume, unsigned long telefon, std::vector<std::shared_ptr<Masina>> cars);
    Client(const Client &other);
    Client &operator=(Client other);
    friend void swap(Client &st1, Client &st2);
    friend std::ostream &operator<<(std::ostream &os, const Client &c);

};
#endif //OOP_CLIENT_H
