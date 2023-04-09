#include <iostream>
#include "administrador.h"
#include "usuario.h"


int main()
{
    bool acceso = false;
    int menu = 0;int i = 0;

    int saldo = 0;
    string cedula;
    string clave;

    while (true)
    {
        menuprincipal(menu);

        if (menu == 1)
        {
            administrador();  //Decodifica la contraseña, valida y permite el registro de usuarios.
        }

        if (menu == 2)
        {
            validar(cedula,clave,saldo,acceso,i);
            // Validar acceso al cliente y retorna por referencia su usuario contraseña y saldo.

            if (acceso == true)
            {

                menusuario (saldo); // Consulta de saldo y retiro de dinero
                actualizar (cedula,clave,saldo,i);

            }
        }


    }

    return 0;
}
