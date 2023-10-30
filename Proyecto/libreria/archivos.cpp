#include "archivos.h"

eArchivoDia Funcion_AsistenciaDia(ifstream *archivo_dia, Asistencia *Asistencia_dia, Clases* ListaClases)
{
    // Comprueba que el archivo se pudo abrir.
    if(!archivo_dia->is_open())
        return ErrArchivo;

    //Creo aux para poder ir copiando:
    unsigned int N=1;
    unsigned int M=1;
    unsigned int aux_id;
    unsigned int aux_cantInscriptos;
    Inscripcion aux_Inscripcion[M];
    Asistencia *Asistencia_dia=new Asistencia[N];
    while(!archivo_dia.eof())
    {
        archivo_dia.read((char*)&aux_id,sizeof(unsigned int));
        archivo_dia.read((char*)&aux_cantInscriptos, sizeof(unsigned int));
        for(int i=0;i<aux_cantInscriptos;i++)
        {
            archivo_dia.read((char*)aux_Inscripcion,sizeof(Inscripcion));
        }
        //si es el primero de la lista que copie los datos
        if(N==1)
        {
            Asistencia_dia[N].idCliente=aux_id;
            Asistencia_dia[N].CursosInscriptos=aux_cantInscriptos;
            for(int i=0;i<aux_cantInscriptos;i++)
            {

                Asistencia_dia[N].CursosInscriptos[i]->idCurso=aux_Inscripcion[N].idCurso;
                Asistencia_dia[N].CursosInscriptos[i].fechaInscripcion=aux_Inscripcion[N].fechaInscripcion;

            }
            resize(Asistencia_dia,N);
        }
        //si no es el primero reviso las condiciones
        else
        {
            //llamo a las funciones para chequear condiciones:
            Doble_IdCLiente(&Asistencia_dia);
            Doble_IdCurso(&Asistencia_dia);
            Doble_Horario(&Asistencia_dia,&ListaClases);
            for(i=0;i<N;i++)
            {
                //si es distinto de nulo, entonces lo copio
                if(Asistencia_dia[i]!=ClienteNulo)
                {
                    Asistencia_dia[N].idCliente=aux_id;
                    Asistencia_dia[N].CursosInscriptos=aux_cantInscriptos;
                    for(int i=0;i<aux_cantInscriptos;i++)
                    {

                        Asistencia_dia[N].CursosInscriptos[i]->idCurso=aux_Inscripcion[N].idCurso;
                        Asistencia_dia[N].CursosInscriptos[i].fechaInscripcion=aux_Inscripcion[N].fechaInscripcion;

                    }
                    //llamo a la funcion resize para ir agrandando el tamaño:
                    resize(Asistencia_dia,N);
                }

            }
        }
    }
    return ExitoArchivo;
}