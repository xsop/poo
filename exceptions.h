#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H
#include <stdexcept>
#include <string>

class eroare_aplicatie : public std::runtime_error { using std::runtime_error::runtime_error; };

class eroareRezervare: public eroare_aplicatie {
public:
    explicit eroareRezervare(int z, int l, int a);
};

class eroareClient: public eroare_aplicatie{
public:
    explicit eroareClient(int varsta);
};


#endif //OOP_EXCEPTIONS_H
