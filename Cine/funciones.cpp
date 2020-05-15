#include "funciones.h"

Funciones::Funciones()
{
    ifstream BD_Funciones;
    string id,hora,Disponible,sillas,TVideo,idp,namep,genero,duracion,clasi,estreno,number,columna,vibra,filas;
    int _id,_duracion,_idp,_number,_columna,_filas,_Disponible;
    bool _Tvideo,_estreno,_vibra;
    string sillla;
    BD_Funciones.open(urlFunciones);
    if (!BD_Funciones.fail()) {
        //leoo el archivo
        while (!BD_Funciones.eof()) {
            getline(BD_Funciones, id, ',');
            getline(BD_Funciones, hora, ',');
            getline(BD_Funciones, TVideo, ',');
            getline(BD_Funciones, idp, ',');
            getline(BD_Funciones, namep, ',');
            getline(BD_Funciones, genero, ',');
            getline(BD_Funciones, duracion, ',');
            getline(BD_Funciones, clasi, ',');
            getline(BD_Funciones, estreno, ',');
            getline(BD_Funciones, number, ',');
            getline(BD_Funciones, columna, ',');
            getline(BD_Funciones, vibra, ',');
            getline(BD_Funciones, filas, ',');
            if (id!= "") {	_id=stoi(id);}
            if (duracion!= "") {_duracion=stoi(duracion);}
            if (idp!= "") {_idp=stoi(idp);}
            if (number!= "") {_number=stoi(number);}
            if (columna!= "") {_columna = stoi(columna);}
            if (filas!= "") {_filas=stoi(filas);}
            _Tvideo = (TVideo == "1");
            _estreno = (estreno == "-1");
            _vibra = (estreno == "-1");
            Pelicula P = Pelicula(_idp,namep,genero,_duracion,clasi,_estreno);
            Sala S = Sala(_id,_columna,_vibra,_filas);
            vector<vector<char>> A;
            for(int i=0;i<_filas;i++){
                vector<char> B;
                for (int c = 0; c < _columna; c++){
                    getline(BD_Funciones, sillla, ',');
                    B.push_back(sillla.at(0));
                }
                A.push_back(B);
            }
            getline(BD_Funciones, Disponible);//obtengo la cantidad de puestos de la funcion
            if (Disponible != "") {_Disponible = stoi(Disponible); }
            Funcion F = Funcion(_id,hora,S,P,_Disponible,A,_Tvideo);
            funcions.push_back(F);
        }
        funcions.pop_back();
    }
    BD_Funciones.close();
}


vector<Funcion> Funciones::getFuncions()
{
    return vector<Funcion>();
}
bool Funciones::newFuncion(Peliculas _peliculas,Salas _salas)
{
    Pelicula pel;
    Sala ssala;
    Funcion f;
    int _ID,n,seleccion,nSillas;
    _ID = funcions.size() + 1;
    bool control,_Tvideo;
    string hora;
    n = _peliculas.getListMovie().size();
    control = true;
    if (n != 0){
        while (control) {
            system("cls");
            cout << "Lista de peliculas: " << endl << endl;
            _peliculas.ListarMovie();
            cout <<endl<< "Selecciones pelicula para la funcion: ";
            cin >> seleccion;
            if (seleccion > 0 && seleccion <=n){
                pel = _peliculas.getListMovie()[seleccion - 1];
                control = false;
            }
            else {
                system("cls");
                cout << "Valor invalido, intente nuevamente" << endl;
                system("pause");
            }
            cout << "Ingrese hora de la funcion: ";
            cin >> hora;
            control = true;
            //while que controla el listado y seleccion de salas
            while (control) {
                system("cls");
                cout << "Lista de salas: " << endl << endl;
                _salas.ListarSalas();
                cout <<endl<< "Selecciones sala para la funcion: ";
                cin >> seleccion;
                n = _salas.getSalas().size();
                if (seleccion > 0 && seleccion <= n) {
                    ssala = _salas.getSalas()[seleccion - 1];
                    nSillas = ssala.getFilas()*ssala.getColumnas();
                    control = false;


                }
                else {
                    system("cls");
                    cout << "Valor invalido, intente nuevamente" << endl;
                    system("pause");
                }
            }
            control = true;
            //while para confirmar si es 2d o 3d
            while (control) {
                system("cls");
                cout << "La funcion es en 3D?" << endl<<endl;
                cout << "1. SI." << endl << "2. NO." << endl<<endl;
                cout << "Selecciones: ";
                cin >> seleccion;
                switch (seleccion)
                {
                case 1:
                    _Tvideo = true;
                    control = false;
                    break;
                case 2:
                    _Tvideo = false;
                    control = false;
                    break;
                default:
                    system("cls");
                    cout << "Valor invalido, intente nuevamente"<<endl;
                    system("pause");
                    break;
                }
            }
            control = true;
            //while para confirmar la creación o cancelar la creacion
            while(control){
                system("cls");
                cout << "Informacion: " << endl<<endl
                     << "Pelicula: " << pel.getNameP() << endl
                     << "Hora " << hora << endl
                     << "sala: " << ssala.getNumber() << endl;
                if (_Tvideo) {
                    cout << "Funcion en 3D" << endl;
                }
                else {
                    cout << "Funcion en 2D" << endl<<endl;
                }
                cout <<endl<< "Confirmar funcion" << endl<<endl;
                cout << "1. SI." << endl << "2. NO.(Cancelar)" << endl<<endl;
                cout << "Selecciones: ";
                cin >> seleccion;
                switch (seleccion)
                {
                case 1:
                    control = false;
                    break;
                case 2:
                    system("cls");
                    cout << "Se a cancelado la creacion de funcion" << endl;
                    system("pause");
                    return false;
                    break;
                default:
                    system("cls");
                    cout << "Valor invalido, intente nuevamente" << endl;
                    system("pause");
                    break;
                }
            }

            f = Funcion(_ID,hora,ssala,pel,nSillas,_Tvideo);
            funcions.push_back(f);
            actualizarArchivoFunciones();
            system("cls");
            cout << "Se creo la funcion correctamente" << endl;
            system("pause");
            return true;
        }
    }

    else {
        //por si no existen peliculas en la base de datos
        system("cls");
        cout << "Actualmente no dispone de ninguna pelicula" << endl;
        system("pause");
    }
    return false;
}

