package ar.edu.untref.dyasc;

import org.junit.Test;
import static org.assertj.core.api.Assertions.*;

public class GameTest {

	@Test
	public void cuandoEmpiezaElPartidoLosDosJugadoresTienenCeroPuntos() {

		Partido partido = new Partido();

		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(0);
		assertThat(puntosJugadorDos).isEqualTo(0);

	}

	@Test
	public void cuandoJugadorUnoHaceUnPuntoSeActualizaElPuntaje() {
		Partido partido = new Partido();

		partido.sumarPuntoJugadorUno();
		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(15);
		assertThat(puntosJugadorDos).isEqualTo(0);

	}

	@Test
	public void cuandoUnJugadorUnoHaceDosPuntosSeActualizaElPuntaje() {
		Partido partido = new Partido();

		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(30);
		assertThat(puntosJugadorDos).isEqualTo(0);
	}

	@Test
	public void cuandoUnJugadorUnoHaceDosPuntosYelOtroHaceUnoSeActualizaElPuntaje() {
		Partido partido = new Partido();

		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorDos();
		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(30);
		assertThat(puntosJugadorDos).isEqualTo(15);
	}

	@Test
	public void cuandoJugadorUnoHaceTresPuntosSeActualizaElPuntaje() {
		Partido partido = new Partido();

		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(40);
		assertThat(puntosJugadorDos).isEqualTo(0);
	}

	@Test
	public void cuandoJugadorDosHaceTresPuntosSeActualizaElPuntaje() {
		Partido partido = new Partido();

		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(0);
		assertThat(puntosJugadorDos).isEqualTo(40);
	}

	@Test
	public void cuandoJugadorUnoHaceUnGameSeActualizaElPuntaje() {
		Partido partido = new Partido();

		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();

		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int gamesJugadorUno = partido.obtenerGamesDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(0);
		assertThat(gamesJugadorUno).isEqualTo(1);
		assertThat(puntosJugadorDos).isEqualTo(0);
	}

	@Test
	public void cuandoJugadorDosHaceUnGameSeActualizaElPuntaje() {
		Partido partido = new Partido();

		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();

		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int gamesJugadorUno = partido.obtenerGamesDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();
		int gamesJugadorDos = partido.obtenerGamesDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(0);
		assertThat(gamesJugadorUno).isEqualTo(0);
		assertThat(puntosJugadorDos).isEqualTo(0);
		assertThat(gamesJugadorDos).isEqualTo(1);
	}
	
	@Test
	public void cuandoJugadorUnoHaceDosGamesSeActualizaElPuntaje() {
		Partido partido = new Partido();

		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		
		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int gamesJugadorUno = partido.obtenerGamesDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(0);
		assertThat(gamesJugadorUno).isEqualTo(2);
		assertThat(puntosJugadorDos).isEqualTo(0);
	}

	@Test
	public void cuandoJugadorDosHaceDosGamesSeActualizaElPuntaje() {
		Partido partido = new Partido();

		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();

		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int gamesJugadorUno = partido.obtenerGamesDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();
		int gamesJugadorDos = partido.obtenerGamesDeJugadorDos();

		assertThat(puntosJugadorUno).isEqualTo(0);
		assertThat(gamesJugadorUno).isEqualTo(0);
		assertThat(puntosJugadorDos).isEqualTo(0);
		assertThat(gamesJugadorDos).isEqualTo(2);
	}


}
