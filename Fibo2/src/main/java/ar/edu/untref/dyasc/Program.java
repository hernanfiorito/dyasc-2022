package ar.edu.untref.dyasc;

public class Program {

	public static void main(String[] args) {

		if (args.length == 1) {
			int n = Integer.parseInt(args[0]);
			horizontalDirecta(n);
			
		} else if (args.length == 2) {
			int n = Integer.parseInt(args[1]);

			if (args[0].equals("-o=vd")) {
				verticalDirecta(n);
			} else if (args[0].equals("-o=hd")) {
				horizontalDirecta(n);

			} else if (args[0].equals("-o=vi")) {
				verticalInversa(n);

			} else if (args[0].equals("-o=hi")) {
				horizontalInversa(n);

			} else {
				System.out.println("Opción no válida.");

			}

		}

	}

	private static void horizontalInversa(int n) {
		String resultado = "fibo<" + n + ">: ";
		for (int i = n - 1; i >= 0; i--) {
			resultado = resultado + fibonacci(i) + " ";
		}
		System.out.println(resultado);
	}

	private static void verticalInversa(int n) {
		System.out.println("fibo<" + n + ">:");
		for (int i = n - 1; i >= 0; i--) {
			System.out.println(fibonacci(i));
		}
	}

	private static void verticalDirecta(int n) {
		System.out.println("fibo<" + n + ">:");
		for (int i = 0; i < n; i++) {
			System.out.println(fibonacci(i));
		}
	}

	private static void horizontalDirecta(int n) {
		String resultado = "fibo<" + n + ">: ";
		for (int i = 0; i < n; i++) {
			resultado = resultado + fibonacci(i) + " ";
		}
		System.out.println(resultado);
	}

	public static int fibonacci(int n) {
		if (n == 0) {
			return 0;
		} else if (n == 1) {
			return 1;
		} else {
			return fibonacci(n - 1) + fibonacci(n - 2);
		}

	}

}
