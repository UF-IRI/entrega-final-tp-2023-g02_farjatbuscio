#include <iostream>
#include <archivos.cpp>
#include <funciones.cpp>

using namespace std;

int main() {

    //INSCRIPCION DE NUEVOS CLIENTES:
    //abro archivos CLASE
    ifstream archivoClase;
    archivoClase.open("iriClasesGYM.csv");

    int NClases=0;//cantidad de clases
    eArchivo retorClase;//creo variable tipo enum
    Clases *ListaClases=new Clases[NClases];//pido memoria para lista clases
    retorClase=LeerClases(archivoClase,ListaClases,NClases);//llamo a la funcion de leer archivo de clases
    if(retorClase==-1)
    {
        cout<<"Error al abrir el archivo de clases"<<endl;
    }
    if(retorClase==1)
    {
        cout<<"El archivo de clases se abrió correctamente"<<endl;
    }
    //abro archivo de CLIENTES
    ifstream archivoClientes;
    archivoClientes.open("iriClientesGYM.csv");
    int Nclientes=0;//cantidad de clientes
    eArchivo retClientes;//creo variable tipo enum
    Cliente* ListaClientes=new Cliente[Nclientes];//pido memoria para lista de clientes
    retClientes=LeerClientes(archivoClientes,ListaClientes,Nclientes);
    if(retClientes==-1)
    {
        cout<<"Error al abrir el archivo de clientes"<<endl;
    }
    if(retorClientes==1)
    {
        cout<<"El archivo de clientes se abrió correctamente"<<endl;
    }

    //una vez abierto los archivos:
    //inicializo la struct de cupos:

    int Ncupo=7;
    CupoClases* Cupo=new CupoClases[Ncupo];
    Cupo={{"Spinning",45},{"Yoga",25},{"Pilates",15},{"Stretching",40},{"Zumba",50},{"Boxeo",30},{"Musculacion",30}};

    //RANDOM CLIENTES:
    //asigno un random de cantidad de clientes nuevos
    int CantNuevos=(rand()%20)+1;
    cout<<"Se intentaran agregar: "<<CantNuevos<<" clientes en el dia de hoy, siempre y cuando cumplan con las condiciones"<<endl;

    eInscripManFinal retInsc;//creo variable tipo enum
    int Ninscriptos=0;
    Asistencia* AsistenciaMan=new Asistencia[Ninscriptos];
    for(int i=0;i<CantNuevos;i++)
    {
        Asistencia* auxRandom=new Asistencia; //FIJARNOS MEMORIA!!
        RandCliente(ListaClientes,NClases,Nclientes,ListaClases,auxRandom);//me devuelve un cliente random
        //llamo a la funcion de inscripcion:
        retInsc=inscripMan(auxRandom,AsistenciaMan,Ninscriptos,ListaClases,NClases,ListaClientes,Nclientes,Cupo,Ncupo);
        //ErrCliente = -1,  ErrCouta = -2, ErrRandom = -3, ErrNingunaClase = -4, ExitoInscrip = 1}
        if(retInsc==-1)
        {
            cout<<"El cliente con id: "<<auxRandom->idCliente<<" no se pudo inscribir ya que no se encontro en la lista del gimnasio, comunicarse con el gimnasio para mayor informacion."<<endl;

        }
        if(retInsc==-2)
        {
            cout<<"El cliente con id: "<<auxRandom->idCliente<<" no se pudo inscribir ya que no abono su cuota, comunicarse con el gimnasio para mayor informacion."<<endl;
        }
        if(retInsc==-3)
        {
            cout<<"El cliente con id: "<<auxRandom->idCliente<<" no se pudo inscribir ya que hubo un error en el proceso, comunicarse con el gimnasio para mayor informacion."<<endl;
        }
        if(retInsc==-4)
        {
            cout<<"El cliente con id: "<<auxRandom->idCliente<<" no se pudo inscribir en ninguna clase ya que en todos los intentos surgieron distintos inconvenientes, comunicarse con el gimnasio para mayor informacion."<<endl;
        }
        if(retInsc==1)
        {
            //El cliente se puede inscribir:lo agrego a la lista de asistencia
            //primero pido memoria para inscripcion:
            Inscripcion* auxClaseExito=new Inscripcion[auxRandom->cantInscriptos];
            for(int k=0;k<auxRandom->cantInscriptos;k++)
            {
                auxClaseExito[k]=auxRandom->CursosInscriptos[k];
            }
            //agrendo la lista de asistencia
            agrandartamAsistencia(AsistenciaMan,Ninscriptos);
            AsistenciaMan[Ninscriptos-1].idCliente=auxRandom->idCliente;
            AsistenciaMan[Ninscriptos-1].cantInscriptos=auxRandom->cantInscriptos;
            AsistenciaMan[Ninscriptos-1].CursosInscriptos=auxClaseExito;
            cout<<"El cliente con id: "<<auxRandom->idCliente<<" se pudo inscribir a las siguientes clases: "<<endl;
            for(int i=0; i<(AsistenciaMan[Ninscriptos-1].cantInscriptos);i++)
            {
                int auxid=AsistenciaMan[Ninscriptos-1].CursosInscriptos[i].idCurso;
                string nombreclase;
                float horarioclase;
                for(int k=0; k<NClases; k++)
                {
                    if(auxid==ListaClases[k].idClase)
                    {
                        nombreclase=ListaClases[k].NombreClase;
                        horarioclase=ListaClases[k].Horario;
                    }
                }
                cout<<"Clase: "<<nombreclase<<" a las: "<<horarioclase<<endl;
            }
            delete[] auxClaseExito;
        }
        delete[] auxRandom;
    }

    //Una vez cargados todos los clientes, creo el archivo de Inscripcion Mañana:
    eArchivo retorArchivoNuevo;
    string NombreArchivo="asistencia.dat";
    retorArchivoNuevo=CrearAsistencia_manana(NombreArchivo,AsistenciaMan,Ninscriptos);
    if(retorArchivoNuevo==-1)
    {
        cout<<"Error al crear el archivo de  clientes nuevos"<<endl;
    }
    if(retorArchivoNuevo==1)
    {
        cout<<"El archivo de clientes nuevos se creo correctamente"<<endl;
    }

    //imprimir datos de una clase random:
    int numRand=(rand()%Ninscriptos);
    int id_clase=AsistenciaMan[numRand].CursosInscriptos[0].idCurso;
    ImprimirDatos(AsistenciaMan,id_clase,Ninscriptos);

    //CIERRO ARCHIVOS
    archivoClase.close();
    archivoClientes.close();
    //LIBERO MEMORIA PEDIDA
    delete[] ListaClases;
    delete[] ListaClientes;
    delete[] AsistenciaMan;
    return 0;
}

