#include <string>
#include <iostream>
#include <regex>
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
    static int unique_id;
    std::string brand;
    std::string model;
    int an{};
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
    int getStaticId() const { return unique_id;}

    friend std::ostream& operator<<(std::ostream& os, const Masina& ma) {
        os << "Brand: " << ma.brand  << ", Model: " << ma.model << ", An: " << ma.an << "\n";
        return os;
    }

    ~Masina() {
        std::cout << "Destr Masina\n";
    }

    int validAn(){
        int anul;
        time_t current_time;
        current_time = time(NULL);
        int a = 1970 + current_time / 31537970;
        while(1){
            std::cout<<"An: ";
            std::cin>>anul;
            if(anul >= 1970 && anul <= a)
                return anul;
        }
        return -1;
    }

    void citire(){
        std::cout<<"Masina cu ID: " << id << "\nBrand: ";
        std::cin>>brand;
        brand[0] = toupper(brand[0]);
        std::cout<<"Model: ";
        std::cin>>model;
        model[0] = toupper(model[0]);
        an = validAn();
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

    Client(){
        id = ++unique_id;
    }

    friend std::ostream& operator<<(std::ostream& os, const Client& cl) {
        os << "Nume: " << cl.nume  << ", Prenume: " << cl.prenume << ", Telefon: " << cl.telefon << "\n";
        return os;
    }

    int validTelefon(){
        int tel;
        while(1){
            std::cout<<"Telefon(fara prefix): ";
            std::cin>>tel;
            int tel2 = tel, nr = 0;
            while(tel2){
                nr++;
                tel2/=10;
            }
            if (nr == 9)
                return tel;
        }
        return -1;
    }

    int getStaticId() const { return unique_id;}

    void citire(){
        std::cout<<"Clientul cu ID: " << id << "\nNume: ";
        std::cin>>nume;
        nume[0] = toupper(nume[0]);
        std::cout<<"Prenume: ";
        std::cin>>prenume;
        prenume[0] = toupper(prenume[0]);
        telefon = validTelefon();
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

    int creeareRezervare(int idm, int idc, int z, int l, int a){
        std::ifstream f("../rezervare.txt");
        if(validData(z,l,a) && validViitor(z,l,a)) {
            std::string rezComplet = std::to_string(idm) + "," + std::to_string(idc) + "," + std::to_string(z) + "," +
                                     std::to_string(l) + "," + std::to_string(a);
            std::string line;
            while (std::getline(f, line)) {
                std::cout << line << '\n';
                if (rezComplet.compare(line) == 0) {
                    std::cout << "Exista deja o rezervare\n";
                    return -1;
                }
            }
            f.close();

            std::ofstream g("../rezervare.txt", std::ios_base::app);
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
        std::cout<<"ID Masina: ";
        std::cin>>idMasina;
        std::cout<<"ID Client: ";
        std::cin>>idClient;
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

    Rezervare(int idMasina_, int idClient_, int zi_, int luna_, int an_) : idMasina{idMasina_}, idClient{idClient_}, zi{zi_}, luna{luna_}, an{an_}{
        std::cout << "Constr de initializare Rezervare\n";
        if(creeareRezervare(idMasina, idClient, zi, luna, an) == -1){
            delete this;
        }
    }

    Rezervare(){
        citire();
        creeareRezervare(idMasina, idClient, zi, luna, an);
    }

    friend std::ostream& operator<<(std::ostream& os, const Rezervare& re) {
        os << "ID Masina " << re.idMasina << ", ID Client " << re.idClient << ", Data " << re.zi << "/" << re.luna <<"/" << re.an <<"\n";
        return os;
    }

};

int main() {

    Masina d1{"Dacia", "Logan", 2009};
    Masina d2{"Renault", "Zoe", 2021};
    std::cout << d1;
    std::cout << d2;
    //Masina d2;
    //d2.citire();
    //std::cout << d2;
    //std::cout << d2.getId() << "\n";

    Client c1{"Popescu", "Andrei", 720222444};
    Client c2{"Ionescu", "Vlad", 777777777};
    std::cout << c1;
    std::cout << c2;

    //c2.citire();
    //std::cout << c2;

    //Rezervare r1{2,1,30,10,2022};
    Rezervare r1;

    //std::cout << d1.getStaticId() << '\n';
    return 0;
}
