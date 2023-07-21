#pragma once
#include "Poblador.h"
#include "Subdito.h"
#include "Tyron.h"
#include "Pobreza.h"
#include <vector>

using namespace std;

class Controlador2 {
private:
	Tyron* tyron;
	Pobreza* pobreza;
	vector<Subdito*> arrSubdito;
	vector<Poblador*> arrPoblador;
public:
	Controlador2(Graphics^ g, Bitmap^ bmTyron, Bitmap^ bmSubdito, Bitmap^ bmPoblador, Bitmap^ bmPobreza) {
		tyron = new Tyron(bmTyron);
		pobreza = new Pobreza(bmPobreza);
		arrPoblador.push_back(new Poblador(bmPoblador, 5, 500));
		arrPoblador.push_back(new Poblador(bmPoblador, 5, 5));
		arrPoblador.push_back(new Poblador(bmPoblador, 850, 5));
		arrPoblador.push_back(new Poblador(bmPoblador, 850, 500));
	}
	~Controlador2() {}
	///Lvl1
	void AgregarSubdito(Bitmap^ bmSubdito) {
		arrSubdito.push_back(new Subdito(bmSubdito, rand() % 650, rand() % 250, rand() % 4));
	}
	void AgregarPoblador(Bitmap^ bmPoblador) {
		arrPoblador.push_back(new Poblador(bmPoblador, rand() % 850, rand() % 500));
	}

	void MoverTodoLvl2(Graphics^ g) {
		pobreza->Mover(g, tyron);
		for (int i = 0; i < arrSubdito.size(); i++) {
			arrSubdito[i]->Mover(g);
		}
		for (int i = 0; i < arrPoblador.size(); i++) {
			arrPoblador[i]->Mover(g);
		}
	}

	void DibujarTodoLvl2(Graphics^ g, Bitmap^ bmTyron, Bitmap^ bmSubdito, Bitmap^ bmPoblador, Bitmap^ bmPobreza) {
		tyron->Dibujar(g, bmTyron);
		pobreza->Dibujar(g, bmPobreza);
		for (int i = 0; i < arrSubdito.size(); i++) {
			arrSubdito[i]->Dibujar(g, bmSubdito);
		}
		for (int i = 0; i < arrPoblador.size(); i++) {
			arrPoblador[i]->Dibujar(g, bmPoblador);
		}
	}

	Tyron* getTyron() {
		return tyron;
	}
	Pobreza* getPobreza() {
		return pobreza;
	}

	void Colision1() { //Colision entre súbditos de Pobreza con el héroe "Tyron"
		for (int i = 0; i < arrSubdito.size(); i++) { //Según la cantidad de súbditos
			if (tyron->getRectangle().IntersectsWith(arrSubdito[i]->getRectangle())) { //Si se intersectan, entonces...
				tyron->Redireccion();
				tyron->ReducirVida();//Se reduce la vida del héroe
			}
		}
	}
	void Colision2() { //Colision entre pobladores y el héroe "Tyron"
		for (int i = 0; i < arrPoblador.size(); i++) {
			if (tyron->getRectangle().IntersectsWith(arrPoblador[i]->getRectangle())) {
				tyron->AumentarContPoblSalv(); //Aumentar cantidad de pobladores salvados
				tyron->AumentarVelocidad(); //Los pobladores al recuperar su inteligencia abandonan la ciudad y nos otorgan 1 de velocidad en cada eje
				arrPoblador.erase(arrPoblador.begin() + i); //Que se elimine del array
			}
		}
	}
	void Colision3() { //Colision entre pobladores y súbditos
		for (int i = 0; i < arrPoblador.size(); i++) {
			for (int j = 0; j < arrSubdito.size(); j++) {
				if (arrPoblador[i]->getRectangle().IntersectsWith(arrSubdito[j]->getRectangle())) {
					arrSubdito[j]->Rebote(); // Si en caso chocan entonces que el súbdito rebote en la direccion contraria
				}
			}
		}
	}
	void Colision4() { //Colision entre pobreza y tyron
		if (tyron->getRectangle().IntersectsWith(pobreza->getRectangle())) {
			tyron->Redireccion();//Lo ubicamos en una posicion aleatoria
			tyron->ReducirVida();//Le reducimos su vida
			tyron->ReducirVelocidad(); //Le reducimos su velocidad
			pobreza->AumentarVelocidad(); //Aumentamos la velocidad de pobreza
		}
	}
	void Colision5() { //Colision entre pobreza y pobladores
		for (int i = 0; i < arrPoblador.size(); i++) {
			if (pobreza->getRectangle().IntersectsWith(arrPoblador[i]->getRectangle())) {
				pobreza->Redireccion();
				pobreza->AumentarContMurder();
				arrPoblador.erase(arrPoblador.begin() + i); //Que se elimine del array
			}
		}
	}
};
