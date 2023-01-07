#ifndef OOP_MASINASPORT_H
#define OOP_MASINASPORT_H
#include "masina.h"
#include <memory>
#include <utility>
#include <vector>

class MasinaSport : public Masina {

public:
    explicit MasinaSport(
            const int an, const int km, const int id, const std::string &brand, const std::string &model, double motor = 2, int hp = 500);

    std::shared_ptr<Masina> clone() const override;

private:
    int pret_() const override;
    double motor = 0;
    int hp = 0;
};


#endif //OOP_MASINASPORT_H
