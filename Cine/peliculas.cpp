#include "peliculas.h"

Peliculas::Peliculas()
{
    Pelicula P = Pelicula(1,"Joker","Accion",220,"16+",true);
    Pelicula P1 = Pelicula(2,"Joker 2","Accion",120,"16+",false);
    ListMovie.push_back(P); ListMovie.push_back(P1);

}

void Peliculas::ListarMovie()
{
    string Estreno;
    int Aux = ListMovie.size();
    for (int i = 0; i < Aux; i++){

        Estreno = "Muy Pronto";
        if (ListMovie[i].getEstreno()){
            Estreno = "Ya se entreno";
        }
        cout<<ListMovie[i].getID()<<". "<<ListMovie[i].getNameP()<<": "<<Estreno<<endl;
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
    cin.ignore();
    getline(cin,genero);
    cout<<"Ingrese la duracion de la pelicula: ";
    cin>>duracion;
    cout<<"Ingrese la clasificacion de la pelicula: ";
    cin>>clasi;

    Id = ListMovie.size()+1;
    Pelicula Nueva;
    Nueva = Pelicula(Id,name,genero,duracion,clasi,false);
    ListMovie.push_back(Nueva);





}















