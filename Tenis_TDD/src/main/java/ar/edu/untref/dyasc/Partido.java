package ar.edu.untref.dyasc;

public class Partido {

	int puntajeJugadorUno;
	int gamesJugadorUno;
	int setsJugadorUno;
	int puntajeJugadorDos;
	int gamesJugadorDos;
	int setsJugadorDos;

	public Partido() {
		this.puntajeJugadorUno = 0;
		this.gamesJugadorUno = 0;
		this.setsJugadorUno = 0;
		this.puntajeJugadorDos = 0;
		this.gamesJugadorDos = 0;
		this.setsJugadorDos = 0;

	}

	public int obtenerPuntajeDeJugadorUno() {

		return this.puntajeJugadorUno;
	}

	public int obtenerPuntajeDeJugadorDos() {

		return this.puntajeJugadorDos;
	}

	public void sumarPuntoJugadorUno() {
		if (this.puntajeJugadorUno < 30) {
			this.puntajeJugadorUno += 15;

		} else if (this.puntajeJugadorUno == 30) {
			this.puntajeJugadorUno += 10;
		} else {
			this.puntajeJugadorUno = 0;
			this.gamesJugadorUno += 1;
			if (this.gamesJugadorUno == 6) {
				this.gamesJugadorUno = 0;
				this.setsJugadorUno += 1;
			}
		}

	}

	public void sumarPuntoJugadorDos() {
		if (this.puntajeJugadorDos < 30) {
			this.puntajeJugadorDos += 15;

		} else if (this.puntajeJugadorDos == 30) {
			this.puntajeJugadorDos += 10;
		} else {
			this.puntajeJugadorDos = 0;
			this.gamesJugadorDos += 1;
			if (this.gamesJugadorDos == 6) {
				this.gamesJugadorDos = 0;
				this.setsJugadorDos += 1;
			}
		}
	}

	public int obtenerGamesDeJugadorUno() {
		return this.gamesJugadorUno;
	}

	public int obtenerGamesDeJugadorDos() {
		return this.gamesJugadorDos;
	}

	public int obtenerSetsDeJugadorUno() {
		return this.setsJugadorUno;
	}

	public int obtenerSetsDeJugadorDos() {
		return this.setsJugadorDos;
	}

	public String obtenerGanador() {
		if (this.setsJugadorUno == 3) {
			return "Jugador Uno";
		} else if (this.setsJugadorDos == 3) {
			return "Jugador Dos";
		} else {
			return "Ninguno";
		}

	}

}
