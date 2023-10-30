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

/********* CONDICIONES PARA CHEQUEAR STRUCT Asistencia_dia (PILI)*********/

/* Chequea cada id registrado en el struct dinamico Asistencia_dia (LO TENGO QUE DECLARAR
COMO DINAMICO EN EL MAIN), si el id se repite, elimina uno */
eId_Cliente Doble_IdCLiente(Asistencia* Asistencia_dia)
{
    unsigned int aux_idCliente;
    unsigned int Nfinal; //CAMBIAR ESTO, MORE LO TIENE
    int cont=0;

    for(unsigned i=0; i<Nfinal ; i++) //recorro Asistencia_dia
    {
        aux_idCliente=Asistencia_dia[i].idCliente; //me guardo el id del primer cliente

        for(unsigned k=0; k<Nfinal; k++) //recorro de nuevo Asistencia_dia
        {
            if(!(Asistencia_dia[k].idCliente==aux_idCliente && i!=k)) //si NO se repite el cliente
            {
                //lo cargo en el struct dinamico
            }
        }
    }
    //si lo voy a cargar aca adentro, hago la funcion void, sino retorno extio/error
}
/* Chequeo que por cliente, no se repita el mismo id_curso (que no este inscripto
dos veces en la misma clase)*/
eId_Curso Doble_IdCurso(Asistencia* Asistencia_dia)
{
    unsigned int aux_idClase;
    unsigned int Nfinal; //CAMBIAR ESTO, MORE LO TIENE

    for(unsigned i=0; i<Nfinal ; i++) //recorro Asistencia_dia
    {
        if(Asistencia_dia[i].cantInscriptos>1) //si esta inscripto en mas de 1 clase
        {
            for(unsigned j=0; j<Asistencia_dia[i].cantInscriptos ; j++) //recorro los cursos en los q este anotado
            {
                aux_idClase = Asistencia_dia[i].CursosInscriptos[j].idCurso; //me guardo el 1er id_curso

                for(unsigned k=0; k<Asistencia_dia[i].cantInscriptos ; k++) //recorro de nuevo los cursos en los q este anotado
                {
                    //si NO se repite el id_curso
                    if(!(aux_idClase == Asistencia_dia[i].CursosInscriptos[k].idCurso && j!=k))
                    {
                        //lo cargo en el struct dinamico
                    }
                }

            }
        }
    }

}
/*FUNCION EXTRA para Doble_Horario (la funcion de abajo), me devuelve el horario de una
clase si le paso el id_curso */
time_t Horario_clase (unsigned int aux_idClase, Clases* ListaClases)
{
    unsigned int NcantClases = 60; //LO HAGO ASI? O CON PUNTERO?
    time_t horario;
    for(unsigned int i=0; i<NcantClases; i++)
    {
        if(aux_idClase == ListaClases[i].idClase)
        {
            horario=ListaClases[i].Horario;
        }
    }
    return horario;
}
/* Chequea que por cliente, no se repita el mismo horario, es decir, que el mismo cliente
no este inscripto en dos clases (distinta o igual clase) al mismo horario. Si fuera asi, deberia cargar en el
struct dinamico la primera a la cual esta inscripto (con time_t fechaInscripcion) */
eHorario Doble_Horario(Asistencia* Asistencia_dia , Clases* ListaClases)
{
    unsigned int aux_idClase;
    unsigned int aux2_idClase;
    time_t aux_horario;
    time_t aux2_horario;
    unsigned int Nfinal; //CAMBIAR ESTO, MORE LO TIENE

    for(unsigned i=0; i<Nfinal ; i++) //recorro Asistencia_dia
    {
        if(Asistencia_dia[i].cantInscriptos>1) //si esta inscripto en mas de 1 clase
        {
            for(unsigned j=0; j<Asistencia_dia[i].cantInscriptos ; j++) //recorro los cursos en los q este anotado
            {
                aux_idClase = Asistencia_dia[i].CursosInscriptos[j].idCurso; //me guardo el 1er id_curso

                //con el id_curso accedo al horario de curso y me lo guardo en un aux
                aux_horario = Horario_clase(aux_idClase, &ListaClases); //VER SI LA LLAME BIEN

                for(unsigned k=0; k<Asistencia_dia[i].cantInscriptos ; k++) //recorro de nuevo los cursos en los q este anotado
                {
                    aux2_idClase = Asistencia_dia[i].CursosInscriptos[k].idCurso;
                    aux2_horario = Horario_clase(aux2_idClase, &ListaClases); //VER SI LA LLAME BIEN

                    if(!(aux_horario==aux2_horario && j!=k))
                    {
                        //lo cargo en el struct dinamico
                    }
                }
            }
        }
    }
}

/********* CONDICIONES PARA INSCRIBIR A UNA CLASE (PILI)*********/




