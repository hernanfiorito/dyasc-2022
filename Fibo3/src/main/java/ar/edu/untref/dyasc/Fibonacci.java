package ar.edu.untref.dyasc;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Fibonacci {

	public static void main(String[] args) {
		SerieFibo fibo = new SerieFibo();
		
		//Imprimir para un argumento
		if (args.length == 1) {
			int n = Integer.parseInt(args[0]);
			System.out.println(fibo.horizontalDirecta(n));
		
		//Imprimir para dos argumentos
		} else if (args.length == 2) {
			int n = Integer.parseInt(args[1]);
			System.out.println(imprimirOpcion(args[0], n, fibo));
			
		//Imprimir para tres argumentos
		} else if (args.length == 3 && args[1].equals("-m=s")) {
			int n = Integer.parseInt(args[2]);
			if(args[0].charAt(3)== 'h') {
				System.out.println(fibo.sumaHorizontal(n));
			} else {
				System.out.println(fibo.sumaVertical(n));
			}

		} else if (args.length == 3 && args[1].equals("-m=l")) {
			int n = Integer.parseInt(args[2]);
			System.out.println(imprimirOpcion(args[0], n, fibo));
			
		} else if(args.length == 3 && args[1].substring(0,1).equals("-f")) {
			int n = Integer.parseInt(args[2]);
			String nombreArchivo = args[1].substring(2); 
			escribirOpcion(args[0], n, fibo, nombreArchivo);
			System.out.println("fibo<" + n + "> guardado en " + nombreArchivo);
		
		//Imprimir para cuatro argumentos
		} else if(args.length == 4 && args[1].substring(0,1).equals("-f") && args[2].equals("-m=s")) {
			int n = Integer.parseInt(args[3]);
			String nombreArchivo = args[1].substring(2);
			escribirSuma(n, args[0], fibo, nombreArchivo);
			System.out.println("fibo<" + n + "> guardado en " + nombreArchivo);			
			
		} else if(args.length == 4 && args[1].substring(0,1).equals("-f") && args[2].equals("-m=l")) {
			int n = Integer.parseInt(args[3]);
			String nombreArchivo = args[1].substring(2);
			escribirOpcion(args[0], n, fibo, nombreArchivo);
			System.out.println("fibo<" + n + "> guardado en " + nombreArchivo);
			
		} else {
			System.out.println("Opción no válida.");
		}

	}

	/* n: cantidad de fibonaccis, o: opcion de impresion seleccionada
	 * fibo: objeto SerieFibo que realiza la operación
	 * nombreArchivo: nombre del archivo que se creará
	 * 
	 * Escribe un archivo con la suma de los fibonaccis segín la opción seleccionada.
	 * */
	static void escribirSuma(int n, String o, SerieFibo fibo, String nombreArchivo) {
		File archivo = new File(nombreArchivo);
		try {
			FileWriter escribir = new FileWriter(archivo);
			if(o.charAt(3)== 'h') {
				escribir.write(fibo.sumaHorizontal(n));
			} else {
				escribir.write(fibo.sumaVertical(n));
			}
			
			escribir.close();
			
		} catch (IOException e) {
			System.out.println("Error al escribir");
		}
		
	}

	/* n: cantidad de fibonaccis, o: opcion de impresion seleccionada
	 * fibo: objeto SerieFibo que realiza la operación
	 * nombreArchivo: nombre del archivo que se creará
	 *  
	 *Escribe un archivo con la lista de fibonaccis segun la opción seleccionada.
	 * */
	static void escribirOpcion(String o, int n, SerieFibo fibo, String nombreArchivo) {
		File archivo = new File(nombreArchivo);
		try {
			FileWriter escribir = new FileWriter(archivo);
			escribir.write(imprimirOpcion(o, n, fibo));
			escribir.close();
			
		} catch (IOException e) {
			System.out.println("Error al escribir");
		}
		
		
		
	}
	
	/* o: opcion de impresión seleccionada, n: cantidad de fibonaccis
	 * fibo: objeto SerieFibo que realiza la operación
	 * 
	 * Imprime los fibonaccis según la opción seleccionada.
	 */
	static String imprimirOpcion(String o, int n, SerieFibo fibo) {
		String resultado;
		switch (o) {

		case "-o=hd":
			resultado = fibo.horizontalDirecta(n);
			break;

		case "-o=hi":
			resultado = fibo.horizontalInversa(n);
			break;

		case "-o=vd":
			resultado = fibo.verticalDirecta(n);
			break;

		case "-o=vi":
			resultado = fibo.verticalInversa(n);
			break;

		default:
			resultado = "Opción no válida.";
			break;

		}
		return resultado;
	}

}
