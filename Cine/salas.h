/*Logica de las salas para la proyección*/

#ifndef SALAS_H
#define SALAS_H
#include "sala.h"
#include <vector>
#include <string>

using namespace std;
class Salas
{

private:
    vector<Sala> salas;

public:
    Salas();
    vector<Sala> getSalas();
    void ListarSalas();

};

#endif // SALAS_H
