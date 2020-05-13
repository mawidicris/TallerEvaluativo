#ifndef PELICULA_H
#define PELICULA_H
#include <string>
#include <iostream>
using namespace std;

class Pelicula
{

private:
    int ID;
    string NameP;
    string Genero;
    int Duracion;
    string Clasi;
    bool Estreno;
public:
    Pelicula();
    Pelicula(int, string, string, int, string, bool _Estreno);
    int getID();
    string getNameP();
    string getGenero();
    int getDuracion();
    string getClasi();
    bool getEstreno();
    void setID(int);
    void setNameP(string);
    void setGenero(string);
    void setDuracion(int);
    void setClasi(string);
    void setEstreno(bool);



};

#endif // PELICULA_H
