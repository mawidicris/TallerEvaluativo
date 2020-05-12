#include "usuario.h"

Usuario::Usuario()
{


}

Usuario::Usuario(string _User, string _Pass , bool _EsAdmin)
{
    User = _User;
    Pass = _Pass;
    EsAdmin = _EsAdmin;

}
string Usuario::getUser()
{
    return User;
}
string Usuario::getPass()
{
    return Pass;
}
bool Usuario::getEsAdmin()
{
    return EsAdmin;
}
void Usuario::setUser(string _User)
{
   User = _User;
}
void Usuario::setPass(string _Pass)
{
    Pass = _Pass;
}
void Usuario::setEsAdmin(bool _EsAdmin)
{
    EsAdmin = _EsAdmin;
}
