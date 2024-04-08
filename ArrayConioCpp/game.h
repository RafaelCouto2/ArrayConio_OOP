#pragma once
#include "arrayconio.h"
#include <conio.h>
#include <windows.h>
#include "modifiers.h"
#include "Controller.h"
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/*
Parei hoje após a criação do sistema de combate. Agora é o level up, melhoria na UI, ajuste do inventário do player e mais possibilidades de inimgos.
Me falta estudo para trabalhar com threads... Talvez futuramente!
*/

class Game {
public:
	Game(short size, Player* player); //CONSTRUCTOR
	void play(); //PLAY :)
	~Game(); //DESTRUCTOR
protected:

private:
	ArrayConio *conio;
	void controller(); //CONTROLLER FUNC.
	short key; //KEYBOARD KEY
	char** t; // PTR TO PTR FOR MAP MATRIX
	char* p; // PLAYER PTR
	char playerchar;
	Player* player; // PLAYER OBJ
	Atqmodifier atqMod[2];
	Controller *game_controller;
	void changeAtqModifier();
	bool extremidade = false; //`-` NO USE
	void playerstatus(); //SHOW PLAYER STATUS
};

Game::Game(short size, Player* player) {
	this->conio = new ArrayConio(size);
	this->t = this->conio->getPtr();
	this->player = player;
	this->player->setPos(&(this->t[this->conio->getLine() / 2][this->conio->getColumn() / 2])); //SET PLAYER POS *PTR TO THE MIDDLE OF MAP MATRIX ADRESS
	this->key = 0;
	this->p = this->player->getPlayer(); //SET PTR P TO GET PLAYER *PTR FROM PLAYER OBJ
	this->player->setInGameValue('x'); // CHANGE VALUE OF PLAYER PTR TO '1'
	this->playerchar = this->player->getInGameValue();
	this->player->setAlive(true);
	this->atqMod[0].setAtqMod(this->atqMod[1].getAtqMod() * 1.5f);
	game_controller = new Controller(this->conio, this->player, this->conio->getLine());
}

void Game::play() { //MAIN FUNC, WHO`LL CALL MOST OF FUNCS.
	//this->conio->screen();
	std::cout << "PRESS ANY KEY TO START! (ANY... BUT NOT ESC XD)";

	this->t[2][1] = 'g';
	this->t[1][2] = 'c';
	this->t[4][0] = 'u';
	this->t[3][3] = 'N';
	
	while (key != 27) {
		this->key = _getch(); //WAIT FOR SOME INPUT AND ISERT THE INTEGER VALUE INTO KEY
		this->extremidade = false;
		if (key == 112) {
			this->player->usePotion();
		}
		this->game_controller->controller(this->key, this->playerchar /*WHAT IS THE PLAYER*/);
		this->conio->refresh();
		this->playerstatus();
	}
}

void Game::playerstatus() {
	std::cout << std::endl << "HEALTH: " << this->player->lifeToScreen() << std::endl;
	std::cout << "INVENTORY: " << std::endl;
	std::cout << "POTIONS: " << this->player->getPotions() << std::endl;
	if (this->player->getLvs() > 0) std::cout << "LIFES: " << this->player->getLvs() << std::endl;
	else std::cout << "LIFES: LAST" << std::endl;
	if (this->player->getLvs() < 0) {
		this->key = 27;
		this->conio->refresh();
		std::cout << std::endl << "GAME OVER!";
	}
}

void Game::changeAtqModifier() {
	this->atqMod[0].setAtqMod(this->atqMod[1].getAtqMod() * 1.5f);
}

Game::~Game() {
	if (this->game_controller != nullptr) {
		delete this->game_controller;
	}
	if (this->conio != nullptr) {
		delete this->conio;
	}
	this->p = nullptr;
	this->t = nullptr;
	this->game_controller = nullptr;
	this->conio = nullptr;
}
#endif // !GAME_H_INCLUDED

