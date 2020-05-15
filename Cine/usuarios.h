/*Logica para el control de los usuarios*/

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
    bool Login(string Usuario, string Contrasena); //Control de inicio de sesion de los usuarios
    int  BuscarUsuario(string Ususu); //Busca un usuario por su username
    bool SeCreoOno(); //Controla la creación de nuevos usuarios
    bool ExisteUsu(string username); //Busca si hay uno repetido
    bool Eliminar(); //Eliminar usuarios en caso sea requerido
    void ListaUsers();
    bool ActualizarArchivo();  //Escribir sobre el archivo Usuarios.txt

};


#endif // USUARIOS_H
