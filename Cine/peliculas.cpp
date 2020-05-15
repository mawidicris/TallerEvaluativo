#include "peliculas.h"

Peliculas::Peliculas()
{
    ifstream Lectura;
    string id,name,genero,duracion,clasi,estreno;
    bool _estreno;
    int _id = 0,_duracion = -1;
    Lectura.open(urlmovies);
    if(!Lectura.fail()){
        while (!Lectura.eof()){
            getline(Lectura,id,',');
            getline(Lectura,name,',');
            getline(Lectura,genero,',');
            getline(Lectura,duracion,',');
            getline(Lectura,clasi,',');
            getline(Lectura,estreno);
            _estreno = (estreno == "1");
            if (id!=""){
                _id = stoi(id);
            }
            if (duracion!=""){
                _duracion = stoi(duracion);
            }
            Pelicula O = Pelicula(_id,name,genero,_duracion,clasi,_estreno);
            ListMovie.push_back(O);

        }
ListMovie.pop_back();

    }

    Lectura.close();
}

vector<Pelicula> Peliculas::getListMovie()
{
    return ListMovie;
}

void Peliculas::ListarMovie()
{

    int Aux = ListMovie.size();
    for (int i = 0; i < Aux; i++){
        cout<<ListMovie[i].getID()<<". "<<ListMovie[i].getNameP()<<endl;

    }


}

void Peliculas::SeEstreno()
{
    bool control;
    int seleccion;
    int n = ListMovie.size();
    control = true;
    if (n != 0) {
        while (control) {
            system("cls");
            cout << "Lista de peliculas: " << endl << endl;
            ListarMovie();
            cout << endl << "Seleccione pelicula a marcar como ya estrenada : ";
            cin >> seleccion;
            if (seleccion > 0 && seleccion <= n) {ListMovie[seleccion - 1].setEstreno(true);
                control = false;
                ActualizarPelicula();
            }
            else {
                system("cls");
                cout << "Valor invalido, intente nuevamente" << endl;
                system("pause");
            }

        }

    }
}

void Peliculas::ListarProximo()
{
    cout<<"Proximamente... Solo en cines!"<<endl<<endl;
    int Aux = ListMovie.size();
    for (int i = 0; i < Aux; i++){


        if (!ListMovie[i].getEstreno()){
            cout<<ListMovie[i].getNameP()<<endl;

        }

    }
    system("pause");
}

bool Peliculas::NewMovie()
{
    string name,genero,clasi;
    int duracion,Id;
    cout<<"Ingrese el nombre de la pelicula: ";
    cin.ignore();   //Ignorar el espacio en blanco
    getline(cin,name);  //Coger la línea completa
    cout<<"Ingrese el genero de la pelicula: ";
    getline(cin,genero);
    cout<<"Ingrese la duracion de la pelicula: ";
    cin>>duracion;
    cout<<"Ingrese la clasificacion de la pelicula: ";
    cin>>clasi;

    Id = ListMovie.size()+1;
    Pelicula Nueva;
    Nueva = Pelicula(Id,name,genero,duracion,clasi,false);
    ListMovie.push_back(Nueva);
    ActualizarPelicula();


    return true;


}

bool Peliculas::ActualizarPelicula()
{
    ofstream Escritura; //Definimos la variable para escritura
    Escritura.open(urlmovies); //Iniciamos la variable con la ubicación del archivp
    int n = ListMovie.size(); //Capturamos el tamaño de la lista de usuarios en una varible n

    system("pause");
    for (int i = 0;i < n; i++){
        Escritura<<ListMovie[i].getID()<<","
                <<ListMovie[i].getNameP()<<","
               <<ListMovie[i].getGenero()<<","
              <<ListMovie[i].getDuracion()<<","
             <<ListMovie[i].getClasi()<<","
            <<ListMovie[i].getEstreno()<<endl;



    }
    Escritura.close(); //Cerramos el archivo
    return true;

}















