#pragma once
#include "Entidad.h"
#include "Tyron.h"
class Pobreza : public Entidad {
private:
	int hp, contMurder;
public:
	Pobreza(Bitmap^ bm) : Entidad() {
		x = y = 0;
		dx = dy = 6;
		ancho = bm->Width / 3.0;
		alto = bm->Height / 4.0;
		hp = 9;
		tam = 7;
		contMurder = 0;
	}

	~Pobreza() {}

	void Dibujar(Graphics^ g, Bitmap^ bm) {
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * tam, alto * tam);
		g->DrawImage(bm, zoom, sectionShown, GraphicsUnit::Pixel);
	}

    void Mover(Graphics^ g, Tyron* tyron) {
        int dx = 1; // Velocidad de movimiento en el eje X
        int dy = 1; // Velocidad de movimiento en el eje Y

        // Comportamiento de perseguidor en el eje X
        if (x == tyron->getX()) {
            dx = 0; // No se mueve en el eje X
        }
        else if (x > tyron->getX()) {
            dx = -1; // Se mueve hacia la izquierda
            idy = 0; // Animación hacia la izquierda
        }
        else if (x < tyron->getX()) {
            dx = 1; // Se mueve hacia la derecha
            idy = 1; // Animación hacia la derecha
        }

        // Comportamiento de perseguidor en el eje Y
        if (y == tyron->getY()) {
            dy = 0; // No se mueve en el eje Y
        }
        else if (y > tyron->getY()) {
            dy = -1; // Se mueve hacia arriba
            idy = 3; // Animación hacia arriba
        }
        else if (y < tyron->getY()) {
            dy = 1; // Se mueve hacia abajo
            idy = 2; // Animación hacia abajo
        }

        // Verificar si el movimiento en el eje X causa una colisión
        int nuevaX = x + dx;
        if (nuevaX < 0 || nuevaX + ancho > g->VisibleClipBounds.Width) {
            dx = 0; // No se mueve en el eje X si hay colisión
        }

        // Verificar si el movimiento en el eje Y causa una colisión
        int nuevaY = y + dy;
        if (nuevaY < 0 || nuevaY + alto > g->VisibleClipBounds.Height) {
            dy = 0; // No se mueve en el eje Y si hay colisión
        }

        // Actualizar la posición del perseguidor
        x += dx;
        y += dy;

        // Mantener la animación constante cuando no hay movimiento
        if (dx == 0 && dy == 0) {
            idx = 0; // No hay cambio de cuadro de animación
        }
        else if (dx != 0) {
            if (idx >= 0 && idx < 3) {
                idx++;
            }
            else {
                idx = 0;
            }
        }
    }


	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * tam/1.5, alto * tam/1.5);
	}
	int getHp() {
		return hp;
	}
	int getContMurder() {
		return contMurder;
	}
	void Redireccion() {
		x = rand() % 500;
		y = rand() % 500;
	}
	void ReducirVida() {
		hp--;
	}
	void AumentarVelocidad() {
		dx++;
		dy++;
	}
	void AumentarContMurder() {
		contMurder++;
	}
};