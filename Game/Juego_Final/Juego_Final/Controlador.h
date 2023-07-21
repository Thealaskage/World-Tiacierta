#pragma once
#include "Poblador.h"
#include "Subdito.h"
#include "Tyron.h"
#include "Pobreza.h"
#include "Obstaculo.h"
#include <vector>

using namespace std;

class Controlador {
private:
	Tyron* tyron;
	Pobreza* pobreza;
	vector<Subdito*> arrSubdito;
	vector<Poblador*> arrPoblador;
	vector<Obstaculo*> arrObstaculo;
public:
	Controlador(Graphics^ g, Bitmap^ bmTyron, Bitmap^ bmSubdito, Bitmap^ bmPoblador, Bitmap^ bmObstaculo) {
		tyron = new Tyron(bmTyron);
		arrSubdito.push_back(new Subdito(bmSubdito, 600, 5, 3));
		arrSubdito.push_back(new Subdito(bmSubdito, 200, 5, 2));
		arrSubdito.push_back(new Subdito(bmSubdito, 5, 200, 0));
		arrSubdito.push_back(new Subdito(bmSubdito, 5, 400, 1));
		arrPoblador.push_back(new Poblador(bmPoblador, 5, 500));
		arrPoblador.push_back(new Poblador(bmPoblador, 5, 5));
		arrPoblador.push_back(new Poblador(bmPoblador, 850, 5));
		arrPoblador.push_back(new Poblador(bmPoblador, 850, 500));
		arrPoblador.push_back(new Poblador(bmPoblador, 450, 5));
		arrPoblador.push_back(new Poblador(bmPoblador, 450, 500));
		arrPoblador.push_back(new Poblador(bmPoblador, 150, 240));
		arrPoblador.push_back(new Poblador(bmPoblador, 640, 240));
		arrObstaculo.push_back(new Obstaculo(bmObstaculo, 100, 50));
		arrObstaculo.push_back(new Obstaculo(bmObstaculo, 100, 300));
		arrObstaculo.push_back(new Obstaculo(bmObstaculo, 600, 50));
		arrObstaculo.push_back(new Obstaculo(bmObstaculo, 600, 300));

	}
	~Controlador() {}
	///Lvl1
	void AgregarSubdito(Bitmap^ bmSubdito) {
		arrSubdito.push_back(new Subdito(bmSubdito, rand() % 850, rand() % 500, rand() % 4));
	}

	void MoverTodoLvl1(Graphics^ g) {
		for (int i = 0; i < arrSubdito.size(); i++) {
			arrSubdito[i]->Mover(g);
		}
		for (int i = 0; i < arrPoblador.size(); i++) {
			arrPoblador[i]->Mover(g);
		}
	}

	void DibujarTodoLvl1(Graphics^ g, Bitmap^ bmTyron, Bitmap^ bmSubdito, Bitmap^ bmPoblador, Bitmap^ bmObstaculo) {
		tyron->Dibujar(g, bmTyron);
		for (int i = 0; i < arrObstaculo.size(); i++) {
			arrObstaculo[i]->Dibujar(g, bmObstaculo);
		}
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

	void Colision1() { //Colision entre súbditos de Pobreza con el héroe "Tyron"
		//Verificacion
		for (int i = 0; i < arrSubdito.size(); i++) { //Según la cantidad de súbditos
			if (tyron->getRectangle().IntersectsWith(arrSubdito[i]->getRectangle())) { //Si se intersectan, entonces...
				tyron->Redireccion();
				tyron->ReducirVida();//Se reduce la vida del héroe
			}
		}
	}
	void Colision2() { //Colision entre pobladores y el héroe "Tyron"
			//Verificacion
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
				if (arrPoblador[i]->getRectangle().IntersectsWith(arrSubdito[j]->getRectangle2())) {
					arrSubdito[j]->Rebote(); // Si en caso chocan que el súbdito rebote en la direccion contraria
				}
			}
		}
	}
	void Colision4() { //Colision entre obstaculos y Tyron
		for (int i = 0; i < arrObstaculo.size(); i++) {
			if (tyron->getRectangle().IntersectsWith(arrObstaculo[i]->getRectangle())) {
				tyron->Redireccion();
				tyron->ReducirVida();
			}
		}
	}
};