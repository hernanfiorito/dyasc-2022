package ar.edu.untref.dyasc;

import static org.junit.Assert.*;

import org.junit.Test;

public class SerieFiboTest {

	@Test
	public void elFibonacciDeTresEsDos(){
		SerieFibo serie = new SerieFibo();
		
		assertEquals(2, serie.fibonacci(3));
	}

	@Test
	public void elFibonacciDeCincoEsCinco(){
		SerieFibo serie = new SerieFibo();
		
		assertEquals(5, serie.fibonacci(5));
	}
	
	@Test
	public void sumaVerticalDevuelveSumaEnLaLineaInferior(){
		SerieFibo serie = new SerieFibo();
		
		assertEquals("fibo<3>s:\n2", serie.sumaVertical(3));
	}
	
	@Test
	public void sumaHorizontalDevuelveSumaAcontinuacion(){
		SerieFibo serie = new SerieFibo();
		
		assertEquals("fibo<3>s: 2", serie.sumaHorizontal(3));
	}
}
