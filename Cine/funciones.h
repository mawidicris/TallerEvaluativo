#pragma once
#include <fstream>
#include "funcion.h"
#include "peliculas.h"
#include "salas.h"
#include <vector>
#include <fstream>
#include "ventas.h"
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
    bool comprarFuncion(string _user,Ventas &Report);
    void sacarDeCartelera();
    void eliminarRepetidas();
    void monstrarPuestos(int i);
};
