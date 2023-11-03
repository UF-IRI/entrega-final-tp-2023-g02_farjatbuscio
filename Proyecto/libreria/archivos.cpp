#include "archivos.h"

/****funcion que lee el archivo de clases y retorna -1 si no se pudo leer y 1 si se pudo leer,
y la lista de clases quedaria cargada:******/
eArchivo LeerClases(ifstream* archivoClases, Clases* ListaClases,int &Nclases)
{
    //si el archivo es distinto a open entonces retorno error
    if(!archivoClases->is_open())
    {
        return ErrArchivo;
    }
    //declaracion de variables:

    stringstream ss;
    string encabezado;
    string auxiliarlinea; //la necesito para ir cargando transitoriamente
    char delimiter=',';

    //auxiliares para guardar los datos de clase: son strigns por la funcion
    string auxIdClase;
    string auxNombreClase;
    string auxHorario;

    //leer el encabezado:
    getline(archivoClases,encabezado);

    //mientras el archivo esté abierto
    while(archivoClases)
    {
        getline(archivoClases,auxiliarlinea);//levanto toda la linea
        ss<<auxiliarlinea; //copio todo lo que tiene auxiliar en ss
        //delimitacion:
        getline(ss,auxIdClase,delimiter);//guardo hasta la coma
        //stoi:castea de string a entero!
        ListaClases[Nclases-1].idClase==stoi(auxIdClase); //N-1 porq N=1
        getline(ss,auxNombreClase,delimiter);
        ListaClases[Nclases-1].NombreClase==auxNombreClase;
        getline(ss,auxHorario,delimiter);
        //stof: el horario debo castearlo a float
        ListaClases[Nclases-1].Horario==stof(auxHorario);
        //llamo a la funcion resize: para agrandar el tamaño
        agrandartam(ListaClases,&Nclases);
    }
    return ExitoArchivo;
}
