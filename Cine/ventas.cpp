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
    ofstream Escritura; //Definimos la variable para escritura
    Escritura.open(urlventas); //Iniciamos la variable con la ubicación del archivp
    V.push_back(_V);
    int n = V.size(); //Capturamos el tamaño de la lista de usuarios en una varible nq
    for (int i = 1;i < n; i++){
        Escritura<<V[i].getUsuario()<<"," //Guardamos en valor de la variable y lo agregamos el delimitador
                << V[i].getProducto()<<","
                << V[i].getTotal()<<endl; //Agregamos el salto de línea al final.
    }
    Escritura.close(); //Cerramos el archivo

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
   // V.pop_back();
    }
    Lectura.close();
}
