package ar.edu.untref.dyasc;

import static org.assertj.core.api.Assertions.assertThat;

import org.junit.Test;

public class GanadorTest {

	@Test
	public void cuandoJugadorUnoHaceTresSetsGanaElPartido() {
		Partido partido = new Partido();

		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);

		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);

		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);
		sumarGameJugadorUno(partido);

		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		int gamesJugadorUno = partido.obtenerGamesDeJugadorUno();
		int setsJugadorUno = partido.obtenerSetsDeJugadorUno();
		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();
		String ganador = partido.obtenerGanador();

		assertThat(puntosJugadorUno).isEqualTo(0);
		assertThat(gamesJugadorUno).isEqualTo(0);
		assertThat(setsJugadorUno).isEqualTo(3);
		assertThat(puntosJugadorDos).isEqualTo(0);
		assertThat(ganador).isEqualTo("Jugador Uno");

	}

	@Test
	public void cuandoJugadorDosHaceTresSetsGanaElPartido() {
		Partido partido = new Partido();

		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);

		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);

		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);
		sumarGameJugadorDos(partido);

		int puntosJugadorDos = partido.obtenerPuntajeDeJugadorDos();
		int gamesJugadorDos = partido.obtenerGamesDeJugadorDos();
		int setsJugadorDos = partido.obtenerSetsDeJugadorDos();
		int puntosJugadorUno = partido.obtenerPuntajeDeJugadorUno();
		String ganador = partido.obtenerGanador();

		assertThat(puntosJugadorDos).isEqualTo(0);
		assertThat(gamesJugadorDos).isEqualTo(0);
		assertThat(setsJugadorDos).isEqualTo(3);
		assertThat(puntosJugadorUno).isEqualTo(0);
		assertThat(ganador).isEqualTo("Jugador Dos");
	}

	@Test
	public void cuandoNadieHizoTresSetsElGanadorEsNinguno() {
		Partido partido = new Partido();

		String ganador = partido.obtenerGanador();
		assertThat(ganador).isEqualTo("Ninguno");

	}

	private void sumarGameJugadorDos(Partido partido) {
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
		partido.sumarPuntoJugadorDos();
	}

	private void sumarGameJugadorUno(Partido partido) {
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
		partido.sumarPuntoJugadorUno();
	}

}
