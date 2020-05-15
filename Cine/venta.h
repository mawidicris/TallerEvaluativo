#ifndef VENTA_H
#define VENTA_H
#include <string>

using namespace  std;

class venta
{

private:
    string Usuario,Producto;
    int total;

public:
    venta();
    venta(string _Usuario,string _Producto, int _total);
    string getUsuario() const;
    void setUsuario(const string &value);
    string getProducto() const;
    void setProducto(const string &value);
    int getTotal() const;
    void setTotal(int value);
};

#endif // VENTA_H
