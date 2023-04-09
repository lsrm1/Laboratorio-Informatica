#include <iostream>
#include "decomet1.h"
#include "decomet2.h"


using namespace std;

int main ()
{
    int metodo = 0;int n = 0;int i = 0;
    int nciclo = 0;int c = 0; int p = 0;
    int l = 0; int resultado = 0;
    bool lectura = false;

    char fuente[20] = {}; char salida [20] = {};

    while(lectura == false)
    {
        cout <<"Ingresa el nombre del archivo fuente para decodificar: ";cin>>fuente;
        ncaracter(fuente,p,lectura);
    }

    cout <<"Ingresa nombre para el archivo de salida decodificado: ";cin>>salida;
    cout <<"Selecciona un metodo para decodificar: ";cin >> metodo;
    cout <<"Ingresa un número que será la semilla decodificación: ";cin>>n;

    char cadena1 [n] = {};
    char cadena2 [n] = {};


    char binario [p+1] = {};
    char codif   [p+1] = {};
    char decodif [(p/8)+1] = {};

    leerbinario(binario,fuente);

    int ciclo = (p/n);

    if (metodo == 1)
    {
        int k = 0;int r = 0;
        int cero = 0; int uno = 0;

        for (k = 0 ; k < n ; k++)
        {
            if (binario[k] == '0')
            {
                codif [k] = '1';
            }
            else
            {
                codif [k] = '0';
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
                ceromayoruno (cadena2,n);
                agregar(cadena2,codif,k,n);
                k += n;
            }

            nciclo++;
        }


        while (c < p)
        {

            binachar (codif,c,resultado);
            decodif [l] =  char(resultado);
            l++;

        }

        ofstream texto;
        texto.open(salida);
        texto<<decodif;
        texto.close();

    }


    if (metodo == 2)
    {
        int j=0;

        while( nciclo < ciclo)
        {
            bloque(binario,cadena1,n,i);
            invierte(cadena1,cadena2,n);
            agrega(cadena2,codif,j,n);
            nciclo++;
        }


        while (c < p-1)
        {

            binachar (codif,c,resultado);
            decodif [l] =  char(resultado);
            l++;

        }

        ofstream texto;
        texto.open(salida);
        texto<<decodif;
        texto.close();


    }

  return 0;

}

