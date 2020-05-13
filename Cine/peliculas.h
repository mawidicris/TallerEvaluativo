#ifndef PELICULAS_H
#define PELICULAS_H
#include "pelicula.h"
#include <vector>

class Peliculas
{

private:
    vector<Pelicula> ListMovie;
public:
    Peliculas();
    vector<Pelicula> getListMovie();
    void ListarMovie();     // Para Admin.
    void ListarEstreno();   //Para el usuario
    void ListarProximo();
    bool NewMovie();
};

#endif // PELICULAS_H
