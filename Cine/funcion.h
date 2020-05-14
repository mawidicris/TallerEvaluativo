#ifndef FUNCION_H
#define FUNCION_H
#include <string>
#include "pelicula.h"
#include "sala.h"
#include <vector>
const vector<char> letras = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
const vector<char> signosSilla = { '#','$','@' };


using namespace std;


class Funcion
{

private:
    int id;
    string hora;
    Sala Salla;
    Pelicula Movie;
    int Disponible;
    vector<vector<char>> Sillas;
    bool TVideo;
public:
    Funcion();
    Funcion(int _id, string _hora, Sala _salla, Pelicula _Movie, int _Disponible, bool _TVideo);
    Funcion(int _id, string _hora, Sala _salla, Pelicula _Movie, int _Disponible,vector<vector<char>> _Sillas, bool _TVideo);

    int getId();
    void setId(int value);
    string getHora();
    void setHora( string value);
    Sala getSalla();
    void setSalla(Sala value);
    Pelicula getMovie();
    void setMovie(Pelicula value);
    int getDisponible();
    void setDisponible(int value);
    bool getTVideo();
    void setTVideo(bool value);
    vector<vector<char> > getSillas() const;
    void setSillas(const vector<vector<char> > value);
    void llenarsillas();
};

#endif // FUNCION_H
