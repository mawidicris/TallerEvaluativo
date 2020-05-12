#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
using namespace std;


class Usuario

{
private:
    string User;
    string Pass;
    bool EsAdmin;

public:

    Usuario();
    Usuario(string, string, bool);
    string getUser();
    string getPass();
    bool getEsAdmin();
    void setUser(string);
    void setPass(string);
    void setEsAdmin(bool);

};

#endif // USUARIO_H
