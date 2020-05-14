#pragma once
#include <fstream>
#include "funcion.h"
#include "peliculas.h"
#include "salas.h"
#include <vector>
#include <fstream>
const string urlFunciones = "Funciones.txt";


class Funciones
{
private:
    vector<Funcion> funcions;
    vector<Pelicula> pelisC;
public:
    Funciones();
    vector<Funcion> getFuncions();
    bool newFuncion(Peliculas _peliculas, Salas _salas);
    bool actualizarArchivoFunciones();
    void listarFunciones();
    bool comprarFuncion();
    void sacarDeCartelera();
    void eliminarRepetidas();
    void monstrarPuestos(int i);
};
