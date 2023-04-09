#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "decodificar.h"
#include <fstream>
using namespace std;

void menuprincipal(int &menu)
{
    cout << "\n---------------------------------------------------------------\n";
    cout << "                    CAJERO INFORMÁTICA II";
    cout << "\n---------------------------------------------------------------\n";
    cout<< "                        Menu Principal\n\n";
    cout<< "1. Para acceder como Administrador\n2. Para acceder como Usuario\nSeleccione: ";
    cin>>menu;

}

void registrousuario() // Agregar usuarios a la base de datos
{
    cout <<"-------------------------------------------------------------------\n";
    cout<< "                        Registro de Usuarios\n";
    cout <<"-------------------------------------------------------------------\n";

    int cedula = 0; int clave = 0; float saldo = 0;
    ofstream archivo;
    char registro = 'S';

    archivo.open("base.txt",ios::app);

    while (registro == 'S')
    {
     cout<<"Ingrese datos del usuario: \n";
     cin >> cedula >> clave >> saldo;


     archivo<<cedula<<" ";
     archivo<<clave<<" ";
     archivo<<saldo<<"\n";


     cout << "Registrar otro usuario ? (S/N) ";cin >> registro;


    }
    archivo.close();


}

void administrador() // Valida la clave de acceso e invoca a la funcion registro de usuarios
{
    string clave;
    string accesoclave;
    int m = 0;

    decodificado(accesoclave);


    cout << "Ingresa clave para continuar: ";cin>>clave;

    if (clave == accesoclave)
    {
        while ( m != 2)
        {
            cout<<"----------------------------------------------------------------------\n";
            cout<<"                              BIENVENIDO\n";
            cout<<"----------------------------------------------------------------------\n";

            cout << "1.Registro de usuarios\n2.Salir\nSeleccione: ";
            cin >> m;


            if (m == 1)
            {
                registrousuario();
            }

            if (m == 2)
            {
                cout << "Cerrando sesion...\n";
            }

        }



    }
    else
    {
        cout <<"Clave incorrecta...\n" ;
    }


}

#endif // ADMINISTRADOR_H
