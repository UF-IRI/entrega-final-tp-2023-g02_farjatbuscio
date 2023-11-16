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
int dobleid_cliente(Asistencia*& aux_asistencia, Asistencia*& Asistencia_dia, int N)
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
void dobleid_curso(Asistencia& aux_asistencia)
{
    int N=aux_asistencia.cantInscriptos;
    for(int i=0; i<N; i++)
    {
        //verifico si hay dos id_cursos iguales
        if(aux_asistencia.CursosInscriptos[i].idCurso==aux_asistencia.CursosInscriptos[i+1].idCurso)
        {
            //elimino uno
            moveralfinal(aux_asistencia.CursosInscriptos, aux_asistencia.cantInscriptos, i+1);
            achicartamInscrip(aux_asistencia.CursosInscriptos, aux_asistencia.cantInscriptos);
            aux_asistencia.cantInscriptos=(aux_asistencia.cantInscriptos)-1;
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

float horario_clase (int aux_idClase, Clases*& ListaClases, int NcantClases)
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

void doblehorario(Asistencia& aux_asistencia, Clases*& ListaClases, int NcantClases)
{
    int N = aux_asistencia.cantInscriptos;
    int aux_id1; //aca guardo el id
    int aux_id2;

    float aux_horario1;//guardo el horario de las clases
    float aux_horario2;

    time_t aux_fecha1;//guardo el horario en el q reservaron la clase
    time_t aux_fecha2;
    int ret=0;
    if(aux_asistencia.cantInscriptos<=1)
    {
        return;
    }
    for(int i=0; i<N-1 ;i++)
    {
        aux_id1 = aux_asistencia.CursosInscriptos[i].idCurso;
        aux_id2 = aux_asistencia.CursosInscriptos[i+1].idCurso;

        aux_horario1 = horario_clase(aux_id1, ListaClases, NcantClases);
        aux_horario2 = horario_clase(aux_id2, ListaClases, NcantClases);

        if(aux_horario1 == aux_horario2)
        {
            aux_fecha1 = aux_asistencia.CursosInscriptos[i].fechaInscripcion;
            aux_fecha2 = aux_asistencia.CursosInscriptos[i+1].fechaInscripcion;
            //borro el que tenga time_t mas reciente
            ret = fechas(aux_fecha1,aux_fecha2);
            if(ret == 1)
            {
                //borro la clase de aux_id1
                moveralfinal(aux_asistencia.CursosInscriptos, N, i);//aux_asistencia->CursosInscriptos lo paso con puntero para que lo recorra???
                achicartamInscrip(aux_asistencia.CursosInscriptos, N); //como paso la N si quiero que el valor quede cambiado?
                aux_asistencia.cantInscriptos=aux_asistencia.cantInscriptos-1;
            }
            else if(ret == 2)
            {
                //borro la clase de aux_id2
                moveralfinal(aux_asistencia.CursosInscriptos, N, i+1);//aux_asistencia->CursosInscriptos lo paso con puntero para que lo recorra???
                achicartamInscrip(aux_asistencia.CursosInscriptos, N); //como paso la N si quiero que el valor quede cambiado?
                aux_asistencia.cantInscriptos=aux_asistencia.cantInscriptos-1;
            }
            else if(ret == 3)
            {
                //borro cualquiera
                moveralfinal(aux_asistencia.CursosInscriptos, N, i);//aux_asistencia->CursosInscriptos lo paso con puntero para que lo recorra???
                achicartamInscrip(aux_asistencia.CursosInscriptos, N); //como paso la N si quiero que el valor quede cambiado?
                aux_asistencia.cantInscriptos=aux_asistencia.cantInscriptos-1;
            }
            else if (ret == -1)
            {
                return;
            }
            N = aux_asistencia.cantInscriptos;
        }
    }
    return;
}

int id_clienteExistente(Cliente*& ListaClientes, int Nclientes, int id_cliente)
{
    int i;
    for(i=0; i<Nclientes; i++)
    {
        if(ListaClientes[i].idCliente == id_cliente)
            return 1; //exito
    }
    return -1; //error ---> no encontró el idcliente
}

int cuotapaga(Cliente*& ListaClientes, int Nclientes, int id_cliente)
{
    int i;
    for(i=0;i<Nclientes;i++)
    {
        if(ListaClientes[i].idCliente == id_cliente)
        {
            if(ListaClientes[i].estado >= 0)
            {
                return 1; //exito ---> cuota al dia
            }
            else
            {
                return -1; //error ---> debe cuotas
            }
        }
    }
    return -1;
}
void dobleid_cursoListaMan(Asistencia*& AsistenciaMan, int Ninscriptos, Asistencia& aux_asistencia)
{
    for(int i=0; i<Ninscriptos; i++) //busco el cliente en la lista de manana
    {
        if(AsistenciaMan[i].idCliente==aux_asistencia.idCliente) //cuando lo encuentro
        {
            for(int j=0; j<AsistenciaMan[i].cantInscriptos; j++) //recorro las clases a las que ya esta inscripto
            {
                for(int k=0; k<aux_asistencia.cantInscriptos; k++) //recorro las clases que se quiere inscribir cliente
                {
                    if(aux_asistencia.CursosInscriptos[k].idCurso == AsistenciaMan[i].CursosInscriptos[j].idCurso)
                    {
                        //si la clase a la que se quiere inscribir es igual a alguna de las clases que ya se inscribio
                        //la elimino
                        moveralfinal(aux_asistencia.CursosInscriptos, aux_asistencia.cantInscriptos, k);
                        achicartamInscrip(aux_asistencia.CursosInscriptos,aux_asistencia.cantInscriptos);
                        aux_asistencia.cantInscriptos=(aux_asistencia.cantInscriptos)-1;
                        k=k-1;
                    }
                }
            }
        }
    }
}
void doblehorario_ListaMan(Asistencia& aux_asistencia, Clases*& ListaClases, int NcantClases, Asistencia*& AsistenciaMan, int Ninscriptos)
{
    int idcurso_inscrip;
    int idcurso_noinscrip;
    float horario_inscrip;
    float horario_noinscrip;
    for(int i=0; i<Ninscriptos; i++) //busco el cliente en la lista de manana
    {
        if(AsistenciaMan[i].idCliente==aux_asistencia.idCliente) //cuando lo encuentro
        {
            for(int j=0; j<AsistenciaMan[i].cantInscriptos; j++) //recorro las clases a las que ya esta inscripto
            {
                for(int k=0; k<aux_asistencia.cantInscriptos; k++) //recorro las clases que se quiere inscribir cliente
                {
                    idcurso_inscrip = AsistenciaMan[i].CursosInscriptos[j].idCurso;
                    idcurso_noinscrip = aux_asistencia.CursosInscriptos[k].idCurso;
                    horario_inscrip = horario_clase(idcurso_inscrip, ListaClases, NcantClases);
                    horario_noinscrip = horario_clase(idcurso_noinscrip, ListaClases, NcantClases);
                    if(horario_inscrip == horario_noinscrip)
                    {
                        moveralfinal(aux_asistencia.CursosInscriptos, aux_asistencia.cantInscriptos, k);
                        achicartamInscrip(aux_asistencia.CursosInscriptos,aux_asistencia.cantInscriptos);
                        aux_asistencia.cantInscriptos=(aux_asistencia.cantInscriptos)-1;
                        k=k-1;
                    }
                }
            }
        }
    }
}

/*void funcion_cupo(Asistencia& aux_asistencia, Asistencia*& AsistenciaMan,int Ninscriptos, Clases* ListaClases,int Nclases, CupoClases*& ListaCupo, int Ncupos)
{
    int cont=0;
    string auxNombreClase;
    int auxIdCurso;
    int aux2IdCurso;
    //si mi cantidad de inscriptos es ==0 entonces hay cupos para cualquier tipo de clase:
    if(Ninscriptos==0)
    {
        return; //si nadie esta inscripto tdv, todos los cupos estan libres
    }

    for(int k=0; k<aux_asistencia.cantInscriptos; k++) //recorro las clases a las que el usuario se quiere inscribir
    {
        auxIdCurso = aux_asistencia.CursosInscriptos[k].idCurso; //me guardo el id de la clase

        for(int j=0; j<Nclases; j++) //recorro la lista de clases para guardarme el nombre de clase
        {
            if(ListaClases[j].idClase == auxIdCurso)
            {
                auxNombreClase = ListaClases[j].NombreClase; //me guarde el nombre de la clase
            }
        }
        for(int i=0; i<Ninscriptos;i++)//recorro la lista de los ya inscriptos
        {
            for(int p=0; p<AsistenciaMan[i].cantInscriptos; p++)//recorro las clases del primer cliente
            {
                aux2IdCurso = AsistenciaMan[i].CursosInscriptos[p].idCurso;
                for(int j=0; j<Nclases; j++) //recorro la lista de clases hasta encontrar la clase
                {
                    if(ListaClases[j].idClase == aux2IdCurso)
                    {
                        if((auxNombreClase.compare(ListaClases[j].NombreClase))==0)
                        {
                            cont++;
                        }
                    }
                }
            }
        }
        //Ahora lo busco en la lista de cupos, y me fijo si mi contador es menor que esa cantidad
        for(int i=0; i<Ncupos; i++)
        {
            if(ListaCupo[i].NombreClase==auxNombreClase)
            {
                if(ListaCupo[i].Ncupo<cont)
                {
                    //no se puede inscribir a la clase
                    //la mando al final
                    moveralfinal(aux_asistencia.CursosInscriptos, aux_asistencia.cantInscriptos, k);
                    //la borro
                    achicartamInscrip(aux_asistencia.CursosInscriptos, aux_asistencia.cantInscriptos);
                    aux_asistencia.cantInscriptos=(aux_asistencia.cantInscriptos)-1;
                    k=k-1;
                }
                //si se puede inscribir a esta clase
            }
        }
    }
}

eInscripManFinal inscripMan(Asistencia& aux_asistencia, Asistencia*& AsistenciaMan, int Ninscriptos, Clases*& ListaClases,int Nclases, Cliente*& ListaClientes, int Nclientes, CupoClases*& ListaCupo, int Ncupos)
{
    //funcion que hace todos los chequeos para la inscripcion de un cliente p manana
    //le paso el cliente q se quiere inscribir, la lista de asistMan, la lista de clases, la lista de clientes y la lista de cupos

    //primero) me fijo si el cliente existe en la lista de clientes.
    int ret1;
    int id_cliente =0;
    id_cliente= aux_asistencia.idCliente;
    ret1 = id_clienteExistente(ListaClientes, Nclientes, id_cliente);

    if(ret1 == 1)
    {
      //el cliente existe en la lista de clientes del gym
      //segundo) me fijo que el cliente tenga la couta al dia
        int ret2;
        ret2 = cuotapaga(ListaClientes,Nclientes,id_cliente);
        if(ret2 == 1)
        {
            //el cliente tiene la cuota al dia
            //tercero) me fijo si el cliente ya existe en la lista de asistenciaMan
            for(int i=0; i<Ninscriptos; i++)
            {
               if(AsistenciaMan[i].idCliente == id_cliente && AsistenciaMan[i].cantInscriptos>0)
                {
                    //cuarto) borro clases a las que no podria inscribirse
                    //el cliente ya existe en la lista de clientes, por ende ya se inscribio a algo p manana
                    //me fijo si se esta queriendo inscribir 2 veces en la misma clase, le borro una
                    dobleid_curso(aux_asistencia);
                    //me fijo si se quiere inscribir en una clase que ya esta inscripto, se la borro
                    dobleid_cursoListaMan(AsistenciaMan, Ninscriptos, aux_asistencia);
                    //me fijo si se quiere inscribir a dos clases al mismo horario, le borro la ultima
                    doblehorario(aux_asistencia, ListaClases, Nclases);
                    //me fijo si se quiere inscribir en una clase al horario de una clase que ya este inscripto, se la borro
                    doblehorario_ListaMan(aux_asistencia, ListaClases, Nclases, AsistenciaMan, Ninscriptos);

                    //quinto) por ultimo me fijo que haya cupo en cada clase
                    funcion_cupo(aux_asistencia, AsistenciaMan, Ninscriptos, ListaClases, Nclases, ListaCupo, Ncupos);
                    //puedo inscribir a aux_asistencia
                    if(aux_asistencia.cantInscriptos>0)
                    {
                        return ExitoInscrip;//retorno exito, aux_asistencia se puede inscribir en AsistenciaMan con todas las modificaciones que le hicimos
                        //podriamos aca imprimir en pantalla los datos que quedaron de aux_asistencia, para mostrarle al cliente
                        //a que clases si se pudo inscribir y a cuales no, explicandole el motivo
                    }
                    else if(aux_asistencia.cantInscriptos <= 0)
                    {
                        return ErrNingunaClase; //retorno error porque no pudo inscribirse a ninguna clase ya que todas tenian errores
                    }
                }
            }
            //el cliente no existe en la lista de clientes, por ende todavia no se inscribio a nada p manana
            //entonces solo chequeo:
            //me fijo si se esta queriendo inscribir 2 veces en la misma clase, le borro una
            dobleid_curso(aux_asistencia);
            //me fijo si se quiere inscribir a dos clases al mismo horario, le borro la ultima
            doblehorario(aux_asistencia, ListaClases, Nclases);
            funcion_cupo(aux_asistencia, AsistenciaMan, Ninscriptos, ListaClases, Nclases, ListaCupo, Ncupos);
            if(aux_asistencia.cantInscriptos>0)
            {
                return ExitoInscrip;//retorno exito, aux_asistencia se puede inscribir en AsistenciaMan con todas las modificaciones que le hicimos
                //podriamos aca imprimir en pantalla los datos que quedaron de aux_asistencia, para mostrarle al cliente
                //a que clases si se pudo inscribir y a cuales no, explicandole el motivo
            }
            else if(aux_asistencia.cantInscriptos <= 0)
            {
                return ErrNingunaClase; //retorno error porque no pudo inscribirse a ninguna clase ya que todas tenian errores
            }
        }
        else if(ret2 == -1)
        {
            return ErrCouta; //el cliente debe cuotas al gimnasio
        }
    }
    else if(ret1 == -1)
    {
        return ErrCliente; //el cliente no se encontro en la lista de clientes del gym
    }
    return ErrRandom; //hubo algun error durante la inscripcion y no se lo podria inscribir
}*/
