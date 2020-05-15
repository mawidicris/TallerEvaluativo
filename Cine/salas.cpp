#include "salas.h"

vector<Sala> Salas::getSalas()
{
    return salas;
}

void Salas::ListarSalas()
{
    int n = salas.size();
    string Conv;
    for (int i = 0; i < n; ++i) {
        Conv = "Sala General";
        if (salas[i].getVibra()){
            Conv = "Sala Vibrosound ";
        }
        cout<<salas[i].getNumber()<<". Sala "<<salas[i].getNumber()<<" Capacidad: "<<salas[i].getFilas()*salas[i].getColumnas()<<" Personas "<<Conv<<endl;
    }
}



Salas::Salas()
{
    Sala S1,S2,S3,S4;
    S1 = Sala(1,14,false,10);
    S2 = Sala(2,10,true,5);
    S3 = Sala(3,14,false,5);
    S4 = Sala(4,10,true,5);
    salas.push_back(S1); salas.push_back(S2); salas.push_back(S3); salas.push_back(S4);
}
