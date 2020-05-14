#ifndef USUARIOS_H
#define USUARIOS_H
#include "usuario.h"
#include <vector>
#include <fstream>
const string urlusers = "Usuarios.txt";

class Usuarios
{


private:
    vector<Usuario> ListUsers;
public:
    Usuarios();
    vector<Usuario> getListUsers();
    void setListUser(vector<Usuario> _ListUsers);
    bool Login(string Usuario, string Contrasena);
    int  BuscarUsuario(string Ususu);
    bool SeCreoOno();
    bool ExisteUsu(string username);
    bool Eliminar();
    void ListaUsers();
    bool ActualizarArchivo();

};


#endif // USUARIOS_H
