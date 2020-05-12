#include "usuarios.h"



Usuarios::Usuarios()
{
    ListUsers.push_back(Usuario("qqq","1234",true));
}
bool Usuarios::Login(string Usuario, string Contrasena)
{
    for (int i=0; i < 3; i++){
        if (ListUsers[i].getUser()==Usuario){
            if (ListUsers[i].getPass()==Contrasena){
                return true;
            }
            return false;
        }
        return  false;

    }
    return false;
}
int Usuarios::BuscarUsuario(string Ususu)
{
    int Aux; //Variable auxiliar.
    Aux = ListUsers.size();
    for (int i = 0; i < Aux; i++){
        if (ListUsers[i].getUser() == Ususu){
            return i;
        }
    }
    cout<<"El Usuario no existe, Intente nuevamente."<<endl;
    system("pause"); //Pausa para dar tiempo al usuario de leer el mensaje.
    return -1;
}
vector<Usuario> Usuarios::getListUsers()
{
    return ListUsers;
}
bool Usuarios::SeCreoOno()
{
    /*cin.ignore();
    getline(cin,VariableDondeSeGuarda);*/
    string user,pass;
    cout<<"Ingrese nombre de usuario: ";
    cin>>user;
    cout<<"Ingrese la contrasena: ";
    cin>>pass;
    cout<<"jjj"<<endl;

    if (ExisteUsu(user)){

        cout<<"El usuario ya existe. Intente nuevamente." <<endl;
        system("pause");

        return false;
    }
    Usuario Aux;
    Aux = Usuario(user, pass, false);
    ListUsers.push_back(Aux);
    return true;
}
bool Usuarios::ExisteUsu(string username)
{
    int Aux; //Variable auxiliar.
    Aux = ListUsers.size();
    for (int i = 0; i < Aux; i++){
        if (ListUsers[i].getUser() == username){
            return true;
        }
    }

    return false;
}








