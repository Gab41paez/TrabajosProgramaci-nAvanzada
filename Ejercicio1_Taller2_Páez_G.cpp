#include <iostream>
#include <cstdlib>
using namespace std;

struct S_datosnumA
{
 int tamConAleatorios;
 int numMax;
 int conjunto[];
};


void f_aleatorio(S_datosnumA aleatorio);
void mostrarHistograma(int numeros[],S_datosnumA aleatorio);
void f_histograga(S_datosnumA histograma);

int main() 
{
  S_datosnumA numA;
  S_datosnumA his;
  
  f_aleatorio(numA);
  
return 0;
}

void f_aleatorio(S_datosnumA aleatorio)
{
  S_datosnumA datos;
  int mayor;
  srand(time(NULL));
  for(int i=0;i<15;i++)
  {
    aleatorio.conjunto[i] = rand()%20;
    cout<<aleatorio.conjunto[i]<<endl;
  }
  //Busco el número mayor
  for(int i=0; i<15; i++)
  {
     if(aleatorio.conjunto[i]>mayor) 
     mayor=aleatorio.conjunto[i]; 
     cout<<mayor;
  }
//return datos;
}
void mostrarHistograma(int numeros[],S_datosnumA aleatorio) 
{
    int frecuencia[21] = {0};  // Inicializar el arreglo de frecuencias en cero
    for (int i = 0; i < 15; i++)
    {
      frecuencia[numeros[i]]++;  // Incrementar la frecuencia del número correspondiente
    }
    cout << "Histograma: "<<endl;
    
    for (int i = 0; i < 25; i++) {
        cout << i << ": ";
        
        for (int j = 0; j < frecuencia[i]; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}