#include "rezervare.h"
#include <fstream>
#include "exceptions.h"

Rezervare::Rezervare(int zi, int luna, int an) : zi(zi), luna(luna), an(an) {
    std::cout << "Constructor initializare rezervare\n";
    if (zi < 0 || zi > 31) {
        throw(eroareRezervare(zi, luna, an));
    } else if (luna < 0 || luna > 12) {
        throw(eroareRezervare(zi, luna, an));
    } else if (an < 1990 || an > 2023) {
        throw(eroareRezervare(zi, luna, an));
    }
}

void Rezervare::adauga(const Client &c) { clients.push_back(c); }

std::ostream &operator<<(std::ostream &os, const Rezervare &r) {
    os << "data rezervare: " << r.zi << "." << r.luna << "." << r.an << "." << "\nclienti:\n";
    for (const auto &Client: r.clients)
        os << Client;
    os << "\n";
    return os;
}
