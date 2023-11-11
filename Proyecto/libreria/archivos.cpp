#include "archivos.h"

//funcion que lee el archivo de clases y retorna -1 si no se pudo leer y 1 si se pudo leer,
//y la lista de clases quedaria cargada:
eArchivo LeerClases(ifstream& archivoClases, Clases* &ListaClases,int& Nclases)
{
    //si el archivo es distinto a open entonces retorno error
   /* if(!archivoClases.is_open())
    {
        return ErrArchivo;
    }
    //declaracion de variables:
*/

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
        ss.clear();
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
//funcion que lee el archivo de clientes y retorna -1 si no se pudo leer y 1 si se pudo leer,
//y la lista de clientes quedaria cargada:
eArchivo LeerClientes(ifstream& archivoClientes, Cliente* &ListaClientes,int &Nclientes)
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
eArchivo LeerAsistencia_hoy(ifstream& archivo_dia, Asistencia*& AsistenciaDia,int &Ninscripciones)
{
    //si el archivo es distinto a open entonces retorno error
    if(!archivo_dia.is_open())
    {
        return ErrArchivo;
    }
    int ret;
    Ninscripciones=0;
    //Creo aux para poder ir copiando:
    Asistencia aux;
    while(!archivo_dia.eof())
    {
        archivo_dia.read((char*)&aux.idCliente,sizeof(int));
        archivo_dia.read((char*)&aux.cantInscriptos, sizeof(int));
        Inscripcion* aux_inscripcion=new Inscripcion[aux.cantInscriptos];
        for(int i=0;i<aux.cantInscriptos;i++)
        {
            archivo_dia.read((char*)aux_inscripcion,sizeof(Inscripcion));
        }
        ret=dobleid_cliente(aux,AsistenciaDia,Ninscripciones);
        if(ret==1)
        {
            //llamar a la funcion 1 y 2
            //agrando el vector de asistencia dia y cargo aux a asistencia dia:
            agrandartamAsistencia(AsistenciaDia,Ninscripciones);
            AsistenciaDia[Ninscripciones-1].idCliente=aux.idCliente;
            AsistenciaDia[Ninscripciones-1].cantInscriptos=aux.cantInscriptos;
            //agrando el vector de inscripcion
            for(int j=0; j<aux.cantInscriptos; j++)
            {
                agrandartamInscrip(AsistenciaDia->CursosInscriptos,j);
            }
            for(int k=0;k<aux.cantInscriptos;k++)
            {
                AsistenciaDia[Ninscripciones-1].CursosInscriptos->idCurso=aux_inscripcion->idCurso;
                AsistenciaDia[Ninscripciones-1].CursosInscriptos->fechaInscripcion=aux_inscripcion->fechaInscripcion;
            }
            //DONDE LIBERO MEMORIA?
        }
    }

    return ExitoArchivo;
}
//lo comento porq me genera ERROR el nombre del archivo
//Funcion que crea el archivo para mañana
eArchivo CrearAsistencia_manana(string& NombreArchivo,Asistencia*& AsistenciaMan,int &Ninscripciones)
{
    //creo el archivo para modificacion:
    ofstream archivo_man;
    //Nombre_Archivo: contiene el nombre del archivo con time actual: "Asistencias"+ time()
    //"asistencias_1697673600000.dat"
    archivo_man.open(NombreArchivo,ios::binary);
    if(!archivo_man.is_open())
    {
        return ErrArchivo;
    }
    if (archivo_man.is_open())
    {
        for (int i=0; i<Ninscripciones; i++)
        {
            archivo_man.write((char*)&AsistenciaMan[i].idCliente, sizeof(int));
            archivo_man.write((char*)&AsistenciaMan[i].cantInscriptos, sizeof(int));
            for(int j = 0; j < AsistenciaMan[i].cantInscriptos; j++)
            {
                archivo_man.write((char*)&AsistenciaMan[i].CursosInscriptos[j],sizeof(Inscripcion));
            }
        }
    }
    archivo_man.close();
    return ExitoArchivo;
}
//Funcion que genera datos random:
/*Asistencia RandCliente(Cliente* ListaClientes, Clases* ListaClase)
{
    int num_cliente=rand()%(sizeof(ListaClientes));
    Asistencia aux;
    aux.idCliente=ListaClientes[num_cliente].idCliente;

    aux.cantInscriptos= (rand()%5)+1;
    Inscripcion*  aux.CursosInscriptos= new Inscripcion [aux.cantInscriptos];
    //no se si esta bien pedir la memoria? o como hago?
    //si esta bien pedirla, donde la libero?
    for(int i=0; i< aux.cantInscriptos; i++)
    {
        int num_clase=rand()%(sizeof(ListaClase));
        aux.CursosInscriptos[i].idCurso=ListaClase[num_clase].idClase;
        aux.CursosInscriptos[i].fechaInscripcion=time(0);
    }
    return aux;
}
*/
//Funcion generica que imprime los datos de los clientes inscriptos en esa id de clase
void ImprimirDatos(Asistencia* AsistenciaMan, int id_clase, int Ninscripciones)
{
    int cont=0;
    if(Ninscripciones==0)
    {
        cout<<"En este momento, no hay clientes inscriptos en su clases"<<endl;
    }
    if(Ninscripciones>0)
    {
        //recorro los clientes
        for(int i=0;i<Ninscripciones;i++)
        {
            //recorro los cursos inscriptos de los clientes
            for(int k=0; k<AsistenciaMan[i].cantInscriptos; k++)
            //si coincide el id de curso imprimo los datos:
            if(AsistenciaMan[i].CursosInscriptos[k].idCurso==id_clase)
            {
                cout<<"Datos de las inscripciones correspondiente a la clase con ID:"<<id_clase<<endl;
                cout<<"Id del cliente:"<<AsistenciaMan[i].idCliente<<endl;
                //un acumulador que cuente los clientes inscriptos
                cont++;
            }
        }
    }
    //si el acumulador es mayor que cero, imprimo la cantidad de clientes inscriptos a esa clase
    if(cont>0)
    {
        cout<<"Cantidad de inscriptos a su clase:"<<cont<<endl;
    }
}
