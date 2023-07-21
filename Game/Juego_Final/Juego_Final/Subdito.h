#pragma once
#include "Entidad.h"
#include "Tyron.h"
#include "Poblador.h"

class Subdito : public Entidad {
private:
	int tipo;
public:
	Subdito(Bitmap^ bm, float x, float y, int tipo) : Entidad() {
		this->x = x;
		this->y = y;
		dx = dy = 5;
		ancho = bm->Width / 2.0;
		alto = bm->Height / 4.0;
		this->tipo = tipo;
		tam = 0.8;
	}
	~Subdito() {}

	void Dibujar(Graphics^ g, Bitmap^ bm) { //Graphics -> Canvas // Bitmap -> Image
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);//Seccion a mostrar
		Rectangle zoom = Rectangle(x, y, ancho * tam, alto * tam);//Zoom
		g->DrawImage(bm, zoom, sectionShown, GraphicsUnit::Pixel);//Dibujar
	}

	void Mover(Graphics^ g) {
		switch (tipo) {
		case 0: //Der
			if (x + ancho * tam > g->VisibleClipBounds.Width || x < 0) dx *= -1;
			if (dx > 0) {
				idy = 2;
			}
			else {
				idy = 3;
			}
			x -= dx;
			break;

		case 1: //Iz
			if (x + ancho * tam > g->VisibleClipBounds.Width || x < 0) dx *= -1;
			if (dx > 0) {
				idy = 3;
			}
			else {
				idy = 2;
			}
			x += dx;
			break;

		case 2: //Arr
			if (y + alto * tam > g->VisibleClipBounds.Height || y < 0) dy *= -1;
			if (dy > 0) {
				idy = 1;
			}
			else {
				idy = 0;
			}
			y -= dy;
			break;

		case 3: //Abaj
			if (y + alto * tam > g->VisibleClipBounds.Height || y < 0) dy *= -1;
			if (dy > 0) {
				idy = 0;
			}
			else {
				idy = 1;
			}
			y += dy;
			break;

		}
		idx++;
		if (idx > 1)idx = 0;
	}


	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * tam/1.5, alto * tam/1.5);
	}
	Rectangle getRectangle2() {
		return Rectangle(x, y, ancho * tam, alto * tam);
	}

	void Rebote() {
		switch (tipo) {
		case 0: dx *= -1; break;
		case 1: dx *= -1; break;
		case 2: dy *= -1; break;
		case 3: dy *= -1; break;
		}
	}

};