#include "sala.h"


int Sala::getColumnas() const
{
    return Columnas;
}

void Sala::setColumnas(int value)
{
    Columnas = value;
}

bool Sala::getVibra() const
{
    return vibra;
}

void Sala::setVibra(bool value)
{
    vibra = value;
}

int Sala::getFilas() const
{
    return filas;
}

void Sala::setFilas(int value)
{
    filas = value;
}

Sala::Sala()
{

}

Sala::Sala(int Numero, int colum, bool sound, int fil)
{
    Number = Numero;
    Columnas = colum;
    vibra = sound;
    filas = fil;
}

int Sala::getNumber() const
{
    return Number;
}

void Sala::setNumber(int value)
{
    Number = value;
}
