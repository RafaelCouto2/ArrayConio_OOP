#pragma once
#include "arrayconio.h"
#include <conio.h>
#include <windows.h>
#include "modifiers.h"
#include "Controller.h"
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/*
Parei hoje no desenvolvimento dos inimigos e a trigger da batalha. O plano é adicionar um array de char e guardar os inimigos nele.
Ao iniciar a batalha, verifica o número do índice desse inimigo, quanto mais alto mais poderoso o inimigo será. Definirei um objeto
para os inimigos com um argumento que acionará os modificadores da instância do inimigo.
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
	//this->player->setInGameValue('x'); // CHANGE VALUE OF PLAYER PTR TO '1'
	this->player->setAlive(true);
	this->atqMod[0].setAtqMod(this->atqMod[1].getAtqMod() * 1.5f);
	game_controller = new Controller(this->conio, this->player, this->conio->getLine());
}

void Game::play() { //MAIN FUNC, WHO`LL CALL MOST OF FUNCS.
	this->conio->screen();
	this->playerstatus();
	this->t[2][1] = '2';
	this->t[1][2] = 'O';
	this->t[4][0] = 'I';
	this->t[3][3] = 'J';
	
	while (key != 27) {
		this->key = _getch(); //WAIT FOR SOME INPUT AND ISERT THE INTEGER VALUE INTO KEY
		this->extremidade = false;
		if (key == 112) {
			this->player->usePotion();
		}
		this->game_controller->controller(this->key, 'x' /*WHAT IS THE PLAYER*/);
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

