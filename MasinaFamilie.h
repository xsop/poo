#ifndef OOP_MASINAFAMILIE_H
#define OOP_MASINAFAMILIE_H
#include "masina.h"

class MasinaFamilie : public Masina {

public:
    explicit MasinaFamilie(
            const int an, const int km, const int id, const std::string &brand, const std::string &model, int capacitate_portbagaj = 70, int nr_locuri = 6);

    std::shared_ptr<Masina> clone() const override;

private:
    int pret_() const override;
    int capacitate_portbagaj = 0;
    int nr_locuri = 0;
};



#endif //OOP_MASINAFAMILIE_H
