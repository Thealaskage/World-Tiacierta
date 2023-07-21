#pragma once

using namespace System::Drawing;

class Fondo1 {
private:
	int x, y;
	float ancho, alto;
	int idx, idy;
	float tam;

public:
	Fondo1(Bitmap^ bm) {
		ancho = bm->Width / 1.0;
		alto = bm->Height / 5.0;
		x = 0;
		y = 0;
		idx = idy = 0;
		tam = 4.0;
	}

	~Fondo1() {}

	void Dibujar(Graphics^ g, Bitmap^ bm) { //Graphics -> Canvas // Bitmap -> Image
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * tam, alto * tam);
		g->DrawImage(bm, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void Mover(Graphics^ g) {
		idy++;
		if (idy > 4) {
			idy = 0;
		}
	}
};