#include "venta.h"

string venta::getUsuario() const
{
    return Usuario;
}

void venta::setUsuario(const string &value)
{
    Usuario = value;
}

string venta::getProducto() const
{
    return Producto;
}

void venta::setProducto(const string &value)
{
    Producto = value;
}

int venta::getTotal() const
{
    return total;
}

void venta::setTotal(int value)
{
    total = value;
}

venta::venta()
{



}

venta::venta(string _Usuario, string _Producto, int _total)
{
    Usuario = _Usuario;
    Producto = _Producto;
    total = _total;

}
