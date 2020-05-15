#include "ventas.h"
#include <fstream>
#include <iostream>

using namespace  std;

const string urlventas = "Resumen.txt";
vector<venta> Ventas::getV() const
{
    return V;
}

void Ventas::setV(const vector<venta> value)
{
    V = value;
}

void Ventas::GuardarVenta(venta _V)
{
    ofstream Escritura;
    Escritura.open(urlventas);
    V.push_back(_V);
    int n = V.size();
    for (int i = 0;i < n; i++){
        Escritura<<V[i].getUsuario()<<","
                << V[i].getProducto()<<","
                << V[i].getTotal()<<endl;
    }
    Escritura.close();

}

void Ventas::ReporteVentas()
{
    int total = 0;
    int n = V.size();
    for (int i = 0; i < n; i++){
        cout<<V[i].getUsuario()<<" "<<V[i].getProducto()<<" "<<V[i].getTotal()<<endl;
        total = total + V[i].getTotal();
    }

    cout<<"Total ventas: "<<total<<endl;
}

Ventas::Ventas()
{

    ifstream Lectura;
    string User,producto,valor;
   int _valor=-1;
    Lectura.open(urlventas);
    if (!Lectura.fail()){
    while (!Lectura.eof()){
        getline(Lectura,User,',');
        getline(Lectura,producto, ',');
        getline(Lectura,valor); //
       if (valor != ""){_valor=stoi(valor);}
       venta _v = venta(User,producto,_valor);
       V.push_back(_v);
    }
   V.pop_back();
    }
    Lectura.close();
}
