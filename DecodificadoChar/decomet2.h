#ifndef DECOMET2_H
#define DECOMET2_H

void bloque(char binario[], char cadena1[],int n,int &i)
{
    int k;
    for (k = 0; k < n; k++)
    {
        cadena1[k] = binario[i];
        i++;
    }
}

void invierte (char cadena1[], char cadena2[],int n)
{
    int k,j = 0;

    for(k = 1; k < n; k++)
    {
       cadena2 [j]=  cadena1 [k];
       j++;
    }
    cadena2 [j]= cadena1[0];
}

void agrega (char cadena2[], char codif[],int &j,int n)
{
    int h,u = 0;
    for (h = j; u < n; h++)
    {
        codif [j] = cadena2[u];
        u++;
        j++;
    }

}

#endif // DECOMET2_H
