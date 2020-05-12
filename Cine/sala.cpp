#include "sala.h"

Sala::Sala()
{

}
Sala::Sala(string _Number,  int _Asientos)
{
    Number = _Number;
    Asientos = _Asientos;
}
string Sala::getNumber()
{
    return Number;
}
int Sala::getAsientos()
{
    return Asientos;
}
void Sala::setNumber(string _Number)
{
    Number = _Number;
}
