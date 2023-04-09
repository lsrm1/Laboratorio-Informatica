#ifndef METODO2_H
#define METODO2_H

using namespace std;

void bloque(char binario[],char cadena1[],int n,int &i)
{
    int k;
    for (k = 0; k < n; k++)
    {
        cadena1 [k] = binario[i];
        i++;
    }
}

void invierte (char cadena1[],char cadena2[],int n)
{
    int k,j = 0;

    cadena2[j] = cadena1[n-1];

    for(k = 1; k < n; k++)
    {
       cadena2[k] =  cadena1 [j];
       j++;
    }
}

void agrega (char cadena2[],char codif[],int &j,int n)
{
    int h,u = 0;
    for (h = j; u < n; h++)
    {
        codif[h] = cadena2[u];
        u++;
        j++;
    }

}

#endif // METODO2_H
