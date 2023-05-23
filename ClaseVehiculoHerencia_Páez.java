/*class Padre{
  //Método Show()
  void show(){
    System.out.println("Clase Padre: método show()");
  }
}
class Hija extends Padre{
  //Este método sobre-escribe el metodo show de la clase Padre
  @Override
  void show(){
    System.out.println("Clase Hija: método show()");
  }
}
class Over02 {
  public static void main(String[] args) {
    Padre objeto01 = new Padre();
    objeto01.show();
    Padre objeto02 = new Hija();
    objeto02.show();
  }
}
*/

class Padre{
  //Método Show()
  private void m1(){
    System.out.println("Desde el padre el m1()");
  }
  protected void m2(){
    System.out.println("Desde el padre el m2()");
  }
}
class Hija extends Padre{
  //Nuevo método m1(()how()
  //unico a la clase hija
  private void m1(){
    System.out.println("Desde la clase Hija m1()");
  }
  @Override
  public void m2(){
    System.out.println("Desde Hija m2()");
  }
}
//Driver class
class Over02{
  public static void main(String[] args){
    Padre obj01 = new Padre();
    obj01.m2();
    Padre obj02 = new Hija();
    obj02.m2();
   }    
  } 