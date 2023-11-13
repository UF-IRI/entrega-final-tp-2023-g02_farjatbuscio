#include "funciones.h"
//DESARROLLO FUNCIONES

//funcion agrandar Clases (resize)
void agrandartamClases(Clases*& vector, int& N)
{
    N=N+1; //aumento en uno mi contador de tamaño
    Clases* aux= new Clases[N]; //un aux con el nuevo tamaño
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
    N=N+1; //aumento en uno mi contador de tamaño
    Cliente* aux= new Cliente[N]; //un aux con el nuevo tamaño
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
    N=N+1; //aumento en uno mi contador de tamaño
    Asistencia* aux= new Asistencia[N]; //un aux con el nuevo tamaño
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
    N=N+1; //aumento en uno mi contador de tamaño
    Inscripcion* aux= new Inscripcion[N]; //un aux con el nuevo tamaño
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
void moveralfinal(Inscripcion*& cursosInscriptos, int CantInscriptos, int pos)
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
//Si retorno Exito -> procedo a mirar si las siguientes condiciones se cumplen
int dobleid_cliente(Asistencia aux_asistencia, Asistencia*& Asistencia_dia, int N)
{
    if(N<=0)
    {
        return 1;
    }
    //recorro los clientes (del archivo) que ya tengo cargados en mi struct dinamica (Asistencia_dia)
    for(int i=0; i<N; i++)
    {
        //Reviso si el cliente q quiero cargar, ya existe en Asistencia_dia
        if(aux_asistencia.idCliente==Asistencia_dia[i].idCliente)
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
    for(int i=0; i<N; i++)
    {
        //verifico si hay dos id_cursos iguales
        if(aux_asistencia->CursosInscriptos[i].idCurso==aux_asistencia->CursosInscriptos[i+1].idCurso)
        {
            //elimino uno
            moveralfinal(aux_asistencia->CursosInscriptos, aux_asistencia->cantInscriptos, i+1);
            achicartamInscrip(aux_asistencia->CursosInscriptos, aux_asistencia->cantInscriptos);
            aux_asistencia->cantInscriptos=(aux_asistencia->cantInscriptos-1);
            N=N-1;
            i=i-1;
        }
    }
}
int fechas(time_t fecha1, time_t fecha2)
{
    if(fecha1 > fecha2)
    {
        //la fecha1 es mas reciente que la fecha2
        return 1;
    }
    else if(fecha1 < fecha2)
    {
        //la fecha2 es mas reciente que la fecha1
        return 2;
    }
    else if(fecha1 == fecha2)
    {
        //son la misma fecha
        return 3;
    }
    else return -1; //retorna -1 si las fechas estan incompletas o null
}
float horario_clase (int aux_idClase, Clases ListaClases, int NcantClases)
{
    float horario=0.0;
    for(int i=0; i<NcantClases; i++)
    {
        if(aux_idClase == ListaClases[i].idClase)
        {
            horario = ListaClases[i].Horario;
        }
    }
    return horario;
}

void doblehorario(Asistencia*& aux_asistencia, Clases ListaClases, int NcantClases)
{
    int N = aux_asistencia->cantInscriptos;
    int aux_id1; //aca guardo el id
    int aux_id2;

    float aux_horario1;//guardo el horario de las clases
    float aux_horario2;

    time_t aux_fecha1;//guardo el horario en el q reservaron la clase
    time_t aux_fecha2;
    int ret=0;
    if(aux_asistencia->cantInscriptos<=1)
    {
        return;
    }
    for(int i=0; i<N-1 ;i++)
    {
        aux_id1 = aux_asistencia->CursosInscriptos[i].idCurso;
        aux_id2 = aux_asistencia->CursosInscriptos[i+1].idCurso;

        aux_horario1 = horario_clase(aux_id1, ListaClases, NcantClases);
        aux_horario2 = horario_clase(aux_id2, ListaClases, NcantClases);

        if(aux_horario1 == aux_horario2)
        {
            aux_fecha1 = aux_asistencia->CursosInscriptos[i].fechaInscripcion;
            aux_fecha2 = aux_asistencia->CursosInscriptos[i+1].fechaInscripcion;
            //borro el que tenga time_t mas reciente
            ret = fechas(aux_fecha1,aux_fecha2);
            if(ret == 1)
            {
                //borro la clase de aux_id1
                moveralfinal(aux_asistencia->CursosInscriptos, N, i);//aux_asistencia->CursosInscriptos lo paso con puntero para que lo recorra???
                achicartamInscrip(aux_asistencia->CursosInscriptos, N); //como paso la N si quiero que el valor quede cambiado?
                aux_asistencia->cantInscriptos=aux_asistencia->cantInscriptos-1;
            }
            else if(ret == 2)
            {
                //borro la clase de aux_id2
                moveralfinal(aux_asistencia->CursosInscriptos, N, i+1);//aux_asistencia->CursosInscriptos lo paso con puntero para que lo recorra???
                achicartamInscrip(aux_asistencia->CursosInscriptos, N); //como paso la N si quiero que el valor quede cambiado?
                aux_asistencia->cantInscriptos=aux_asistencia->cantInscriptos-1;
            }
            else if(ret == 3)
            {
                //borro cualquiera
                moveralfinal(aux_asistencia->CursosInscriptos, N, i);//aux_asistencia->CursosInscriptos lo paso con puntero para que lo recorra???
                achicartamInscrip(aux_asistencia->CursosInscriptos, N); //como paso la N si quiero que el valor quede cambiado?
                aux_asistencia->cantInscriptos=aux_asistencia->cantInscriptos-1;
            }
            else if (ret == -1)
            {
                return;
            }
            N = aux_asistencia->cantInscriptos;
        }
    }
    return;
}


int funcion_cupo(Asistencia*& AsistenciaMan,int Ninscriptos, Clases* ListaClases,int Nclases, int id_clase, CupoClases* &ListaCupo, int Ncupos)
{
    int cont=0;
    string auxNombreClase;
    //si mi cantidad de inscriptos es ==0 entonces hay cupos para cualquier tipo de clase:
    if(Ninscriptos==0)
    {
        return 1; //retorno 1 si hay cupos y -1 si no hay
    }
    //primero cuento cuantos inscriptos hay con este id de clase pasado:
    for(int i=0;i<Ninscriptos;i++)
    {
        for(int k=0;k<AsistenciaMan[i].cantInscriptos;k++)
        {
            if(AsistenciaMan[i].CursosInscriptos[k].idCurso==id_clase)
            {
                cont++;
            }
        }
    }
    //me guardo en un auxiliar el nombre de la clase que coincide con ese ID
    for(int j=0;j<Nclases;j++)
    {
        if(ListaClases[j].idClase==id_clase)
        {
            auxNombreClase=ListaClases[j].NombreClase;
        }
    }
    //Ahora lo busco en la lista de cupos, y me fijo si mi contador es menor que esa cantidad
    for(int i=0;i<Ncupos;i++)
    {
        if(ListaCupo[i].NombreClase==auxNombreClase)
        {
            if(cont<ListaCupo[i].Ncupo)
            {
                return 1;
            }
            else if(cont>ListaCupo[i].Ncupo)
            {
                return -1;
            }
        }
    }
}
