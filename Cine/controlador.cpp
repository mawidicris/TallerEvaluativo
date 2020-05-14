#include "controlador.h"


Controlador::Controlador()
{
    UserMas = Usuarios();
    Movies = Peliculas();
    sala = Salas();
    funcion = Funciones();
}
void Controlador:: OneMenu()
{

    string Username, password;
    bool probar = false;
    do {
        system("cls");
        cout<<"Ingrese su usuario: ";
        cin>>Username;
        cout<<"Ingrese su contrasena: ";
        cin>>password;
        probar = UserMas.Login(Username,password);

        if (probar) //Llamado de la función del Login sin sus advertencias.
        {
            QueUsuEs = UserMas.BuscarUsuario(Username);
            Usuario temp;
            temp = UserMas.getListUsers()[QueUsuEs];
            if (temp.getEsAdmin()){
                MenuAdmin();
                probar = false; //Validación para repetir el menú
            }

            else {

                MenuUsu();
                probar = false;

            }

        }

        else{
            cout<<"Credenciales invalidos, intente nuevamente"<<endl;
            system("pause");
        }
    }
    while (!probar);
}
void Controlador:: MenuAdmin()
{
    bool correr = true;
    int control;

    while (correr){
        system("cls"); //Limpia la terminal.
        cout<<"Bienvenido al menu del Administrador"<<endl<<endl;

        cout<<"1. Control de Usuarios"<<endl
           << "2. Control de Peliculas"<<endl
           << "3. Cerrar caja"<<endl
           << "4. Cerrar Sesion"<<endl<<endl
           <<"Seleccione una opcion a continuacion: ";
        cin>>control;
        switch (control) {
        case 1:
            MenuAdminUsu();
            break;
        case 2:
            MenuAdminPeli();

            break;

        case 3:
            break;
        case 4:
            correr = false;
            QueUsuEs = -1; //Deshabitar el acceso del usuario actual.

            break;

        default:
            cout<<"Opción invalida. Intente nuevamente"<<endl;
            system("Pause");
            break;


        }


    }

}
void Controlador::MenuAdminUsu()
{
    bool correr = true;
    int control;
    while (correr) {
        system("cls"); //Limpia la terminal.
        cout<<"Control de Usuarios"<<endl<<endl;
        cout<<"1. Agregar Usuario"<<endl
           << "2. Eliminar Usuario"<<endl
           << "3. Lista de Usuarios"<<endl
           << "4. Volver al menu anterior"<<endl<<endl
           <<"Seleccione una opcion a continuacion: ";
        cin>>control;
        switch (control) {
        case 1:
            UserMas.SeCreoOno();

            break;
        case 2:

            UserMas.Eliminar();

            break;

        case 3:
            UserMas.ListaUsers();

            break;
        case 4:
            correr = false;

            break;

        default:
            cout<<"Opción invalida. Intente nuevamente"<<endl;
            system("Pause");
            break;


        }
    }

}
void Controlador::MenuUsu()
{
    bool correr = true;
    int control;
    while (correr) {
        system("cls"); //Limpia la terminal.
        cout<<"Control de Usuarios"<<endl<<endl;
        cout<<"1. Comprar boleteria"<<endl
           << "2. Cerrar sesion"<<endl<<endl

           <<"Seleccione una opcion a continuacion: ";
        cin>>control;
        switch (control) {
        case 1:
            break;
        case 2:

            correr = false;
            QueUsuEs = -1;
            break;

        default:
            cout<<"Opción invalida. Intente nuevamente"<<endl;
            system("Pause");
            break;

        }
    }

}
void Controlador::MenuAdminPeli()
{
    bool correr = true;
    int control;
    while (correr) {
        system("cls"); //Limpia la terminal.
        cout<<"Control de Peliculas"<<endl<<endl;
        cout<<"1.Agregar Pelicula"<<endl
           << "2.Agregar funcion"<<endl
           << "3. Ver funciones activas"<<endl<<endl

           <<"Seleccione una opcion a continuacion: ";
        cin>>control;
        switch (control) {
        case 1:
            Movies.NewMovie();

            break;
        case 2:

            funcion.newFuncion(Movies,sala);

            break;
        case 3:
            correr = false;

            break;


        default:
            cout<<"Opción invalida. Intente nuevamente"<<endl;
            system("Pause");
            break;

        }
    }
}







