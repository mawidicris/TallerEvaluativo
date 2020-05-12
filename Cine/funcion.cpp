#include "funcion.h"

Funcion::Funcion()
{

}
Funcion::Funcion(Sala, Pelicula, int _Disponible, string _TVideo)
{
    Disponible = _Disponible;
    TVideo = _TVideo;
}
int Funcion:: getDisponible()
{
    return Disponible;
}
string Funcion::getTVideo()
{
    return TVideo;
}
void Funcion:: setDisponible(int _Disponible)
{
    Disponible = _Disponible;
}
void Funcion:: setTVideo(string _TVideo)
{
    TVideo = _TVideo;
}
