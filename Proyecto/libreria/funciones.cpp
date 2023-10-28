#include "funciones.h"
#include <string>

//Funcion que modifica el tamaño de un vector con el N pasado como parametro:
void resize (string*& vector, int* N)
{
    *N=*(N)+1; //aumento en uno mi contador de tamaño
    string* aux= new string[*(n)]; //un aux con el nuevo tamaño
    for(unsigned int i=0; i<*N-1;i++)
    {
        aux[i]=vector[i]; //copio las cosas en el auxiliar
    }
    //libero memoria dinamica:
    delete[] vector;
    vector=aux; //le asigno la nueva memoria
}
