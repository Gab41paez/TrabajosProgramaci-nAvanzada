/*
Autor Gabriela Páez
Fecha 2-2023
Tema Taller 1 
Ejercicio 01:
1.- Crear un array con 10 elementos
2.- Crear una función para generar números aleatorios entre 0 y 25
3.- Llenar el array con 10 números aleatorios
4.- Crear un puntero
5.- Imprimir el contenido del array usando el puntero
6.- Imprimir las direcciones del contenido del array usando el puntero.

*/
#include <iostream>
#include <vector> 
using namespace std;
void f_aleatorio(int aleatorio[]);
int main() 
{
  //Creación de arreglo con 10 elementos
  vector<int>vector01(10);
  //Creación de variabeles.
  int numA[10];
  //creo puntero
  int *apuntador=&numA[0];
  //apuntador=numA; Es lo mismo.
  f_aleatorio(numA);
  cout<<endl;
  //Imprimo el arreglo por medio de pauntadores.
    for(int i=0; i<10; i++)
    {
      //Se imprime, desde la pos 0 hasta llegar a 10 aumentado uno.
      cout<<"El vector contiene["<<i<<"] _ "<<*apuntador++<<endl;
    }
  //Imprimo las direcciones del contenido del array usando el puntero.
  cout<<endl;
    for(int i=0; i<10; i++)
    {
      //
      cout<<"Las direcciones del arreglo son "<<numA[i]<<" "<<apuntador++<<endl;
    }  
  return 0;
}

void f_aleatorio(int aleatorio[])
{
  int datos;
  int mayor;
  srand(time(NULL));
  for(int i=0;i<10;i++)
  {
    aleatorio[i] = rand()%25;
    cout<<aleatorio[i]<<endl;
  }
}