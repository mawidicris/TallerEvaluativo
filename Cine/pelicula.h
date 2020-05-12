#ifndef PELICULA_H
#define PELICULA_H
#include <string>
using namespace std;

class Pelicula
{

private:
    int ID;
    string NameP;
    string Genero;
    int Duracion;
    string Clasi;
public:
    Pelicula();
    Pelicula(int,string, string, int, string);
    int getID();
    string getNameP();
    string getGenero();
    int getDuracion();
    string getClasi();
    void setID(int);
    void setNameP(string);
    void setGenero(string);
    void setDuracion(int);
    void setClasi(string);



};

#endif // PELICULA_H
