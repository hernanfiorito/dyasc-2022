package ar.edu.untref.dyasc;

import static org.junit.Assert.*;

import org.junit.Test;

public class FibonacciTest {

	@Test
	public void cuandoOpcionEsHdSeObtieneEnHorizontalDirecta() {
		Fibonacci fibo = new Fibonacci();
		SerieFibo serie = new SerieFibo();
		assertEquals("fibo<3>: 0 1 1", fibo.imprimirOpcion("-o=hd", 3, serie));

	}

	@Test
	public void cuandoOpcionEsHiSeObtieneEnHorizontalInversa() {
		Fibonacci fibo = new Fibonacci();
		SerieFibo serie = new SerieFibo();
		assertEquals("fibo<3>: 1 1 0", fibo.imprimirOpcion("-o=hi", 3, serie));

	}

	@Test
	public void cuandoOpcionEsVdSeObtieneEnVerticalDirecta() {
		Fibonacci fibo = new Fibonacci();
		SerieFibo serie = new SerieFibo();
		assertEquals("fibo<3>:\n" + "0\n" + "1\n" + "1", fibo.imprimirOpcion("-o=vd", 3, serie));
	}
	
	@Test
	public void cuandoOpcionEsViSeObtieneEnVerticalInversa() {
		Fibonacci fibo = new Fibonacci();
		SerieFibo serie = new SerieFibo();
		assertEquals("fibo<3>:\n" + "1\n" + "1\n" + "0", fibo.imprimirOpcion("-o=vi", 3, serie));
	}
	
	@Test
	public void cuandoOpcionEsIncorrectaSeObtieneOpcionNoValida() {
		Fibonacci fibo = new Fibonacci();
		SerieFibo serie = new SerieFibo();
		assertEquals("Opción no válida.", fibo.imprimirOpcion("-o=vv", 3, serie));
	}
	
}
