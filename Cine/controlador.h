/*Clase maestra que controla todas las vistas y llama las funciones*/

#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "usuarios.h"
#include "peliculas.h"
#include "salas.h"
#include "funciones.h"
#include "ventas.h"

class Controlador
{

private:
    Usuarios UserMas;
    Peliculas Movies;
    int QueUsuEs;
    Salas sala;
    Funciones funcion;
    Ventas Reporte;

public:

    Controlador();
    /*Vistas para los difentes menús a usar*/
    void OneMenu(); //Vista inicial
    void MenuAdmin(); //Vista del administrador
    void MenuUsu(); //Vista de un usuario
    void MenuAdminUsu(); //Vista de control de usuarios
    void MenuAdminPeli(); //Vistas de control de películas.





};

#endif // CONTROLADOR_H
