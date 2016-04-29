#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define C 20


int menu()
{
        int op;

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");
    scanf("%d",&op);

    while(op<1||op>6)
    {
        printf("\nIngrese una opcion entre 1 y 5: ");
        scanf("%d",&op);
    }//validacion para que el usuario ingrese un numero correcto
    return op;
}

void inicializar(EPersona per[])
{
        int i;
    for(i=0;i<C;i++)//dejar todos los campos de la estructura vacio
    {
        strcpy(per[i].nombre,"\0");
        per[i].dni=0;
        per[i].edad=0;
        per[i].estado=0;
    }
}

void altas(EPersona per[])
{
        long int dni;
        int i,edad,indice=-1,flag=0;
        char auxnom[75];
        indice=libre(per);

    if(indice!=-1)
    {
        printf("Ingrese dni: ");
        scanf("%ld",&dni);

        while(dni<1000000||dni>99000000)
        {
            printf("Ingrese un dni correcto: ");
            scanf("%ld",&dni);
        }//validar dni

        for(i=0;i<C;i++)
        {
                while(dni<1000000||dni>99000000)
                {
                    printf("Ingrese un dni correcto: ");
                    scanf("%ld",&dni);
                }
            }
        }


            per[indice].dni=dni;
            printf("Ingrese su nombre: ");
            fflush(stdin);
            gets(auxnom);
            valtam(auxnom,50);
            strcpy(per[indice].nombre, auxnom);
            printf("Ingrese su edad: ");
            scanf("%d",&edad);

            while(edad<1 || edad>100)
            {
                printf("reingrese su edad verdadero: ");
                scanf("%d",&edad);
            }//validacion de edad

            per[indice].edad=edad;
            per[indice].estado=1;//el estado cambia cuando el usuario ingresa sus datos
        }


void imprimir(EPersona per[])
{
        int i,j;
        EPersona aux;
        for(i=0;i<C-1;i++)
    {
        if(per[i].estado==1)
        {
            for(j=i+1;j<C;j++)
            {
                if(strcmp(per[i].nombre,per[j].nombre)>0)//ordena de orden alfabetico
                {
                    aux=per[i];
                    per[i]=per[j];
                    per[j]=aux;
                }
            }
        }
    }
    for(i=0;i<C;i++)
    {
        if(per[i].estado!=0)
            printf("%ld--%s--%d\n",per[i].dni,per[i].nombre, per[i].edad);
    }
}
int buscar(EPersona per[C], long int auxdni)
{
        int i, flag=0;

    for(i=0;i<C;i++)
    {
        if(per[i].dni==auxdni)
        {
            flag=1;
            break;
        }
    }
    return flag;
}//busca el dni y lo compara con el dni ingresado

void bajas(EPersona per[])
{
        int i, flag=0;
        long int dni;
        char rta='n';

        printf("Ingrese el dni de la persona que desea borrar: ");
        scanf("%ld",&dni);

        flag=buscar(per,dni);

    for(i=0;i<C;i++)
    {
        if(dni==per[i].dni)
        {
            printf("Nombre: %s,DNI: %ld,Edad: %d",per[i].nombre, per[i].dni, per[i].edad);
            printf("\nDesea borrarlo? <s/n>: ");
            rta=tolower(getch());
            while(rta!='s'&&rta!='n')//validar s o n
            {
                printf("\nIngrese solo s o n: ");
                rta=tolower(getch());
            }
        }
    }
if(flag && rta=='s')
{

    for(i=0;i<C;i++)
    {
        if(dni==per[i].dni)//borra los datos
        {
            strcpy(per[i].nombre,"\0");
            per[i].edad=0;
            per[i].dni=0;
            per[i].estado=0;
            break;
        }
    }
}

    else
        if(rta=='n')
        printf("\nVolviendo al menu.\n");
    else
        printf("\nEse dni no existe.\n");
}

int libre(EPersona per[])
{
    int i,indice=-1;
    for(i=0;i<C;i++)
    {
        if(per[i].estado==0)
        {
            indice=i;
            break;
        }

    }
    return indice;
}//busca si hay espacio libre en la celda

void grafico(EPersona per[])
{
int i,c18=0,c19y35=0,cm35=0,mayor=0,flag=0;

    for(i=0;i<C;i++)
    {
        if(per[i].estado!=0)
        {
            if(per[i].edad<=18)
                c18++;

            else if(per[i].edad>18 && per[i].edad<=35)
                c19y35++;

            else
                cm35++;
        }
    }

    if(c18>=c19y35 && c18>=cm35)
        mayor=c18;

    else if(c19y35>=c18 && c19y35>=cm35)
        mayor=c19y35;

    else
        mayor=cm35;

    for(i=mayor;i>0;i--)
    {
        if(c18>=mayor)
            printf("*");

        if(c19y35>=mayor)
        {
            printf("\t*");
            flag=1;
        }

        if(cm35>=mayor)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag)
                printf("\t*");
        }

        printf("\n");
        mayor--;
    }
    printf("< 18/19<>35/> 35");
}

void valtam(char x[], int tam)//validar nombre
{
    while(strlen(x)>tam-1)
    {
        printf("Error, reingrese una cadena que no exeda %d caracteres: ", tam-1);
        fflush(stdin);
        gets(x);
    }
}
//desarrollo de las funciones
