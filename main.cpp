#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include "masina.h"
#include "MasinaSport.h"
#include "MasinaFamilie.h"
#include "client.h"
#include "rezervare.h"
#include "exceptions.h"

int main() {
    try {
        Client c1{1, 18, "marin", "george", 4034567890, {
                MasinaSport{2020, 45000, 1, "Suzuki", "Swift Sport", 1.4, 140}.clone(),
                MasinaSport{2014, 130000, 2, "Audi", "Q5", 2.0, 190}.clone(),
                MasinaFamilie{2022, 2000, 3, "Dacia", "Duster", 75, 5}.clone(),
        }};
        Client c2{2, 29, "gheorghe", "alexandru", 4076325938, {
                MasinaSport{2016, 64000, 1, "Skoda", "Sperb", 2.0, 220}.clone(),
                MasinaSport{2020, 32000, 2, "Volswagen", "Golf GTI", 2.0, 220}.clone(),
                MasinaSport{2018, 78000, 3, "Volswagen", "Touareg", 3.0, 250}.clone(),
                MasinaFamilie{2013, 145000, 4, "Toyota", "Corolla", 50, 4}.clone()
        }};
        Client c3{3, 17, "robert", "vlad", 076157335, {
                MasinaSport{2015, 99000, 1, "Audi", "Q7", 3.0, 270}.clone(),
                MasinaSport{2021, 10000, 2, "Renault", "Laguna", 2.0, 200}.clone(),
                MasinaFamilie{2017, 41000, 3, "Ford", "Ranger", 400, 6}.clone(),
        }};
        std::cout << c1 << "\n" << "Pretul masinii este: " << c1.pretMasina() << "\n";
        std::cout << c2 << "\n" << "Pretul masinii este: " << c2.pretMasina() << "\n";
        std::cout << c3 << "\n" << "Pretul masinii este: " << c3.pretMasina() << "\n";
        Rezervare r1{10, 4, 2022};
        r1.adauga(c1);
        r1.adauga(c2);
        r1.adauga(c3);
        std::cout << r1;
        Rezervare r2 = Rezervare{5, 12, 2023};
        r2.adauga(c2);
        std::cout << r2;
    } catch(eroareClient &err) {
        std::cout<<err.what()<<std::endl;
    } catch(eroareRezervare &err) {
        std::cout<<err.what()<<std::endl;
    }
}