bool Funciones::actualizarArchivoFunciones()
{
    ofstream BD_Funciones;
    int filas, columnas;
    Sala salaAux;
    BD_Funciones.open(urlFunciones);
    int n= funcions.size();
    for (int i =0; i<n;i++){
        salaAux = funcions[i].getSalla();
        BD_Funciones << funcions[i].getId() << ","
                     << funcions[i].getHora() << ","
                     << funcions[i].getTVideo() << ","
                     << funcions[i].getMovie().getID() << ","
                     << funcions[i].getMovie().getNameP() << ","
                     << funcions[i].getMovie().getGenero() << ","
                     << funcions[i].getMovie().getDuracion() << ","
                     << funcions[i].getMovie().getClasi() << ","
                     << funcions[i].getMovie().getEstreno() << ","
                     << funcions[i].getSalla().getNumber() << ","
                     << funcions[i].getSalla().getColumnas() << ","
                     << funcions[i].getSalla().getVibra() << ","
                     << funcions[i].getSalla().getFilas() << ",";
        filas = salaAux.getFilas();
        columnas = salaAux.getColumnas();
        for (int f = 0; f < filas ; f++) {
            for (int c = 0; c < columnas; c++){
                BD_Funciones<<funcions[i].getSillas()[f][c]<<",";
            }

        }
        BD_Funciones<<funcions[i].getDisponible()<<endl;
    }
    BD_Funciones.close();
    return true;
}

