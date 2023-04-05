#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//Clase circulo que calcula el area, perimetro y el diámetro.
class c_circulo
{
 private:
 float radio;
//Metodos
 public:
 const float pi=3.1314;
 void f_PedirDatoRadio()
 {
  cout<<"¿Que radio tiene el circulo?  ";
  cin>>radio;
 };
  void f_area()
  {
    int area=0;
    area=pi*pow(radio, 2);
    cout<<"El area del circulo es "<<area<<endl;
    
  };
  void f_perimetro()
  {
    int perimetro=0;
    perimetro=pi*(2*radio);
    cout<<"El perimetro del circulo es "<<perimetro<<endl;
    
  };
  void f_diametro()
  {
    int diametro=0;
    diametro=radio*2;
    cout<<"El diametro del circulo es "<<diametro<<endl;  
  }
};
//Clase para el triangulo, se pude calcular el el perimetro la hipotenusa y la altura.
class c_triangulo
{
 private:
  float ladoOpuesto;
  float ladoAdyacente;
 public:
//Float hipotenusa es global por que se usa en dos funciones.
  float hipotenusa;
  void f_pedirLados()
  {
      cout<<"Ingrese el valor del cateto opuesto: ";
      cin>>ladoOpuesto;
      cout<<"Ingrese el valor del cateto adyacente: ";
      cin>>ladoAdyacente;
  };

  void f_altura()
  {
    cout<<"La altura de triangulo rectangulo es: "<<ladoAdyacente<<endl;
  };

  void f_hipotenusa()
  {
    //Raiz de cateto opuesto a cuadradro mas el cateto adyacente al cuadrado
      hipotenusa=sqrt(pow (ladoOpuesto,2) + pow(ladoAdyacente,2));
      cout <<"La hipoteenusa del triangulo es "<< hipotenusa<<endl;
  };

  void f_perimetro()
  {
      float perimetro;
      perimetro=ladoAdyacente+hipotenusa+ladoOpuesto;
      cout <<"El perimetro del triangulo es "<<perimetro<<endl;
  };
};
//Clase persona
class c_persona
{
  protected:
    string nombre;
    int edad;
    int curso;
    string especialidad;

  public:
    void f_datosPersona()
    {
      cout<< "Ingrese su nombre ";
      cin >> nombre;
      cout<< "Ingrese su edad ";
      cin >> edad;
    } 

    void f_presentarse()
    {
      cout << "¡Hola! Soy "<< nombre<< ", tengo "<< edad<<"  años de vida, estoy dispuesto/a a ayudar en lo que pueda y a compartir mi experiencia y conocimientos."<<endl;
    }
};

class c_estudiante : public c_persona 
{
  public:
    void f_datosPerEstudiante()
    {
      cout<<"Ingrese su nombre ";
      cin>>nombre;
      cout<<"Ingrese su edad ";
      cin>>edad;
      cout<<"Ingrese su curso ";
      cin>>curso;
    } 
    void f_inscribirProgramacion()
    {
      if (curso>9){
        cout <<"Puede inscribir la materia de programación."<<endl;
      }else{
        cout <<"No puede inscribir programación, porque usted esta en un curso menor a noveno grado."<<endl;
      }
    }
};

class c_profesor : public c_persona
{
  public:
    void f_datosPerProfesor()
    {
      cout<<"Ingrese su nombre ";
      cin>>nombre;
      cout<<"Ingrese su edad ";
      cin>>edad;
      cout<<"Ingrese su especialidad_ejm(Profesor de matematicas,física, religión, etc.) ";
      cin>>especialidad;
    } 
};
//Función principal
int main()
{
  //Variable boleana para el while del switch persona
  bool seguir=true;
  int opcion;//Para el switch
  //Creo una variable tipo clase
  c_circulo circulo;
  c_triangulo triangulo;
  c_persona usuario;
  c_estudiante estudiante;
  c_profesor profesor;
  //Llamar funciones de la cada objeto

  //Para el circulo
  cout<<"-Se calculará el área, perimétro y diámetro de un circulo"
  <<endl<<endl;  
  circulo.f_PedirDatoRadio();
  cout<<endl<<endl;

  circulo.f_area();
  cout<<"...................................................................."<<endl;
  circulo.f_perimetro();
  cout<<"...................................................................."<<endl;
  circulo.f_diametro();
    cout<<"...................................................................."<<endl;
  //Para el triángulo
cout<<endl<<endl;
  cout<<"Se calculará la altura, hipotenusa y perimétro de un triángulo."
  <<endl<<endl;
 
  triangulo.f_pedirLados();
  cout<<endl<<endl;
  
  triangulo.f_altura();
  cout<<"...................................................................."<<endl;
  triangulo.f_hipotenusa();
  cout<<"...................................................................."<<endl;
  triangulo.f_perimetro();
  cout<<"...................................................................."<<endl;
  cout<<endl<<endl;
  //Para la persona / estudiante / profesor.
  while(seguir=true)
  {
    cout<<"1.Persona\n2.Estudiante\n3.Profesor\n4.Salir"<<endl<<endl;
    cin>>opcion;
    cout<<endl;
    switch(opcion)
    {
      case 1:
        usuario.f_datosPersona();
        cout<<endl<<endl;
        usuario.f_presentarse();
        cout<<endl<<endl;   
      break;
      case 2:
        estudiante.f_datosPerEstudiante();
        cout<<endl<<endl;
        estudiante.f_presentarse(); 
        cout<<endl<<endl;
        estudiante.f_inscribirProgramacion();
        cout<<endl<<endl;
      break;
      case 3:
        profesor.f_datosPerProfesor();
        cout<<endl<<endl;
        profesor.f_presentarse();
        cout<<endl<<endl;
      break;
      case 4:
      seguir=false;
      break;

      default:
      cout<<"Opcion no valida"<<endl;  
    }
    seguir=false;
  }
  return 0;
}