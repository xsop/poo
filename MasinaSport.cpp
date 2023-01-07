#include "MasinaSport.h"

MasinaSport::MasinaSport(const int an, const int km, const int id, const std::string &brand, const std::string &model,
                         double motor, int hp) :
        Masina(an, km, id, brand, model), motor(motor), hp(hp) {
    std::cout << "Constructor initializare masina sport\n";
}

std::shared_ptr<Masina> MasinaSport::clone() const { return std::make_shared<MasinaSport>(*this); }

int MasinaSport::pret_() const {
    if (motor < 2 && hp < 150) {
        return (2023 - an) * km / 1000 - 200;
    } else {
        return (2023 - an) * km / 1000 - 200 + 10 * hp;
    }
}
