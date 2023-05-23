import java.util.ArrayList;
import java.util.Scanner;

abstract class ConjuntoDeDatos{

  private String nombre;
  private int tamanho;//Número de elementos en el conjunto de datos.
  
  public ConjuntoDeDatos(String nombre, int tamanho){//CONSTRUCTOR
  this.nombre = nombre;
  this.tamanho = tamanho;
  }
//Getters and Setters

  public String getNombre(){
  return nombre;
  }
  
  public void setNombre(String nombre){
  this.nombre = nombre;
  }
  
  public int getTamanho(){
  return tamanho;
  }
  
  public void setTamanho(int tamanho){
  this.tamanho = tamanho;
  }
  
  abstract String describir();
  
}

class ConjuntoDeDatosTabular extends ConjuntoDeDatos{

  int numeroDeColumnas;
  int numeroDeFilas;
  //CONSTRUCTOR
  public ConjuntoDeDatosTabular(String nombre, int tamanho,int numeroDeColumnas,int numeroDeFilas){

  super(nombre,tamanho);
  this.numeroDeColumnas = numeroDeColumnas;
  this.numeroDeFilas = numeroDeFilas;
  
  }
  
  //Getters and Setters
  
  public int getnumeroDeColumnas(){
  return numeroDeColumnas;
  }
  
  public void setNumeroDeColumnas(int numeroDeColumnas){
  this.numeroDeColumnas= numeroDeColumnas;
  }
  
  public int getnumeroDeFilas(){
  return numeroDeFilas;
  }
  
  public void setnumeroDeFilas(int numeroDeFilas){
  this.numeroDeFilas = numeroDeFilas;
  }
  
  @Override //Método abstracto
  String describir(){
  return "Nombre " + getNombre() + "Total de elementos del conjunto de datos" + getTamanho() + getnumeroDeColumnas() + getnumeroDeFilas();
//Tipo Tabular
  }
}

class ConjuntoDeDatosImagen extends ConjuntoDeDatos{

  private int ancho;
  private int alto;
  
  public ConjuntoDeDatosImagen(String nombre, int tamanho,int ancho, int alto){
  super(nombre,tamanho);
  this.ancho = ancho;
  this.alto = alto; 
  }  
  
  //Getters and Setters
  
  public int getAncho(){
  return ancho;
  }
  
  public void setAncho(int ancho){
  this.ancho= ancho;
  }
  
  public int getAlto(){
  return alto;
  }
  
  public void setAlto(int alto){
  this.alto= alto;
  }
  
  @Override 
  String describir(){ //Método abstracto
  return "Nombre " + getNombre() + "Total de elementos del conjunto de datos" + getTamanho() + getAncho() + getAlto();
  // ACA SIEMPRE VA A SER DE TIPO IMAGEN POR QUE EL METODO SE ESTA SOBREECRIBIENDO EN LA CLAS IMAGEN
  }
}

class AnalizadorDeDatos extends ConjuntoDeDatos {
   
  private ArrayList<ConjuntoDeDatos> listaConjDatos; // Atributo listaConjDatos de tipo ArrayList

  public AnalizadorDeDatos(String nombre, int tamanho, ArrayList<ConjuntoDeDatos> listaConjDatos) {
    super(nombre, tamanho);
    this.listaConjDatos = listaConjDatos;
  }
  
  public void anadirConjuntoDeDatos(int numeroDeColumnas, int numeroDeFilas) {
    ConjuntoDeDatos nuevoConjunto = new ConjuntoDeDatosTabular(" ", 0, numeroDeColumnas, numeroDeFilas);
    listaConjDatos.add(nuevoConjunto);
  }
    
  public void eliminarConjuntoDeDatos() {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Ingrese el nombre del Conjunto de datos que va a eliminar");
    String nombre = scanner.nextLine();
  
    boolean estaContenido = false;
    
    for (ConjuntoDeDatos conjunto : listaConjDatos) {
      if (conjunto.getNombre().equals(nombre)) {
        estaContenido = true;
        listaConjDatos.remove(conjunto);
        System.out.println("Conjunto eliminado: " + conjunto.getNombre());
        break;
      }
    }
    
    if (!estaContenido) {
      System.out.println("No se encontró el conjunto de datos: " + nombre);
    }
  }
  
  public ArrayList<String> describirConjuntoDeDatos() {
    ArrayList<String> resultados = new ArrayList<>();
  
    for (ConjuntoDeDatos conjunto : listaConjDatos) {
      String descripcion = conjunto.describir();
      resultados.add(descripcion);
    }
    
    return resultados;
  }
  
  @Override
  public String describir() {
    ArrayList<String> descripciones = describirConjuntoDeDatos();
    StringBuilder resultado = new StringBuilder("Descripción del analizador de datos:\n");
    
    for (String descripcion : descripciones) {
      resultado.append(descripcion).append("\n");
    }
    
    return resultado.toString();
  }
}

public class Parcial {
  public static void main(String[] args) {
    ArrayList<ConjuntoDeDatos> listaConjDatos = new ArrayList<>();

    ConjuntoDeDatos DatosDeEstudiantes00 = new ConjuntoDeDatosTabular("Datos de estudiantes", 1000, 200, 5);
    ConjuntoDeDatos ImagenesDeSatelite01 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);
    ConjuntoDeDatos ImagenesDeSatelite02 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);

    listaConjDatos.add(DatosDeEstudiantes00);
    listaConjDatos.add(ImagenesDeSatelite01);
    listaConjDatos.add(ImagenesDeSatelite02);

    AnalizadorDeDatos analizador = new AnalizadorDeDatos("Analizador", 3000, listaConjDatos);

    System.out.println(analizador.describir());
  }
}