#include "asientos.h"


Asientos::Asientos()
{

}
Asientos::Asientos(string _Tipo, int _Valor)
{
    Tipo = _Tipo;
    Valor = _Valor;
}
string Asientos::getTipo()
{
    return Tipo;
}
int Asientos::getValor()
{
    return Valor;
}
void Asientos::setTipo(string _Tipo)
{
    Tipo = _Tipo;
}
void Asientos::setValor(int _Valor)
{
    Valor = _Valor;
}
