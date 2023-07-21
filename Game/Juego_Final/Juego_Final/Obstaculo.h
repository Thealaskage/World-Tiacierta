#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Drawing;

class Obstaculo : public Entidad
{
public:

    Obstaculo(Bitmap^ bm, float x, float y) : Entidad() {

        this->x = x;
        this->y = y;
        ancho = bm->Width / 1.0;
        alto = bm->Height / 1.0;
        tam = 0.7;

    }
    ~Obstaculo() {}

    void Dibujar(Graphics^ g, Bitmap^ bm) { //Graphics -> Canvas // Bitmap -> Image
        Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);//Seccion a mostrar
        Rectangle zoom = Rectangle(x, y, ancho * tam, alto * tam);//Zoom
        g->DrawImage(bm, zoom, sectionShown, GraphicsUnit::Pixel);//Dibujar
    }

    Rectangle getRectangle() {
        return Rectangle(x, y, ancho * 0.65, alto * 0.65);//Reducir hitbox
    }

};