#ifndef DECOMET1_H
#define DECOMET1_H

#include <string>
#include <fstream>

using namespace std;

void leerbinario(string &binario,string fuente,bool &lectura)
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
                char temp=leerbin.get();

                if(leerbin.good())
                {
                    binario += temp;
                }

            }
            leerbin.close();

            if (binario.size() >= 1)
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

void binachar (string codif,int &c,int &resultado)
{
    string cadena = "";
    int resto = 0;
    int digito[8];

    for (int b = 0; b < 8; b++)
    {
        cadena += codif[c];
        c++;
    }

    int entero = stoi(cadena);


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
