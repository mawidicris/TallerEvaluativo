#ifndef SALA_H
#define SALA_H
#include <string>
#include <iostream>
using namespace std;


class Sala
{

private:
    int Number;
    int Columnas;
    bool vibra;
    int filas;



public:
    Sala();

    Sala(int Numero, int colum, bool sound, int fil);
    int getNumber() const;
    void setNumber(int value);
    int getColumnas() const;
    void setColumnas(int value);
    bool getVibra() const;
    void setVibra(bool value);
    int getFilas() const;
    void setFilas(int value);

};

#endif // SALA_H
