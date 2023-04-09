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

    char original[30]={};
    char fuente  [20]={};
    char salida  [20]={};

    while (lectura == false) //Verifica que el archivo exista y no esté vacío
    {
        cout <<"Ingresa el nombre del archivo fuente para codificar: ";cin>>fuente;

        leer (fuente,original,p,lectura);

        cout<< "------------------------------------------------------------------\n";
    }

    cout << "---------------------------------------------------------------------\n";
    cout <<"Ingresa el nombre del archivo salida codificado: ";cin>>salida;
    cout <<"1. Primer metodo\n2. Segundo metodo\nSelecciona un metodo para codificar: ";cin >> metodo;
    cout <<"Ingresa un número que será la semilla de codificación: ";cin>>n;

    char cadena1 [n] = {};
    char cadena2 [n] = {};

    conversor (original,p);       // Convierte el texto a binario

    p = (p*8);                    // p es el número de caracteres que tiene el texto

    char binario[p+1] = {};
    char codif  [p+1] = {};

    leerbinario(binario);

    ciclo = (p/n);

    if (metodo == 1)
    {
        int k = 0;int r = 0;
        int cero = 0; int uno = 0;

        for (k = 0 ; k < n ; k++)          //Invierte el primer grupo de caracteres
        {
            if (binario[k] == '0')
            {
                codif[k] = '1';
            }
            else
            {
                codif[k] = '0';
            }

        }

        nciclo++;

        while (nciclo < ciclo)
        {
            cadenabase(binario,cadena1,n,i);    //Toma la cadena para contar unos y ceros en ella
            r = i;
            cadenamodif(binario,cadena2,n,r);   //Toma la cadena a la que se va a modificar
            contador(cadena1,cero,uno,n);       // Cuenta unos y ceros en la cadena base

            if (cero == uno)
            {
                ceroigualuno (cadena2,n);
                agregar(cadena2,codif,k,n);     //Va agregando a la línea codificada
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

        while( nciclo < ciclo) // Toma cada grupo de bits invierte la posición del último bit y la agrega la cadena codificada
        {
            bloque(binario,cadena1,n,i);
            invierte(cadena1,cadena2,n);
            agrega(cadena2,codif,j,n);

            nciclo++;
        }

        ofstream archivocodif;
        archivocodif.open(salida);
        archivocodif << codif;
        archivocodif.close();

    }

    return 0;
}
