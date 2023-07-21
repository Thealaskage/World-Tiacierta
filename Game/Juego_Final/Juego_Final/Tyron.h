#pragma once
#include "Entidad.h"

class Tyron : public Entidad {
private:
	unsigned int hp;
	int contPobSalvados;
	unsigned int gameTime;
public:
	Tyron(Bitmap^ bm) : Entidad() {
		x = 450;
		y = 240;
		dx = dy = 5;
		ancho = bm->Width / 4.0;
		alto = bm->Height / 4.0;
		tam = 0.8;
		hp = 5;
		contPobSalvados = 0;
		gameTime = 50;
	}

	~Tyron() {}

	void Dibujar(Graphics^ g, Bitmap^ bm) { //Graphics -> Canvas // Bitmap -> Image
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);//Seccion a mostrar
		Rectangle zoom = Rectangle(x, y, ancho * tam, alto * tam);//Zoom
		g->DrawImage(bm, zoom, sectionShown, GraphicsUnit::Pixel);//Dibujar
	}

	void Mover(Graphics^ g, char tecla) {
		switch (tecla)
		{
		case 'A': //Izq
			if (x > 0) {
				x -= dx; //Movimiento
				idy = 1; //Postura del personaje
			}
			break;

		case 'D': //Derecha
			if (x + ancho * tam < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
			}
			break;

		case 'W': //Arriba
			if (y > 0) {
				y -= dy;
				idy = 3;
			}
			break;

		case 'S': //Abajo
			if (y + alto * tam < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}
			break;
		}
		//Animación
		idx++;
		if (idx > 3) {
			idx = 0;
		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * tam / 1.5, alto * tam / 1.5);
	}
	int getHp() {
		return hp;
	}
	int getContPoblSal() {
		return contPobSalvados;
	}
	void ReducirVida() {
		hp--;
	}

	void AumentarContPoblSalv() {
		contPobSalvados++;
	}
	void AumentarVelocidad() {
		dx++;
		dy++;
	}
	void ReducirVelocidad() {
		dx--;
		dy--;
	}
	void Redireccion() {
		x = 450;
		y = 240;
	}
	void ReducirGameTime() {
		gameTime--;
	}
	int getGameTime() {
		return gameTime;
	}
};