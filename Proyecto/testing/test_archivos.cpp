#include <catch2/catch.hpp>
#include <archivos.h>

using namespace std;

//test para leer archivo de clases:
TEST_CASE("Funcion de leer archivo de clases", "[fancy]")
{
    //abro archivo de clases
    ifstream archivoClase;
    archivoClase.open("iriClasesGYM.csv");

    int N=0;
    eArchivo retor;//creo variable tipo enum

    Clases *ListaClases=new Clases[N];
    retor=LeerClases(archivoClase,ListaClases,N);

    REQUIRE(retor==1);
    archivoClase.close();
    delete[] ListaClases;
}
TEST_CASE("leer archivo de clientes", "[fancy]")
{
    //abro archivo de clientes
    ifstream archivoClientes;
    archivoClientes.open("iriClientesGYM.csv");
    int N=0;
    eArchivo ret;
    Cliente* ListaClientes=new Cliente[N];
    ret=LeerClientes(archivoClientes,ListaClientes,N);
    REQUIRE(ret==1);
    archivoClientes.close();
    delete[] ListaClientes;
}
TEST_CASE("escribir archivo de inscripcion", "[fancy]")
{
    string NombreArchivo="asistencia.dat";
    int Ninscripciones=7;
    Asistencia* AsistenciaMan=new Asistencia[Ninscripciones];
    eArchivo ret;
    ret=CrearAsistencia_manana(NombreArchivo,AsistenciaMan,Ninscripciones);
    REQUIRE(ret==1);
    delete[] AsistenciaMan;
}
TEST_CASE("Funcion Random", "[fancy]")
{
    //le paso algunos datos cargados de lista cliente y clases y me debe retornar algun valor random
    int N=3;
    Cliente* ListaClientes=new Cliente[N];
    Clases* ListaClase=new Clases[N];
    ListaClientes[0].idCliente=12;
    ListaClientes[1].idCliente=3;
    ListaClientes[2].idCliente=19;
    ListaClientes[3].idCliente=4;
    ListaClase[0].idClase=2;
    ListaClase[1].idClase=15;
    ListaClase[2].idClase=7;
    ListaClase[3].idClase=1;
    Asistencia* aux=new Asistencia;
    RandCliente(ListaClientes,N,N,ListaClase,aux);
    REQUIRE(0==0);
    delete aux;
    delete[] ListaClientes;
    delete[] ListaClase;
}
TEST_CASE("escribir archivo de inscripcion", "[fancy]")
{
    ifstream archivo_dia;
    archivo_dia.open("asistencias_1697673600000.dat", ios::binary);
    int N=0;
    eArchivo ret;
    Asistencia* AsistenciaDia=new Asistencia[N];
    ret=LeerAsistencia_hoy(archivo_dia,AsistenciaDia,N);
    REQUIRE(ret==1);
    archivo_dia.close();
    delete[] AsistenciaDia;
}

