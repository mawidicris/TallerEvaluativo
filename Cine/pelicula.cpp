#include "pelicula.h"

Pelicula::Pelicula()
{

}
Pelicula::Pelicula(int _ID, string _NameP, string _Genero, int _Duracion, string _Clasi)
{
    ID = _ID;
    NameP = _NameP;
    Genero = _Genero;
    Duracion = _Duracion;
    Clasi = _Clasi;

}
int Pelicula::getID()
{
    return ID;
}
string Pelicula::getNameP()
{
    return NameP;
}
string Pelicula::getGenero()
{
    return Genero;
}
int Pelicula::getDuracion()
{
    return Duracion;
}
string Pelicula::getClasi()
{
    return Clasi;
}
void Pelicula::setID(int _ID)
{
   ID = _ID;
}
void Pelicula::setNameP(string _NameP)
{
    NameP = _NameP;
}
void Pelicula::setGenero(string _Genero)
{
    Genero = _Genero;
}
void Pelicula::setDuracion(int _Duracion)
{
    Duracion = _Duracion;
}
void Pelicula::setClasi(string _Clasi)
{
    Clasi = _Clasi;
}
