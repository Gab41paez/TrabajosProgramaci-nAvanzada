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