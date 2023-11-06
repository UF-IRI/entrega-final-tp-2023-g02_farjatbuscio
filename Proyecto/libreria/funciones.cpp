#include "funciones.h"
//DESARROLLO FUNCIONES
//funcion agrandar Clases (resize)
void agrandartamClases(Clases*& vector, int& N)
{
    N=(N)+1; //aumento en uno mi contador de tamaño
    Clases* aux= new Clases[(N)]; //un aux con el nuevo tamaño
    for(int i=0; i<N-1;i++)
    {
        aux[i]=vector[i]; //copio las cosas en el auxiliar
    }
    //libero memoria dinamica:
    delete[] vector;
    vector=aux; //le asigno la nueva memoria
}
//funcion agrandar Cliente (resize)
void agrandartamCliente(Cliente*& vector, int& N)
{
    N=(N)+1; //aumento en uno mi contador de tamaño
    Cliente* aux= new Cliente[(N)]; //un aux con el nuevo tamaño
    for(int i=0; i<N-1;i++)
    {
        aux[i]=vector[i]; //copio las cosas en el auxiliar
    }
    //libero memoria dinamica:
    delete[] vector;
    vector=aux; //le asigno la nueva memoria
}
//funcion agrandar Asistencia (resize)
void agrandartamAsistencia(Asistencia*& vector, int& N)
{
    N=(N)+1; //aumento en uno mi contador de tamaño
    Asistencia* aux= new Asistencia[(N)]; //un aux con el nuevo tamaño
    for(int i=0; i<N-1;i++)
    {
        aux[i]=vector[i]; //copio las cosas en el auxiliar
    }
    //libero memoria dinamica:
    delete[] vector;
    vector=aux; //le asigno la nueva memoria
}
//funcion agrandar Inscripcion (resize)
void agrandartamInscrip(Inscripcion*& vector, int& N)
{
    N=(N)+1; //aumento en uno mi contador de tamaño
    Inscripcion* aux= new Inscripcion[(N)]; //un aux con el nuevo tamaño
    for(int i=0; i<N-1;i++)
    {
        aux[i]=vector[i]; //copio las cosas en el auxiliar
    }
    //libero memoria dinamica:
    delete[] vector;
    vector=aux; //le asigno la nueva memoria
}
//funcion achicar Inscripcion (resize)
void achicartamInscrip(Inscripcion*& vector, int& N)
{
    N=N-1; //disminuyo en uno mi contador de tamaño
    Inscripcion* aux= new Inscripcion[(N)]; //un aux con el nuevo tamaño
    for(int i=0; i<N-1;i++)
    {
        aux[i]=vector[i]; //copio las cosas en el auxiliar
    }
    //libero memoria dinamica:
    delete[] vector;
    vector=aux; //le asigno la nueva memoria
}
//desplazar un elemento al final y mover los elementos restantes una posición hacia arriba
//para desp eliminarla con el resize
void moveralfinal(Inscripcion* cursosInscriptos, int CantInscriptos, int pos)
{
    if(pos>= CantInscriptos)
    {
        //si pos>CantInscriptos es una posicion invalida y si pos=CantInscriptos, ya esta ubicado a lo ultimo
        return;
    }
    int ultimoIdCurso = cursosInscriptos[pos].idCurso;
    time_t ultimoFechaInscrip = cursosInscriptos[pos].fechaInscripcion;

    for(int i=pos; i<CantInscriptos-1; i++)
    {
        cursosInscriptos[i].idCurso=cursosInscriptos[i+1].idCurso;
        cursosInscriptos[i].fechaInscripcion=cursosInscriptos[i+1].fechaInscripcion;
    }
    cursosInscriptos[CantInscriptos-1].idCurso=ultimoIdCurso;
    cursosInscriptos[CantInscriptos-1].fechaInscripcion=ultimoFechaInscrip;
}
//Chequea que el cliente del archivo Asitencia_dia que voy a leer, no esté ya anotado en Asistencia_dia
//Si retorno Error -> NO lo cargo directamente NADA
//Si retorno Exito -> procedo a mirar si las siguientes condiciones se cumplen*/
int dobleid_cliente(Asistencia* aux_asistencia, Asistencia* Asistencia_dia, int N)
{
    if(N==0)
    {
        return 1;
    }
    /*recorro los clientes (del archivo) que ya tengo cargados en mi struct dinamica
    (Asistencia_dia)*/
    for(int i=0; i<N; i++)
    {
        /*Reviso si el cliente q quiero cargar, ya existe en Asistencia_dia*/
        if(aux_asistencia->idCliente==Asistencia_dia[i].idCliente)
        {
            //Si exite, retorno Error y no lo vuelvo a cargar
            return -1;
        }
    }
    return 1;
}
//Chequea que el cliente que voy a inscribir no este anotado dos veces en la misma clase
//si esta anotado dos veces, elimino una
//sino no cambio nada
void dobleid_curso(Asistencia*& aux_asistencia)
{
    int N=aux_asistencia->cantInscriptos;
    for(int i=1; i<N; i++)
    {
        //verifico si hay dos id_cursos iguales
        if(aux_asistencia->CursosInscriptos[i].idCurso==aux_asistencia->CursosInscriptos[i+1].idCurso)
        {
            //elimino uno
            moveralfinal(aux_asistencia->CursosInscriptos, aux_asistencia->cantInscriptos, i);
            achicartamInscrip(aux_asistencia->CursosInscriptos, aux_asistencia->cantInscriptos);
            aux_asistencia->cantInscriptos=(aux_asistencia->cantInscriptos-1);
        }
    }
}

