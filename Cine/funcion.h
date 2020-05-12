#ifndef FUNCION_H
#define FUNCION_H
#include <string>
#include "pelicula.h"
#include "sala.h"
using namespace std;


class Funcion
{

private:
    Sala Salla;
    Pelicula Movie;
    int Disponible;
    string TVideo;
public:
    Funcion();
    Funcion(Sala, Pelicula, int, string);
    Sala getSalla();
    Pelicula getMovie();
    int getDisponible();
    string getTVideo();
    void setDisponible(int);
    void setTVideo(string);

};

#endif // FUNCION_H
