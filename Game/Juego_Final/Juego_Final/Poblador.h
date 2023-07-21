#pragma once
#include "Entidad.h"

class Poblador : public Entidad {
public:
	Poblador(Bitmap^ bm, float x, float y) : Entidad() {
		this->x = x;
		this->y = y;
		ancho = bm->Width / 4;
		alto = bm->Height / 4;
		tam = 0.8;
	}
	~Poblador() {}
	void Dibujar(Graphics^ g, Bitmap^ bm) {
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * tam, alto * tam);
		g->DrawImage(bm, zoom, sectionShown, GraphicsUnit::Pixel);
	}
	void Mover(Graphics^ g) {
		int i = rand() % 4;
		switch (i)
		{
		case 0: //Izq
			if (x > 0) {
				dx = 3;
				idy = 1; //Postura del personaje
			}
			break;

		case 1: //Derecha
			if (x + ancho * tam < g->VisibleClipBounds.Width) {
				dx = 3;
				idy = 2;
			}
			break;

		case 2: //Arriba
			if (y > 0) {
				dy = 3;
				idy = 3;
			}
			break;

		case 3: //Abajo
			if (y + alto * tam < g->VisibleClipBounds.Height) {
				dy = 3;
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
		return Rectangle(x, y, ancho * tam, alto * tam);
	}
};