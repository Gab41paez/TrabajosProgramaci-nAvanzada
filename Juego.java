import java.util.Random;
import java.util.Scanner;

public class Ahorcado {
    private static final String[] palabras = {"profesor", "computadora", "programacion", "java", "poo"};
    private static final int errores= 8;

    public static void main(String[] args) {
        
        Random random = new Random();
        int i = random.nextInt(palabras.length);
        String palabraSeleccionada = palabras[i];


        char[] letrasAdivinadas = new char[palabraSeleccionada.length()];
        for (int j = 0; j< letrasAdivinadas.length; j++) {
            letrasAdivinadas[j] = '_';
        }

        
        int numeroErrores = 0;
        int letrasCorrectas= 0;

        Scanner scanner = new Scanner(System.in);

       
        while (numeroErrores < errores && letrasCorrectas< palabraSeleccionada.length()) {
          
            System.out.println(letrasAdivinadas);

            
            System.out.print("Ingresa una letra: ");
            char letraIngresada = scanner.nextLine();

 
            boolean letraCorrecta = false;
            for (int k= 0; k < palabraSeleccionada.length(); k++) {
                if (palabraSeleccionada.charAt(i) == letraIngresada) {
                    letrasAdivinadas[i] = letraIngresada;
                    letraCorrecta = true;
                    letrasCorrectas++;
                }
            }

           
            if (!letraCorrecta) {
                numeroErrores++;
                System.out.println("Letra incorrecta. Llevas " + numeroErrores + " errores.");
            }
        }

      
        if (letrasCorrectas == palabraSeleccionada.length()) {
            System.out.println("¡Felicidades! Adivinaste la palabra " + palabraSeleccionada + "!");
        } else {
            System.out.println("Lo siento, has perdido. La palabra era " + palabraSeleccionada + ".");
        }
    }
}