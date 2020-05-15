

#ifndef ASIENTOS_H
#define ASIENTOS_H
#include <string>

using namespace std;


class Asientos
{

private:
    string Tipo;
    int Valor;
public:
    Asientos();
    Asientos(string,int);
    string getTipo();
    int getValor();
    void setTipo(string);
    void setValor(int);

};

#endif // ASIENTOS_H
