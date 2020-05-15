/*Control de la logica de las películas*/

#ifndef PELICULAS_H
#define PELICULAS_H
#include "pelicula.h"
#include <vector>
#include <fstream>
const string urlmovies = "Peliculas.txt";

class Peliculas
{

private:
    vector<Pelicula> ListMovie;
public:
    Peliculas();
    vector<Pelicula> getListMovie(); //Retorna el vector de películas
    void ListarMovie(); //Lista de todas las películas
    void SeEstreno(); //Controlar si una película ya se entrenó
    void ListarProximo(); //Lista las películas a entrenarse proximamente
    bool NewMovie(); //Agregar una película nueva
    bool ActualizarPelicula(); //Escribir en el archivo Peliculas.txt


};

#endif // PELICULAS_H
