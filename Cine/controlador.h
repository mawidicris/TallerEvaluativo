#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "usuarios.h"
#include "peliculas.h"
#include <salas.h>
#include <funciones.h>

class Controlador
{

private:
    Usuarios UserMas;
    Peliculas Movies;
    int QueUsuEs; //Variable auxiliar que guarda la posición del usuario actual.
    Salas sala;
    Funciones funcion;

public:

    Controlador();
    void OneMenu();
    void MenuAdmin();
    void MenuUsu();
    void MenuAdminUsu();
    void MenuAdminPeli();



};

#endif // CONTROLADOR_H
