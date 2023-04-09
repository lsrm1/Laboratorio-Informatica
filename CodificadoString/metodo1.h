#ifndef METODO1_H
#define METODO1_H

#include <fstream>
#include <bitset>

using namespace std;

void leer (string fuente,string &original, int &p,bool &lectura)
{
    try
    {
        ifstream archivotxt;
        archivotxt.open(fuente);

        if (archivotxt.fail() == true)
        {
            throw 1;
        }

        else
        {
            int k=0;
            while(archivotxt.good())
            {
                char temp = archivotxt.get();

                if(archivotxt.good())
                {
                    original += temp;
                }

                k++;
            }

            archivotxt.close();
            p = (original.size())-1;

            if (p >= 1)
            {
                lectura = true;
            }

            else
            {
                cout << "El archivo "<<fuente<<" esta vacio!\n";

            }


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


void conversor (string original,int p)
{
    int ascii = 0;
    ofstream archivobin;

    archivobin.open ("binario.txt");

    for (int j = 0; j < p; j++)
    {
        ascii = original[j];
        bitset<8> b(ascii);
        archivobin << b;

    }

    archivobin.close();



}

void leerbinario(string &binario)
{
    ifstream leerbin;
    leerbin.open("binario.txt");


    while(leerbin.good())
    {
        char temp=leerbin.get();

        if(leerbin.good())
        {
            binario += temp;
        }

    }
    leerbin.close();

}

void cadenabase (string binario,string &cadena, int n, int &i)
{
    int j;
    for (j = 0; j < n; j++)
    {
       cadena += binario[i];
       i++;

    }

}

void cadenamodif (string binario,string &cadena, int n, int &r)
{
    int j;
    for (j = 0; j < n; j++)
    {
       cadena += binario[r];
       r++;

    }

}

void contador(string &cadena1,int &cero,int &uno,int n)
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

void ceroigualuno (string &cadena2,int n)
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

void ceromayoruno (string &cadena2,int n)
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

void ceromenoruno (string &cadena2,int n)
{
    int l ;
    for (l = 2;l < n; l += 3)
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


void agregar (string cadena2,string &codif,int k,int n)
{
    int h,u = 0;
    for (h = k; u < n ; h++)
    {
        codif += cadena2[u];
        u++;
    }

}

#endif // METODO1_H
