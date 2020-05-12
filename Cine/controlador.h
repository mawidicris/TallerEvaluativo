#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "usuarios.h"

class Controlador
{

private:
    Usuarios UserMas;
    int QueUsuEs; //Variable auxiliar que guarda la posición del usuario actual.
public:

    Controlador();
    void OneMenu();
    void MenuAdmin();
    void MenuUsu();
    void MenuAdminUsu();
};

#endif // CONTROLADOR_H
