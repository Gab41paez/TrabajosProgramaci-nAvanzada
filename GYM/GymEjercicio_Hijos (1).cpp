#include<iostream>
#include<string>
using namespace std;
/*
Fecha: Enero 30 del 2023- versión
Autor: Gabriela Páez
Problema:
-"Se tiene un gymnasio que requiere un
  sistema informático para capturar los datos de sus
  clientes"
  -Se crea un struct para hacer el tipo de dato que capture los datos
  -Se presenta que por cada dato se imprime la pregunta y se captura.
  -Se pide datos de los hijos de los usarios del gym  y se presenta ek nombre de los usuarios registrados satisfactiriamente.
  -Solución
    -se hará un TDA general para la captura de datos del usuario.
    -Se hará un TDA anidado, para la capturra de datos de los hijos.
    -Se presentará todos los anuncios posibles descriptivos.
*/
//Se crea un TDA para la captura de usarios de gym
struct S_DatosGym
{
	string nombre;
	int Edad;
	int CC;
	float MasaCorporal;
	char Genero;
  string Correo;
	long int movil;
	int Hijos;
	string Direccion;
//Anido TDA para la captura de datos de los hijos
   struct S_DatosHijos
   {
     int cantidadA;
     int CedulaA;
   };
//Variable para llamar la estructura anidada
S_DatosHijos InfoHijos;
};

int main()
{
    int cantidadClientes;
    
    cout<<"¿Cuantos clientes va a registrar?"<<endl;
    cin>>cantidadClientes;
    S_DatosGym informacion[cantidadClientes];

    for(int i=0; i<cantidadClientes; i++)
    {
    cout<<endl<<" Escriba su nombre ";
    cin>>informacion[i].nombre;
    //getline(cin, informacion.nombre);
    cout<<endl<<" Escriba su edad ";
    cin>>informacion[i].Edad;
    cout<<endl<<" Escriba su cédula ";
    cin>>informacion[i].CC;
    cout<<endl<<" Escriba su peso ";
    cin>>informacion[i].MasaCorporal;
    cout<<endl<<" Escriba su género(una sola letra) ";
    cin>>informacion[i].Genero;
    cout<<endl<<" Escriba su correo ";
    cin>>informacion[i].Correo;
    cout<<endl<<" Escriba su número telefónico ";
    cin>>informacion[i].movil;
    cout<<endl<<" Escriba su dirección ";
    cin>>informacion[i].Direccion;
    //getline(cin, informacion.Direccion);
    cout<<endl<<" Si tiene hijos ponga 0, sino ponga 1 ";
    cin>>informacion[i].Hijos;
      if(informacion[i].Hijos==0)
      {
        cout<<endl<<" ¿Cuantos hijos tiene? ";
        cin>>informacion[i].InfoHijos.cantidadA;
        cout<<endl<<" Escriba la cedula de su hije ";
        cin>>informacion[i].InfoHijos.CedulaA;
      }
    cout<<endl;
    cout<<"Los datos de "<<informacion[i].nombre<< " han sido tomados con exito.--Persona "<<i+1;
      cout<<endl;
    }
return 0;
}