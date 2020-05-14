#include "funcion.h"


vector<vector<char> > Funcion::getSillas() const
{
    return Sillas;
}

void Funcion::setSillas(const vector<vector<char> > value)
{
    Sillas = value;
}

void Funcion::llenarsillas()
{
    int fil, col;
    fil = Salla.getFilas();
    col = Salla.getColumnas();
    int medio;
    const int aCol = col;
    medio = col / 2;

    for (int i = 0; i < fil; i++) {
        vector<char> fila;
        for (int c = 0; c < col; c++) {


            if (i + 1 > fil / 5 && i + 1 < fil) {
                fila.push_back(signosSilla[0]);
            }
            else {
                if (col % 2 == 0 && (c == medio || c == medio - 1)) {
                    fila.push_back(signosSilla[1]);
                }
                else if (c == medio) {
                    fila.push_back(signosSilla[1]);
                }
                else {
                    fila.push_back(signosSilla[0]);
                }
            }
        }
        Sillas.push_back(fila);
    }
}

Funcion::Funcion()
{

}

Funcion::Funcion(int _id, string _hora, Sala _salla, Pelicula _Movie, int _Disponible, bool _TVideo)
{
    id = _id;
    hora = _hora;
    Salla = _salla;
    Movie = _Movie;
    Disponible = _Disponible;
    TVideo = _TVideo;
    llenarsillas();


}

Funcion::Funcion(int _id, string _hora, Sala _salla, Pelicula _Movie, int _Disponible, vector<vector<char> > _Sillas, bool _TVideo)
{
    id = _id;
    hora = _hora;
    Salla = _salla;
    Movie = _Movie;
    Disponible = _Disponible;
    TVideo = _TVideo;
    Sillas = _Sillas;
}



string Funcion::getHora()
{
    return hora;
}

void Funcion::setHora(string value)
{
    hora = value;
}

Sala Funcion::getSalla()
{
    return Salla;
}

void Funcion::setSalla(Sala value)
{
    Salla = value;
}

Pelicula Funcion::getMovie()
{
    return Movie;
}

void Funcion::setMovie(Pelicula value)
{
    Movie = value;
}

int Funcion::getDisponible()
{
    return Disponible;
}

void Funcion::setDisponible(int value)
{
    Disponible = value;
}

bool Funcion::getTVideo()
{
    return TVideo;
}

void Funcion::setTVideo(bool value)
{
    TVideo = value;
}

int Funcion::getId()
{
    return id;
}

void Funcion::setId(int value)
{
    id = value;
}
