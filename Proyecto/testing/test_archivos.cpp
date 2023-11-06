#include <catch2/catch.hpp>
#include <archivos.h>

using namespace std;

/**********test leer archivo de clases**********/

TEST_CASE("leer archivo de clases", "[fancy]")
{
    //abro archivo de clases
    std::ifstream archivoClase("../../../iriClasesGYM.csv");

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
}

TEST_CASE("leer archivo de clientes", "[fancy]")
{
    //abro archivo de clientes
    ifstream archivoClientes;
    archivoClientes.open("../../../iriClientesGYM.csv");
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
}
