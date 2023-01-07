#include "exceptions.h"

eroareRezervare::eroareRezervare(int z, int l, int a) :
        eroare_aplicatie("Ziua " + std::to_string(z) + " sau luna " + std::to_string(l) + " sau anul " + std::to_string(a) + " este invalid/a") {}

eroareClient::eroareClient(int varsta) :
        eroare_aplicatie("Varsta clientului trebuie sa fie minim 18 ani, dar este " + std::to_string(varsta)) {}