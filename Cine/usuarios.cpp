#include "usuarios.h"



Usuarios::Usuarios()
{
    ListUsers.push_back(Usuario("admin","admin",true));
    ifstream Lectura;
    string User,admin,pass;
    bool _admin;
    Lectura.open(urlusers);
    if (!Lectura.fail()){
        while (!Lectura.eof()){
            getline(Lectura,User,',');
            getline(Lectura,pass, ',');
            getline(Lectura,admin);
            _admin = (admin== "1");
            Usuario J = Usuario(User,pass,_admin);
            ListUsers.push_back(J);

        }
        ListUsers.pop_back(); }
    Lectura.close(); //
}
bool Usuarios::Login(string Usuario, string Contrasena)
{
    int Aux = ListUsers.size();
    for (int i=0; i < Aux; i++){
        if (ListUsers[i].getUser()==Usuario){
            if (ListUsers[i].getPass()==Contrasena){
                return true;
            }

        }


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

    string user,pass;
    cout<<"Ingrese nombre de usuario: ";
    cin>>user;
    cout<<"Ingrese la contrasena: ";
    cin>>pass;


    if (ExisteUsu(user)){

        cout<<"El usuario ya existe. Intente nuevamente." <<endl;
        system("pause");

        return false;
    }
    Usuario Aux;
    Aux = Usuario(user, pass, false);
    ListUsers.push_back(Aux);
    ActualizarArchivo();
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
bool Usuarios::Eliminar()
{
    string Delete;
    int Posicion;  //Varible de referencia para la posición de usuario
    cout<<"Ingrese el usuario a eliminar: ";
    cin>>Delete;
    if (ExisteUsu(Delete)){
        Posicion = BuscarUsuario(Delete);
        ListUsers.erase(ListUsers.begin()+Posicion);
        cout<<"Usuario eliminado satisfactoriamente"<<endl;
        system("pause");
        return true;

    }
    cout<<"Usuario no existe"<<endl;
    system("pause");
    return false;
}
void Usuarios::ListaUsers()
{
    system("cls");
    int Aux = ListUsers.size();
    cout<<"Mostrando usuarios..."<<endl<<endl;
    for (int i=0; i < Aux; i++ ){
        cout<<ListUsers[i].getUser()<<endl;

    }
    system("pause");
}

bool Usuarios::ActualizarArchivo()
{
    ofstream Escritura; //Definimos la variable para escritura
    Escritura.open(urlusers); //Iniciamos la variable con la ubicación del archivp
    int n = ListUsers.size(); //Capturamos el tamaño de la lista de usuarios en una varible nq
    for (int i = 1;i < n; i++){
        Escritura<<ListUsers[i].getUser()<<"," //Guardamos en valor de la variable y lo agregamos el delimitador
                << ListUsers[i].getPass()<<","
                << ListUsers[i].getEsAdmin()<<endl; //Agregamos el salto de línea al final.
    }
    Escritura.close(); //Cerramos el archivo
    return true;
}













