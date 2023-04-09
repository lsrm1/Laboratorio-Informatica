#ifndef DECODIFICAR_H
#define DECODIFICAR_H

#include <string>
#include <fstream>

using namespace std;

void leerbinario(string &binario) //Obtiene todos los caracteres del archivo y los almacena en la cadena binario
{
    ifstream leerbin;
    leerbin.open("sudo.txt");


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

void bloque(string binario,string &cadena1,int n,int &i)
{
    int k;
    for (k = 0; k < n; k++)
    {
        cadena1 += binario[i];
        i++;
    }
}

void invierte (string cadena1,string &cadena2,int n)
{
    int k,j = 0;

    for(k = 1; k < n; k++)
    {
       cadena2 +=  cadena1 [k];
    }
    cadena2 += cadena1[j];
}

void agrega (string cadena2,string &codif,int &j,int n)
{
    int h,u = 0;
    for (h = j; u < n; h++)
    {
        codif += cadena2[u];
        u++;
        j++;
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

void decodificado(string &accesoclave) // Función principal para decodificar por el método 2
{
    int n = 4; int i = 0;
    int nciclo = 0;int c = 0;
    int resultado = 0;


    string cadena1;string cadena2;
    string binario;
    string codif;


    leerbinario(binario);

    int p = binario.size();
    int ciclo = (p/n);


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


    while (c < p-1)
    {

        binachar (codif,c,resultado);
        accesoclave +=  char(resultado);

    }



}

#endif // DECODIFICAR_H
