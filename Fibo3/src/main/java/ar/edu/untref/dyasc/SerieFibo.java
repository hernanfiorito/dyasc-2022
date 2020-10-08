package ar.edu.untref.dyasc;

public class SerieFibo {

	public int fibonacci(int n) {
		if (n == 0) {
			return 0;
		} else if (n == 1) {
			return 1;
		} else {
			return fibonacci(n - 1) + fibonacci(n - 2);
		}
	}

	public String horizontalDirecta(int n) {
		String resultado = "fibo<" + n + ">:";
		for (int i = 0; i < n; i++) {
			resultado = resultado + " " + fibonacci(i);
		}
		return resultado;

	}

	public String horizontalInversa(int n) {
		String resultado = "fibo<" + n + ">:";
		for (int i = n - 1; i >= 0; i--) {
			resultado = resultado + " " + fibonacci(i);
		}
		return resultado;
	}

	public String verticalDirecta(int n) {
		String resultado = "fibo<" + n + ">:";
		for (int i = 0; i < n; i++) {
			resultado = resultado + "\n" + fibonacci(i);
		}
		return resultado;
	}

	public String verticalInversa(int n) {
		String resultado = "fibo<" + n + ">:";
		for (int i = n - 1; i >= 0; i--) {
			 resultado = resultado + "\n" + fibonacci(i);
		}
		return resultado;
	}

	public String sumaVertical(int n) {
		int suma=0;
		for (int i = 0; i < n; i++) {
			suma = suma + fibonacci(i);
		}
		String resultado = "fibo<" + n + ">" + "s:" + "\n" + suma;
		return resultado;

	}

	public String sumaHorizontal(int n) {
		int suma=0;
		for (int i = 0; i < n; i++) {
			suma = suma + fibonacci(i);
		}
		String resultado = "fibo<" + n + ">" + "s: " + suma;
		return resultado;

	}
}
