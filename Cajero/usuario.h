#ifndef USUARIO_H
#define USUARIO_H

#include <fstream>

using namespace std;

int numerolinea () //Cuenta el número de líneas que tiene la base de datos
{
    int j = 0;
    string linea;

    ifstream archivo;
    archivo.open("base.txt");

    while (getline(archivo, linea))
    {
        j ++;
    }

    archivo.close();

  return j;

}

void validar (string &cedula, string &clave, int &saldo, bool &acceso,int &i)
{
    string usuario; // Verifica usuario y contraseña y permite el acceso al menú del usuario
    string  claveu; //y  da el número de línea en el que se encontró al usuario.

    int nlinea = 0;
    i = 0;

    cout << "Ingrese numero de cédula: ";cin >> usuario;
    cout << "Ingrese clave: ";cin>>claveu;
    cout <<"-------------------------------------------------------------------\n";

    nlinea = numerolinea();

    ifstream archivo;

    archivo.open("base.txt");

    while ((acceso == false) && (i < nlinea))
    {

        archivo >> cedula>>clave>>saldo;

        if ((cedula == usuario) && (clave == claveu))
        {
            acceso = true;
        }

        i++;

    }

    archivo.close();

    if (acceso == false)
    {
        cout <<"-------------------------------------------------------------------\n";
        cout << "Usuario o clave incorrectas...\nIntente de nuevo\n";

    }
}

void menusuario (int &saldo) // Permite la consulta de saldo y retiro de dinero
{
    int retiro = 0;
    bool checkretiro = false;
    int m = 0;

    saldo = saldo-1000;

    cout <<"-------------------------------------------------------------------\n";
    cout<<"                              BIENVENIDO\n";
    cout <<"-------------------------------------------------------------------\n";

    while ( m != 3)
    {

        cout << "\n1.Consultar saldo.\n2.Retirar dinero\n3.Salir\nSeleccione: ";
        cin >> m;


        if (m == 1)
        {
            cout <<"-------------------------------------------------------------------\n";
            cout << "Saldo actual: "<< saldo;
            cout <<"\n-------------------------------------------------------------------\n";
        }

        if (m == 2)
        {
            while (checkretiro == false)
            {
                cout <<"-------------------------------------------------------------------\n";
                cout << "Saldo actual: "<< saldo;
                cout <<"\n¿Cuanto dinero desea retirar? ";cin >> retiro;
                cout <<"\n-------------------------------------------------------------------\n";

                if ((retiro<=saldo)&&(retiro > 0))
                {
                    saldo = saldo-retiro;
                    checkretiro = true;
                    cout <<"                        ¡Transaccion Realizada!\n";
                    cout <<"-------------------------------------------------------------------\n";


                }
                else
                {
                    cout << "\nCantidad no valida!!\n ";
                }

        }   }


        if (m == 3)
        {
            cout << "Cerrando sesion...\n";
        }

    }


}


void actualizar (string &cedula, string &clave, int &saldo,int &i)
{
    int j = 0; // Actualiza la base de datos
    string linea;

    ifstream archivo;
    archivo.open("base.txt");

    ofstream archivo2;
    archivo2.open("texto.txt");

    while (getline(archivo, linea))
    {
        if (j == i) // i Es la línea de texto del usuario que va actualizar
        {
            archivo2<<cedula<<" ";
            archivo2<<clave<<" ";
            archivo2<<saldo<<"\n";



        }
        else
        {
            archivo2<<linea;
            archivo2<<"\n";
        }

        j++;

    }

    archivo.close();

    archivo2.close();


    ofstream archivo3;
    archivo3.open("base.txt");

    ifstream archivo4;
    archivo4.open("texto.txt");

    while (getline(archivo4, linea))
    {
        archivo3<<linea;
        archivo3<<"\n";

    }
    archivo4.close();

    archivo3.close();

}

#endif // USUARIO_H
