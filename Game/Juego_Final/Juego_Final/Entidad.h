#pragma once
#include <iostream>
using namespace System::Drawing;

class Entidad {
protected:
	float x, y;//Coordenadas
	int dx, dy;//Velocidad
	float ancho, alto;
	int idx, idy;//Indices
	float tam;//Tamaño del sprite
public:
	Entidad() {//Constructor
		x = y = 0;
		dx = dy = 0;
		ancho = 0;
		alto = 0;
		idx = idy = 0;
		tam = 0;
	}
	~Entidad() {}//Destructor

	//Metodos
	virtual void Dibujar() {}

	virtual void Mover() {}

	virtual Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}

	void Stop() {
		idx = 0;
	}

	//Getters
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	int getDx() {
		return dx;
	}
	int getDy() {
		return dy;
	}
	float getAncho() {
		return ancho;
	}
	float getAlto() {
		return alto;
	}
	int getIdx() {
		return idx;
	}
	int getIdy() {
		return idy;
	}
	int getTam() {
		return tam;
	}

	//Setters
	void setX(int x) {
		x = x;
	}
	void setY(int y) {
		y = y;
	}
	void setDx(int dx) {
		dx = dx;
	}
	void setDy(int dy) {
		dy = dy;
	}
	void setAncho(float ancho) {
		this->ancho = ancho;
	}
	void setAlto(float alto) {
		this->alto = alto;
	}
	void setIdx(int idx) {
		idx = idx;
	}
	void setIdy(int idy) {
		idy = idy;
	}
	void setTam(int tam) {
		tam = tam;
	}

};