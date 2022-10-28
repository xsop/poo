#include <string>
#include <iostream>


class Masina {
private:
    int id;
    static int unique_id;
    std::string brand;
    std::string model;
    int an;
public:
    Masina(const std::string& brand_, const std::string& model_, int an_) : brand{brand_}, model{model_}, an{an_} {
        std::cout << "Constr de initializare Masina\n";
        id = ++unique_id;
    }

    Masina(const Masina& other) : brand{other.brand}, model{other.model}, an{other.an} {
        std::cout << "Constr de copiere Masina\n";
        id = ++unique_id;
    }

    /*
    const std::string& getBrand() const { return brand; }
    const std::string& getModel() const { return model; }
    int getAn() const { return an; }
    */
    Masina(){
        id = ++unique_id;
    }

    int getId() const { return id;}

    friend std::ostream& operator<<(std::ostream& os, const Masina& ma) {
        os << "Brand: " << ma.brand  << ", Model: " << ma.model << ", An: " << ma.an << "\n";
        return os;
    }

    ~Masina() {
        std::cout << "Destr Masina\n";
    }
};

int Masina::unique_id = 0;

class Client {
private:
    int id;
    static int unique_id;
    std::string nume;
    std::string prenume;
    unsigned long telefon;

public:

    Client(const std::string& nume_, const std::string& prenume_, unsigned long telefon_) : nume{nume_}, prenume{prenume_}, telefon{telefon_}{
        std::cout << "Constr de initializare Client\n";
        id = ++unique_id;
    }

    friend std::ostream& operator<<(std::ostream& os, const Client& cl) {
        os << "Nume: " << cl.nume  << ", Prenume: " << cl.prenume << ", Telefon: " << cl.telefon << "\n";
        return os;
    }

    //int getId() const { return id;}

};

int Client::unique_id = 0;

class Rezervare {
private:
    int idMasina;
    int idClient;
    int zi;
    int luna;
    int an;
public:

    Rezervare(int idMasina_, int idClient_, int zi_, int luna_, int an_) : idMasina{idMasina_}, idClient{idClient_}, zi{zi_}, luna{luna_}, an{an_}{
        std::cout << "Constr de initializare Rezervare\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Rezervare& re) {
        os << "ID Masina " << re.idMasina << ", ID Client " << re.idClient << ", Data " << re.zi << "/" << re.luna <<"/" << re.an <<"\n";
        return os;
    }
};

int main() {

    Masina d1{"Dacia", "Logan", 2009};
    //Masina d2 = d1;
    //operator<<(std::cout, d1);
    std::cout << d1;
    std::cout << d1.getId() << "\n";

    Masina d2 = d1;

    std::cout << d2;
    std::cout << d2.getId() << "\n";

    Client c1{"Popescu", "Andrei", 720222444};
    std::cout << c1;

    Rezervare r1(2,1,28,10,2022);
    std::cout << r1;



    return 0;
}
