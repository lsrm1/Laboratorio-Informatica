#ifndef DECOMET1_H
#define DECOMET1_H

#include <fstream>
using namespace std;


void ncaracter(char fuente[], int &p,bool &lectura)
{
    try
    {
        ifstream leerbin;
        leerbin.open(fuente);

        if (leerbin.fail() == true)
        {
            throw 1;
        }

        else
        {
            while(leerbin.good())
            {
               char temp = leerbin.get();

               if(leerbin.good())
                {
                    p++;
                }
            }

        }

        leerbin.close();


        if (p >= 1)
        {
            lectura = true;
        }

        else
        {
            cout << "El archivo "<<fuente<<" esta vacio!\n";

        }
    }

    catch(int error)
    {
        if( error == 1)
        {
            cout<< "No se encontro el archivo "<<fuente<<"\n";

        }
    }

}

void leerbinario(char binario[],char fuente[])
{
    ifstream leerbin;
    leerbin.open(fuente);

    int k = 0;
    while(leerbin.good())
    {
        char temp=leerbin.get();

        if(leerbin.good())
        {
            binario [k] = temp;
        }

        k++;
    }
    leerbin.close();

}

void cadenabase (char binario[],char cadena[], int n, int &i)
{
    int j;
    for (j = 0; j < n; j++)
    {
       cadena[j] = binario[i];
       i++;

    }

}

void cadenamodif (char binario[],char cadena[], int n, int &r)
{
    int j;
    for (j = 0; j < n; j++)
    {
       cadena [j] = binario[r];
       r++;

    }

}

void contador(char cadena1[],int &cero,int &uno,int n)
{
    cero= 0;
    uno = 0;
    int j = 0;

    while (j < n)
    {
        if (cadena1 [j] == '0')
        {
            cero++;
        }
        else
        {
            uno++;
        }

        j++;
    }
}

void ceroigualuno (char cadena2[],int n)
{
    int l = 0;
    for (l = 0;l < n; l++)
    {
        if (cadena2[l]=='0')
        {
            cadena2[l]='1';
        }
        else
        {
            cadena2[l]='0';
        }
    }
}

void ceromayoruno (char cadena2[],int n)
{
    int l ;
    for (l = 1;l < n; l += 2)
    {
        if (cadena2[l]=='0')
        {
            cadena2[l]='1';
        }
        else
        {
            cadena2[l]='0';
        }
    }
}

void agregar (char cadena2[],char codif[],int k,int n)
{
    int h,u = 0;
    for (h = k; u < n ; h++)
    {
        codif [h]= cadena2[u];
        u++;
    }

}

void binachar (char  codif[],int &c,int &resultado)
{
    char cadena[8] = {};
    int resto = 0;
    int digito[8];

    for (int b = 0; b < 8; b++)
    {
        cadena [b] = codif[c];
        c++;
    }

    int entero = atoi(cadena);


    for (int i = 0; i < 8; i++)
    {
      digito[i] = entero % 10;
      entero /= 10;
    }

    for (int i = 7; i >= 0; i--)
    {
      resultado = (resto*2) + digito[i];
      resto = resultado;
    }


}
#endif // DECOMET1_H
