#include "archivos.h"

/****funcion que lee el archivo de clases y retorna -1 si no se pudo leer y 1 si se pudo leer,
y la lista de clases quedaria cargada:******/
eArchivo LeerClases(ifstream archivoClases, Clases*& ListaClases,int &Nclases)
{
    //si el archivo es distinto a open entonces retorno error
    if(!archivoClases.is_open())
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
        ListaClases[Nclases-1].idClase=stoi(auxIdClase); //N-1 porq N=1
        getline(ss,auxNombreClase,delimiter);
        ListaClases[Nclases-1].NombreClase=auxNombreClase;
        getline(ss,auxHorario,delimiter);
        //stof: el horario debo castearlo a float
        ListaClases[Nclases-1].Horario=stof(auxHorario);
        //llamo a la funcion resize: para agrandar el tamaño
        agrandartamClases(ListaClases,Nclases);
    }
    return ExitoArchivo;
}
/****funcion que lee el archivo de clientes y retorna -1 si no se pudo leer y 1 si se pudo leer,
y la lista de clientes quedaria cargada:******/
eArchivo LeerClientes(ifstream archivoClientes, Cliente*& ListaClientes,int &Nclientes)
{
    //si el archivo es distinto a open entonces retorno error
    if(!archivoClientes.is_open())
    {
        return ErrArchivo;
    }
    //declaracion de variables:

    stringstream ss;
    string encabezado;
    string auxiliarlinea; //la necesito para ir cargando transitoriamente
    char delimiter=',';

    //auxiliares para guardar los datos de clase: son strigns por la funcion
    string auxidCliente;
    string auxNombre;
    string auxApellido;
    string auxMail;
    string auxTelefono;
    string auxfechaNacimiento;
    string auxestado;
    //leer el encabezado:
    getline(archivoClientes,encabezado);

    //mientras el archivo esté abierto
    while(archivoClientes)
    {
        getline(archivoClientes,auxiliarlinea);//levanto toda la linea
        ss<<auxiliarlinea; //copio todo lo que tiene auxiliar en ss
        //delimitacion:
        getline(ss,auxidCliente,delimiter);//guardo hasta la coma
        //stoi:castea de string a entero!
        ListaClientes[Nclientes-1].idCliente=stoi(auxidCliente); //N-1 porq N=1
        getline(ss,auxNombre,delimiter);
        ListaClientes[Nclientes-1].Nombre=auxNombre;
        getline(ss,auxApellido,delimiter);
        ListaClientes[Nclientes-1].Apellido=auxApellido;
        getline(ss,auxMail,delimiter);
        ListaClientes[Nclientes-1].Mail=auxMail;
        getline(ss,auxTelefono,delimiter);
        ListaClientes[Nclientes-1].Telefono=auxTelefono;
        getline(ss,auxfechaNacimiento,delimiter);
        //casteo a float
        ListaClientes[Nclientes-1].fechaNacimiento=stof(auxfechaNacimiento);
        getline(ss,auxestado,delimiter);
        //casteo a int
        ListaClientes[Nclientes-1].estado=stoi(auxestado);
        //llamo a la funcion resize: para agrandar el tamaño
        agrandartamCliente(ListaClientes,Nclientes);
    }
    return ExitoArchivo;
}
