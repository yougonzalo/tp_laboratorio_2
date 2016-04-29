#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
                char nombre[50];
                int edad;
                int estado;
                long int dni;
              }EPersona;//estructura

int menu();
void inicializar(EPersona per[]);
void altas(EPersona per[]);
int buscar(EPersona per[],long int dni);
void imprimir(EPersona per[]);
void bajas(EPersona per[]);
int libre(EPersona per[]);
void grafico(EPersona per[]);
void valtam(char x[],int tam);

#endif // FUNCIONES_H_INCLUDED

