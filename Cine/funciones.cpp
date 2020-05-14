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

            f = Funcion(_ID,hora,ssala,pel,_Tvideo,nSillas);
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
















