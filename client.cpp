//
// Created by Admin on 06/01/2023.
//
#include "client.h"
#include <iostream>
#include <ctime>
#include "exceptions.h"

Client::Client(int id, int varsta,  std::string nume, std::string prenume, unsigned long telefon,
               std::vector<std::shared_ptr<Masina>> cars) :
        id(id), varsta(varsta), nume(std::move(nume)), prenume(std::move(prenume)), telefon(telefon), cars(std::move(cars)) {
    std::cout << "Constructor initializare Client\n";
    if (varsta < 18) {
        throw(eroareClient(varsta));
    }
}

int Client::pretMasina() const {
    int pret_total = 0;
    for (auto &Masina: cars)
        pret_total += Masina->pret();
    return pret_total;
}

Client::Client(const Client &other) : id(other.id), varsta(other.varsta), nume(other.nume), prenume(other.prenume), telefon(other.telefon) {
    for (const auto &curs: other.cars)
        cars.emplace_back(curs->clone());
}

Client &Client::operator=(Client other) {
    swap(*this, other);
    return *this;
}

void swap(Client &st1, Client &st2) {
    std::swap(st1.cars, st2.cars);
    std::swap(st1.nume, st2.nume);
}

std::ostream &operator<<(std::ostream &os, const Client &c) {
    os <<"id client: " << c.id << "\n" << "nume client: " << c.nume << "\n" << "prenume client: " << c.prenume << "\n" << "varsta client: " << c.varsta << "\n" << "telefon client: " << c.telefon << "\n" << "\nmasini:\n";
    for (const auto &Masina: c.cars)
        os << *Masina;
    os << "\n";
    return os;
}
