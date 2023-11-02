#include "archivos.h"

eArchivoDia Funcion_AsistenciaDia(std::ifstream *archivo_dia, Asistencia *Asistencia_dia, Clases* ListaClases)
{
    // Comprueba que el archivo se pudo abrir.
    if(!archivo_dia->is_open())
        return ErrArchivo;

    //Creo aux para poder ir copiando:
    unsigned int N=1;
    unsigned int M=aux_cantInscriptos;
    unsigned int aux_id;
    unsigned int aux_cantInscriptos;
    Inscripcion aux_Inscripcion[M];
    Asistencia *Asistencia_aux=new Asistencia[N];
    while(!archivo_dia.eof())
    {
        archivo_dia.read((char*)&aux_id,sizeof(unsigned int));
        archivo_dia.read((char*)&aux_cantInscriptos, sizeof(unsigned int));
        for(int i=0;i<aux_cantInscriptos;i++)
        {
            archivo_dia.read((char*)aux_Inscripcion,sizeof(Inscripcion));
        }
            Asistencia_aux[N].idCliente=aux_id;
            Asistencia_aux[N].CursosInscriptos=aux_cantInscriptos;
            for(int i=0;i<aux_cantInscriptos;i++)
            {

                Asistencia_aux[N].CursosInscriptos[i]->idCurso=aux_Inscripcion[N].idCurso;
                Asistencia_aux[N].CursosInscriptos[i].fechaInscripcion=aux_Inscripcion[N].fechaInscripcion;

            }
            nuevotamano(Asistencia_aux,&N);

    }

    Doble_IdCLiente(&Asistencia_aux,N);
    Doble_IdCurso(&Asistencia_aux,N);
    Doble_Horario(&Asistencia_aux, &ListaClases,N);

    int aux=N;
    int N2=1;
    for(int i=0;i<N;i++) //recorro la lista entera (con nulos incluidos)
    {
        if(Asistencia_aux[i]!=ClienteNulo) //si la linea no es nula
        {
            for(int k=0; k<N2; k++) //recorro la lista nueva y la copio
            {
                Asistencia_dia[i]=Asistencia_aux[i];
                nuevotamano(Asistencia_dia,&N2);
            }
        }
    }

    return ExitoArchivo;
}
//Funcion que lee el arhivo binario de clases:
eArchivoDia Funcion_Clases(ifstream *archivo_clase,Clases *ListaClase)
{
    if(!archivo_dia->is_open())
        return ErrArchivo;
    unsigned int aux_idClase;
    string aux_NombreClase;
    time_t aux_Horario;
    int N=1;
    Clases aux_ListaClases=new Clases[N];
    //primero copio el encabezado
    string encabezado;
    getline(infile,encabezado);
    while(infile.good())
    {

    }
}
