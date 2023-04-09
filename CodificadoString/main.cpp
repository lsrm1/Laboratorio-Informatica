#include <iostream>
#include "metodo1.h"
#include "metodo2.h"

using namespace std;

int main()
{
    int metodo = 0;
    int n = 0;int p = 0;int i = 0;
    int ciclo = 0;int nciclo = 0;
    bool lectura = false;

    string fuente;  string salida;
    string original;string binario; string codif;
    string cadena1; string cadena2;

    while (lectura == false)
    {
        cout <<"Ingresa el nombre del archivo fuente para codificar: ";cin>>fuente;
        leer (fuente,original,p,lectura);
        cout<< "------------------------------------------------------------------\n";
    }


    cout << "---------------------------------------------------------------------\n";
    cout <<"Ingresa el nombre del archivo salida codificado: ";cin>>salida;
    cout <<"1. Primer metodo\n2. Segundo metodo\nSelecciona un metodo para codificar: ";cin >> metodo;
    cout <<"Ingresa un número que será la semilla de codificación: ";cin>>n;

    conversor (original,p);

    leerbinario(binario);

    p = binario.size();

    ciclo = (p/n);

    if (metodo == 1)
    {
        int k = 0;int r = 0;
        int cero = 0; int uno = 0;

        for (k = 0 ; k < n ; k++)
        {
            if (binario[k] == '0')
            {
                codif += '1';
            }
            else
            {
                codif += '0';
            }

        }

        nciclo++;




        while (nciclo < ciclo)
        {
            cadenabase(binario,cadena1,n,i);
            r = i;
            cadenamodif(binario,cadena2,n,r);
            contador(cadena1,cero,uno,n);

            if (cero == uno)
            {
                ceroigualuno (cadena2,n);
                agregar(cadena2,codif,k,n);
                k += n;
            }
            if (cero > uno)
            {
                ceromayoruno (cadena2,n);
                agregar(cadena2,codif,k,n);
                k += n;
            }
            if (cero < uno)
            {
                ceromenoruno (cadena2,n);
                agregar(cadena2,codif,k,n);
                k += n;
            }

            cadena1 = "";
            cadena2 = "";
            nciclo++;
        }

        ofstream archivocodif;
        archivocodif.open(salida);
        archivocodif << codif;
        archivocodif.close();
    }

    if (metodo == 2)
    {
        int j=0;

        while( nciclo < ciclo)
        {
            bloque(binario,cadena1,n,i);
            invierte(cadena1,cadena2,n);
            agrega(cadena2,codif,j,n);

            cadena1 = "";
            cadena2 = "";
            nciclo++;
        }

        ofstream archivocodif;
        archivocodif.open(salida);
        archivocodif << codif;
        archivocodif.close();

    }


    return 0;
}
