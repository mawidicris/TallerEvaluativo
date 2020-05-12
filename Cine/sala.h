#ifndef SALA_H
#define SALA_H
#include <string>

using namespace std;


class Sala
{

private:
    string Number;
    int Asientos;

public:
    Sala();
    Sala(string, int);
    string getNumber();
    int getAsientos();
    void setNumber(string);
    void setAsientos(int);
};

#endif // SALA_H
