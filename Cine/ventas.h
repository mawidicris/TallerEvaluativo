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
    void GuardarVenta(venta _V);
    void ReporteVentas();
};

#endif // VENTAS_H
