#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

bool bisect(int an){
    return (((an % 4 == 0) && (an % 100 != 0)) || (an % 400 == 0));
}

bool validData(int z, int l, int y){
    if (l < 1 || l > 12)
        return 0;
    if (z < 1 || z > 31)
        return 0;

    if (l == 2)
    {
        if (bisect(y))
            return (z <= 29);
        else
            return (z <= 28);
    }

    if (l == 4 || l == 6 ||
        l == 9 || l == 11)
        return (z <= 30);

    return 1;
}

bool validViitor(int z, int l, int y){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if(y > (1900 + ltm->tm_year)) {
        return 1;
    }
    else if(y == (1900 + ltm->tm_year)) {
        if(l > 1 + ltm->tm_mon) {
            return 1;
        }
        else if(l == 1 + ltm->tm_mon) {
            if(z > ltm->tm_mday) {
                return 1;
            }
        }
    }
    return 0;
}

class Masina {
private:
    int id;
    std::string brand;
    std::string model;
    int an{};
public:
    Masina(int id_, const std::string& brand_, const std::string& model_, int an_) :id{id_}, brand{brand_}, model{model_}, an{an_} {
        std::cout << "Constr de initializare Masina\n";
    }

    Masina(const Masina& other) : id{other.id}, brand{other.brand}, model{other.model}, an{other.an} {
        std::cout << "Constr de copiere Masina\n";
    }

    /*
    const std::string& getBrand() const { return brand; }
    const std::string& getModel() const { return model; }
    int getAn() const { return an; }
    */
    Masina(){
        citire();
    }

    int getId() const { return id;}

    friend std::ostream& operator<<(std::ostream& os, const Masina& ma) {
        os << "Brand: " << ma.brand  << ", Model: " << ma.model << ", An: " << ma.an << "\n";
        return os;
    }

    ~Masina() {
        std::cout << "Destr Masina\n";
    }

    int validAn(){
        int anul;
        std::time_t t = std::time(nullptr);
        std::tm *const pTInfo = std::localtime(&t);
        while(1){
            std::cout<<"An: ";
            std::cin>>anul;
            if(anul >= 1970 && anul <= 1900 + pTInfo->tm_year)
                return anul;
        }
        return -1;
    }

    void citire(){
        std::cout<<"Masina cu ID: ";
        std::cin>>id;
        std::cout<<"Brand: ";
        std::cin>>brand;
        brand[0] = toupper(brand[0]);
        std::cout<<"Model: ";
        std::cin>>model;
        model[0] = toupper(model[0]);
        an = validAn();
    }
};

class Client {
private:
    int id;
    std::string nume;
    std::string prenume;
    unsigned long telefon;

public:

    Client(int id_, const std::string& nume_, const std::string& prenume_, unsigned long telefon_) : id{id_}, nume{nume_}, prenume{prenume_}, telefon{telefon_}{
        std::cout << "Constr de initializare Client\n";
    }

    Client(){
        citire();
    }

    friend std::ostream& operator<<(std::ostream& os, const Client& cl) {
        os << "Nume: " << cl.nume  << ", Prenume: " << cl.prenume << ", Telefon: " << cl.telefon << "\n";
        return os;
    }

    static int validTelefon(){
        std::string tel;
        while(1){
            std::cout<<"Telefon(07xxxxxxxx): ";
            std::cin>>tel;
            if (tel.find_first_not_of( "0123456789" ) == std::string::npos && tel.length() == 10){
                break;
            }
        }
        return -1;
    }


    void citire(){
        std::cout<<"Clientul cu ID: ";
        std::cin>>id;
        std::cout<<"Nume: ";
        std::cin>>nume;
        nume[0] = toupper(nume[0]);
        std::cout<<"Prenume: ";
        std::cin>>prenume;
        prenume[0] = toupper(prenume[0]);
        telefon = validTelefon();
    }

    int getId() const { return id;}



};

class Rezervare {
private:
    Masina masina;
    Client client;
    int zi;
    int luna;
    int an;
public:

    int creeareRezervare(int idm, int idc, int z, int l, int a){
        std::ifstream f("rezervare.txt");
        if(validData(z,l,a) && validViitor(z,l,a)) {
            std::string rezComplet = std::to_string(idm) + "," + std::to_string(idc) + "," + std::to_string(z) + "," +
                                     std::to_string(l) + "," + std::to_string(a);
            std::string line;
            while (std::getline(f, line)) {
                if (rezComplet.compare(line) == 0) {
                    std::cout << "Exista deja o rezervare\n";
                    f.close();
                    return -1;
                }
            }
            f.close();

            std::ofstream g("rezervare.txt", std::ios_base::app);
            g.seekp(0, std::ios_base::end);
            int length = g.tellp();
            g.seekp(length, std::ios_base::beg);
            g << "\n" << rezComplet;
            g.close();
            return 0;
        }
        std::cout<<"Data invalida\n";
        return -1;

    }

    void citire(){
        while(1) {
            std::cout << "zi: ";
            std::cin >> zi;
            std::cout << "luna: ";
            std::cin >> luna;
            std::cout << "an: ";
            std::cin >> an;
            if(validData(zi, luna, an) && validViitor(zi, luna, an))
                break;
        }
    }

    Rezervare(const Masina& masina_, const Client& client_, int zi_, int luna_, int an_) : masina{masina_}, client{client_},  zi{zi_}, luna{luna_}, an{an_}{
        creeareRezervare(masina.getId(), client.getId(), zi_, luna_, an_);
    }

    Rezervare(const Masina& masina_, const Client& client_): masina{masina_}, client{client_}{
        citire();
        creeareRezervare(masina.getId(), client.getId(), zi, luna, an);
    }

    friend std::ostream& operator<<(std::ostream& os, const Rezervare& re) {
        os << "ID Masina " << re.masina.getId() << ", ID Client " << re.client.getId() << ", Data " << re.zi << "/" << re.luna <<"/" << re.an <<"\n";
        return os;
    }

};

void afisareProg(){
    std::string line;
    std::ifstream f("rezervare.txt");
    while(!f.eof()){
        getline(f,line);
        std::cout << "" << line << "\n" ;
    }
    f.close();
}

int main() {

    /*Masina d1{1,"Dacia", "Logan", 2009};
    Masina d2{2,"Dacia", "Logan", 2009};
    Masina d3{3,"Dacia", "Logan", 2009};
    Client c1{1,"Popescu", "Andrei", 720222444};
    Rezervare r1{d3,c1,31,12,2022};
    Rezervare r2{d3,c1,29,11,2052};
    afisareProg();
    return 0;*/

    Masina m1{};
    Masina m2{};
    Client c1{};
    Client c2{};
    Rezervare r1{m1,c1};
    Rezervare r2{m2,c2};
    afisareProg();
}
