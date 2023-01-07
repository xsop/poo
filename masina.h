#ifndef OOP_MASINA_H
#define OOP_MASINA_H
#include <iostream>
#include <string>
#include <utility>
#include <memory>

class Masina {
public:
    virtual ~Masina() = default;
    virtual std::shared_ptr<Masina> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Masina &m) {
        os << "Id: " << m.id << ",  Brand: " << m.brand << ",  Model: " << m.model << ",  An: " << m.an << ",  Numar kilometri: " << m.km << " " << std::endl;
        return os;
    }

    explicit Masina(int an_, int km_, int id_, std::string brand_, std::string model_) :
    an(an_), km(km_), id(id_), brand(std::move(brand_)), model(std::move(model_)) {}

    int pret() { return pret_(); }
    //int getId() const;
    //void citire();

protected:
    Masina(const Masina &other) = default;
    Masina &operator=(const Masina &other) = default;
    int an, km;
private:
    int id;
    std::string brand;
    std::string model;
    virtual int pret_() const = 0;
};

#endif //OOP_MASINA_H
