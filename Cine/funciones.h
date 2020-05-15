/*Logica para controlar la función*/

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

    bool newFuncion(Peliculas _peliculas, Salas _salas); //Se encarga de crear una nueva proyección
    bool actualizarArchivoFunciones(); //Escribe en el archivo Funciones.txt
    void listarFunciones(); //Listar en un vector todas las funciones
    bool comprarFuncion(string _user,Ventas &Report); //Metodo que se encarga de la venta de funciones
    void sacarDeCartelera(); //Hacer que una película salga de cartelera
    void monstrarPuestos(int i); //Para mostrar organizados los puestos en la terminal
};
