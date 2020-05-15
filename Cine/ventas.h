/*Logica y control de la ventas en el día */

#ifndef VENTAS_H
#define VENTAS_H
#include "venta.h"
#include <vector>

class Ventas
{
private:
    vector<venta> V;
public:
    Ventas();
    vector<venta> getV() const;
    void setV(const vector<venta> value);
    void GuardarVenta(venta _V); //Escribir sobre el archivo Repote.txt
    void ReporteVentas(); //Calcula el total de ventas y genera un reporte al administrador
};

#endif // VENTAS_H
