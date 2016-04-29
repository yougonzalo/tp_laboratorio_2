#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define C 20
int main()
{
    EPersona per[C];
    char continuar='s';
    int flag=0,op=0;
    inicializar(per);
// declaracion de variables
    while(continuar=='s')
    {
        system("cls");
        op=menu();

        switch(op)
        {
            case 1:
                altas(per);//llamada de la funcion altas
                flag=1;
                system("pause");
                break;
            case 2:
                if(flag==1)
                {
                    bajas(per);//llamada de la funcion bajas
                }
                system("pause");
                break;
            case 3:
                if(flag==1)
                {
                    imprimir(per);//llamada de la funcion imprimir
                }
                system("pause");
                break;
            case 4:
                if(flag==1)
                {
                    grafico(per);//llamada de la funcion grafico
                }
                printf("\n");
                system("pause");
                break;
            case 5:
                continuar ='n';
                break;
        }
    }

    return 0;
}