bool Funciones::comprarFuncion(string _user, Ventas &Report)
{
    int n = funcions.size();
        char fila;
        int columna, _fila;
        int filas, columnas;
        int seleccion, valorFuncion, ValorPuesto, ValorSala;

        bool control = true;
        while (control) {

            cout << "Lista de funciones actuales" << endl << endl;
            for (int i = 0; i < n; i++) {

                cout << i + 1 << ". Pelicula: " << funcions[i].getMovie().getNameP()
                    << " Genero: " << funcions[i].getMovie().getGenero()
                    << " Duracion: " << funcions[i].getMovie().getDuracion() << " min "
                    << " Sala: " << funcions[i].getSalla().getNumber()
                    << " Hora: " << funcions[i].getHora()
                    << " Asientos disponibles: " << funcions[i].getDisponible()
                    << " Clas: " << funcions[i].getMovie().getClasi();
                string vibrosound = "Sala normal";
                string f3d = "2D";
                if (funcions[i].getSalla().getVibra()) {
                    vibrosound = "Sala con vibroSound";
                }
                if (funcions[i].getTVideo()) {
                    f3d = "3D";
                }
                cout << " Tipo funcion " << vibrosound << " - " << f3d << endl;
            }
            cout << "Seleccione: ";
            cin >> seleccion;
            if (seleccion > 0 && seleccion <= n) {
                control = false;
            }
            else {
                cout << "Valor invalido" << endl;
                system("pause");
            }


        }
        filas = funcions[seleccion-1].getSalla().getFilas();
        columnas = funcions[seleccion-1].getSalla().getColumnas();
        control = true;
        //Control de la seleccion de puesto , aqui se muestran los puestos de la funcion
        while (control) {
            monstrarPuestos(seleccion - 1);
            cout << endl << "Donde se quiere ubicar" << endl;
            cout << "Fila: ";
            cin >> fila;
            cout << "Columna: ";
            cin >> columna;
            //este for me transforma el valor del char de la silla a un numero
            for (int c = 0; c < letras.size(); c++) {
                if (letras[c] == fila) {
                    _fila = c + 1;
                }
            }
            cout<<seleccion<<endl;
            char silla = funcions[seleccion - 1].getSillas()[filas - _fila][columnas - columna];
cout<<silla<<endl;
            if (signosSilla[0] == silla) {
                ValorPuesto = 9900;
                control = false;
            }
            else if (signosSilla[1] == silla) {
                ValorPuesto = 7000;
                control = false;
            }

            else if (signosSilla[2] == silla) {
                cout << "El puesto ya esta ocupado, seleccione otro" << endl;
                system("pause");
            }
            else {
                cout << "Seleccion invalida vuelva a intentar." << endl;
                system("pause");
            }

        }

        //aqui valido los precios para la venta dependiendo de la sala y funcion
            if (funcions[seleccion - 1].getTVideo()) {
                valorFuncion = 2000;
            }
            else { valorFuncion = 0; }
            if (funcions[seleccion - 1].getSalla().getVibra()) {
                ValorSala = 2900;
            }
            else { ValorSala = 1800; }
            control = true;
            //control para confirmacion , muestro la compra y pido confirmacion
            while (control) {
                int s;
                venta V;
                system("cls");
                cout << "Informacion de compra: " << endl << endl;
                cout << "Pelicula: " << funcions[seleccion - 1].getMovie().getNameP()<<endl
                    <<"Sala: "<< funcions[seleccion - 1].getSalla().getNumber()<<endl
                    <<"Hora: "<< funcions[seleccion - 1].getHora()<<endl
                    <<"Puesto: "<<fila<<columna<<endl
                    <<"Valor voleta: "<< valorFuncion + ValorPuesto + ValorSala << " pesos" << endl;
                cout << "Confirmar compra:" << endl
                    << "1. Confirmar." << endl << "2. Cancelar Compra." << endl
                    << "Seleccion: ";
                cin >> s;
                switch (s)
                {
                case 1:
                    funcions[seleccion-1].NuevoPuestoOcupado((filas-_fila),(columnas - columna));
                    actualizarArchivoFunciones();
                    V = venta (_user,funcions[seleccion-1].getMovie().getNameP(),(valorFuncion + ValorPuesto + ValorSala ));
                    Report.GuardarVenta(V);
                    cout<<"Compra realizada con exito. Gracias por su cumpra. "<<endl;
                    system("pause");
                    return true;
                    break;
                case 2:

                    cout << "Operacion cancelada";
                    control = false;

                    return false;
                    break;
                default:
                    cout << "Valor invalido" << endl;
                    system("pause");
                    break;
                }


            }





            return false;

}
void Funciones::monstrarPuestos(int i)
{
    system("cls");
        cout << "Diagrama de las sillas de la sala" << endl<< endl;


        cout << "El simbolo " << signosSilla[0] << " son los puestos generales" << endl;
        cout << "El simbolo " << signosSilla[1] << " son los puestos discapacitados" << endl;
        cout << "El simbolo " << signosSilla[2] << " son los puestos ocupados" << endl << endl;
            int n;
            int _col = funcions[i].getSalla().getColumnas();
            int _fil = funcions[i].getSalla().getFilas();
        int	medio = _col / 2;
            n = funcions.size();
            cout << " ";
            for (int f = _col; f > 0; f--) {

                if (f < 10) {
                    cout << " ";
                }
                cout << " " << f;
            }
            cout << endl;

                for (int f = 0; f < _fil; f++) {
                    cout  <<letras[_fil - 1 - f];
                    for (int c = 0; c < _col; c++) {
                        cout << "  " << funcions[i].getSillas()[f][c];
                    }
                    cout << endl;
                }
                cout << endl;
                for (int i = 0; i < medio; i++) {
                    if (i <= 10 && _col > 10) {
                        cout << "  ";
                    }
                    else {
                        cout << " ";
                    }
                }

            cout << "La pantalla queda aqui" << endl << endl;


}
















