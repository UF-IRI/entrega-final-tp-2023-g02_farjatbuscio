#include "funciones.h"
#include <string>
/************** DESARROLLO FUNCIONES **************/
//funcion agrandar vector (resize)
void agrandartam(str*& vector, int& N)
{
    N=(N)+1; //aumento en uno mi contador de tamaño
    string* aux= new string[(N)]; //un aux con el nuevo tamaño
    for(int i=0; i<N-1;i++)
    {
        aux[i]=vector[i]; //copio las cosas en el auxiliar
    }
    //libero memoria dinamica:
    delete[] vector;
    vector=aux; //le asigno la nueva memoria
}
//funcion achicar vector (resize)
void achicartam(str*& vector, int& N)
{
    N=(N)-1; //aumento en uno mi contador de tamaño
    string* aux= new string[(N)]; //un aux con el nuevo tamaño
    for(int i=0; i<N-1;i++)
    {
        aux[i]=vector[i]; //copio las cosas en el auxiliar
    }
    //libero memoria dinamica:
    delete[] vector;
    vector=aux; //le asigno la nueva memoria
}
/*desplazar un elemento al final y mover los elementos restantes una posición hacia arriba
para desp eliminarla con el resize*/
void moveralfinal(Inscripcion* cursosInscriptos, unsigned int CantInscriptos, unsigned int pos)
{
    if(pos>= CantInscriptos)
    {
        //si pos>CantInscriptos es una posicion invalida y si pos=CantInscriptos, ya esta ubicado a lo ultimo
        return;
    }
    unsigned int ultimoIdCurso = cursosInscriptos[pos].idCurso;
    time_t ultimoFechaInscrip = cursosInscriptos[pos].fechaInscripcion;

    for(unsigned int i=pos; i<CantInscriptos-1; i++)
    {
        cursosInscriptos[i].idCurso=cursosInscriptos[i+1].idCurso;
        cursosInscriptos[i].fechaInscripcion=cursosInscriptos[i+1].fechaInscripcion;
    }
    cursosInscriptos[CantInscriptos-1].idCurso=ultimoIdCurso;
    cursosInscriptos[CantInscriptos-1].fechaInscripcion=ultimoFechaInscrip;
}

