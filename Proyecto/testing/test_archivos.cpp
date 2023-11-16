#include <catch2/catch.hpp>
#include <archivos.h>

using namespace std;

//test para leer archivos

TEST_CASE("leer archivo de clases", "[fancy]")
{
    //abro archivo de clases
    ifstream archivoClase;
    archivoClase.open("/../iriClasesGYM.csv");

    int N=1;

    Clases *ListaClases=new Clases[N];
    LeerClases(archivoClase,ListaClases,N);

    Clases aux[2];
    aux[0].idClase=1;
    aux[1].idClase=2;
    aux[0].NombreClase="Spinning";
    aux[1].NombreClase="Spinning";
    aux[0].Horario=8;
    aux[1].Horario=10;

    REQUIRE(ListaClases[0].idClase==aux[0].idClase);
    archivoClase.close();
    delete[] ListaClases;
}

TEST_CASE("leer archivo de clientes", "[fancy]")
{
    //abro archivo de clientes
    ifstream archivoClientes;
    archivoClientes.open("iriClientesGYM.csv");
    int N=1;

    Cliente *ListaClientes=new Cliente[N];
    Cliente aux[2];
    aux[0].idCliente=1;
    aux[1].idCliente=2;
    aux[0].Nombre="AgustÃ­n";
    aux[1].Nombre="Emilio";
    aux[0].Apellido="Guerra";
    aux[1].Apellido="Romero";
    LeerClientes(archivoClientes,ListaClientes,N);
    REQUIRE(ListaClientes[0].idCliente==aux[0].idCliente);

    archivoClientes.close();
    delete[] ListaClientes;
}
TEST_CASE("leer archivo de inscripcion", "[fancy]")
{
    //abro archivo de inscripcion
    ifstream archivoInscripcion;
    archivoInscripcion.open("asistencias_1697673600000.dat", ios::binary);

    int N=1;
    Asistencia* AsistenciaDia=new Asistencia[N];

    int ret= LeerAsistencia_hoy(archivoInscripcion,AsistenciaDia,N);
    REQUIRE(ret==1);

    archivoInscripcion.close();
    delete[] AsistenciaDia;
}
/*TEST_CASE("Funcion Random", "[fancy]")
{
    //le paso algunos datos cargados de lista cliente y clases y me debe retornar algun valor random
    //Asistencia RandCliente(Cliente* ListaClientes, Clases* ListaClase)
    int N=3;
    Cliente ListaClientes[N];
    int M=3;
    Clases ListaClase[M];
    ListaClientes[0].idCliente=12;
    ListaClientes[1].idCliente=3;
    ListaClientes[2].idCliente=19;
    ListaClientes[3].idCliente=4;
    ListaClase[0].idClase=2;
    ListaClase[1].idClase=15;
    ListaClase[2].idClase=7;
    ListaClase[3].idClase=1;
    Asistencia aux;
    aux=RandCliente(ListaClientes,ListaClase);
    REQUIRE(aux.idCliente==12);
}*/
/*TEST_CASE("Funcion imprimir", "[fancy]")
{
    int N=3;
    int id_clase=3;
    Asistencia* AsistenciaMan=new Asistencia [N];
    AsistenciaMan[0].idCliente=1;
    AsistenciaMan[0].CursosInscriptos->idCurso=3;
    AsistenciaMan[1].idCliente=2;
    AsistenciaMan[1].CursosInscriptos->idCurso=3;
    ImprimirDatos(AsistenciaMan,id_clase, N);
    REQUIRE(N==3);
}*/
