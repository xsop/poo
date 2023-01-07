#include "MasinaFamilie.h"

MasinaFamilie::MasinaFamilie(const int an, const int km, const int id, const std::string &brand,
                             const std::string &model, int capacitate_portbagaj, int nr_locuri) :
        Masina(an, km, id, brand, model), capacitate_portbagaj(capacitate_portbagaj), nr_locuri(nr_locuri) {
    std::cout << "Constructor initializare masina de familie\n";

}

std::shared_ptr<Masina> MasinaFamilie::clone() const { return std::make_shared<MasinaFamilie>(*this); }

int MasinaFamilie::pret_() const {
    if (capacitate_portbagaj < 50 && nr_locuri < 4) {
        return (2023 - an) * km / 1000 - 500;
    } else {
        return (2023 - an) * km / 1000 - 200 + nr_locuri * 50 + capacitate_portbagaj * 10;
    }
}
