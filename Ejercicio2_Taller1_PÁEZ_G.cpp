/*
Autor Gabriela Páez
Fecha 2-2023
Tema Taller 1
Se desea capturar los datos de los clientes para ser impreso en la factura. Se requiere
crear una estructura de datos, que encapsule los datos de los usuarios. Se requiere que
el uso de la estructura sea a través de punteros. Se requiere imprimir las facturas en
un fichero de texto.
Recomendaciones:
1.- Hacer funciones por separado
2.- Anunciar/Documentar acciones
3.- Identificar su fichero fuente .cpp
4.- Subir el fichero fuente a un repositorio.

*/
#include <iostream>
#include <string>
#include<ctime>
#include<fstream>
using namespace std;
//Structura con datos que iran en la factura.

struct S_clientes
{
 string nombre;
 string apellido;
 float precioTotal;
};
//Declaro la funcion de llenar el archivo
void f_LlenarDatosArchivo(S_clientes personas[], int tam);
int main()
{
  //Variables a usar
  int cantidad=0;
  //Se pide cantidad de facturas
  cout<<"Diga la cantidad de facturas que imprimirá ";
  cin>>cantidad;
  S_clientes personas[cantidad];
  f_LlenarDatosArchivo(personas, cantidad);

   
  return 0;
}
void f_LlenarDatosArchivo(S_clientes personas[], int tam)
{
  //Se crea archivo
  ofstream archivo_escritura("archivoFacturas.txt");
  //Se piedn datos
  if(archivo_escritura.is_open())
  {
    for(int i=0; i<tam; i++)
    {
      cout<<"Ingrese nombre: ";
      cin>> personas[i].nombre;
      archivo_escritura<<personas[i].nombre<<endl;
      cout<<"Ingrese apellido: ";
      cin>>personas[i].apellido;
      archivo_escritura<<personas[i].apellido<<endl;
      cout<<"Ingrese su precio total a pagar: ";
      cin>>personas[i].precioTotal;
      cout<<endl;
    }
  }
  else
  {
    cout<<"No tiene permiso para escritura";
  }
  //Se imprime los datos de los usuarios
  for(int i=0; i<tam; i++)
  {
    cout<<endl<<" Nombre "<<personas[i].nombre<<" "<<personas[i].apellido;
    cout<<endl<<" Precio "<<personas[i].precioTotal;
    cout<<endl;
  }
}