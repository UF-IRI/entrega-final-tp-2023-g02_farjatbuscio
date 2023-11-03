#include <catch2/catch.hpp>
#include "archivos.cpp"

/**********test leer archivo de clases**********/
TEST_CASE("leer archivo de clases", "[fancy]")
{
    //abro archivo de clases
    ifstream archivoClases;
    archivoClases.open("../Proyecto/iriClasesGYM.csv");
    int N=1;
    Clases *ListaClases=new Clases[N];
    Clases aux[2];
    aux[0].idClase=1;
    aux[1].idClase=2;
    aux[0].NombreClase="Spinning";
    aux[1].NombreClase="Spinning";
    aux[0].Horario=8;
    aux[1].Horario=10;
    LeerClases(&archivoClases,ListaClases,&N);
    for(int i=0;i<2;i++)
    {
      REQUIERE(ListaClases[i].idClase==aux[i].idClase && ListaClases[i].NombreClase==aux[i].NombreClase && ListaClases[i].Horario==aux[i].Horario);
    }
}
TEST_CASE("leer archivo de clientes", "[fancy]")
{
    //abro archivo de clientes
    ifstream archivoClientes;
    archivoClases.open("../Proyecto/iriClientesGYM.csv");
    int N=1;
    Cliente *ListaClientes=new Cliente[N];
    Cliente aux[2];
    aux[0].idCliente=1;
    aux[1].idCliente=2;
    aux[0].Nombre="AgustÃ­n";
    aux[1].Nombre="Emilio";
    aux[0].Horario=8;
    aux[1].Horario=10;
    LeerClases(&archivoClases,ListaClases,&N);
    for(int i=0;i<2;i++)
    {
      REQUIERE(ListaClases[i].idClase==aux[i].idClase && ListaClases[i].NombreClase==aux[i].NombreClase && ListaClases[i].Horario==aux[i].Horario);
    }
}
