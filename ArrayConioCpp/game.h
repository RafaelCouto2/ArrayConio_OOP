#pragma once
#include "arrayconio.h"
#include <conio.h>
#include <windows.h>
#include "modifiers.h"
#include "Controller.h"
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Game { //GAME INHERIT ARRAYCONIO
public:
	Game(short size, Player p); //CONSTRUCTOR
	void play(); //PLAY :)
	~Game(); //DESTRUCTOR
protected:

private:
	ArrayConio *conio;
	void controller(); //CONTROLLER FUNC.
	short key; //KEYBOARD KEY
	char** t; // PTR TO PTR FOR MAP MATRIX
	char* p; // PLAYER PTR
	Player player; // PLAYER OBJ
	Atqmodifier atqMod[2];
	Controller *game_controller;
	void changeAtqModifier();
	bool extremidade = false; //`-` NO USE
	void playerstatus(); //SHOW PLAYER STATUS
	//ArrayConio arr;
};

Game::Game(short size, Player pl) { //GAME AND (SUPER)ARRAYCONIO CONSTRUCTOR.
	this->conio = new ArrayConio(size);
	this->t = this->conio->getPtr();
	this->player = pl;
	this->player.setPos(&(this->t[this->conio->getLine() / 2][this->conio->getColumn() / 2])); //SET PLAYER POS *PTR TO THE MIDDLE OF MAP MATRIX ADRESS
	this->key = 0;
	*this->player.getPlayer() = '1'; // CHANGE VALUE OF PLAYER PTR TO '1'
	this->p = this->player.getPlayer(); //SET PTR P TO GET PLAYER *PTR FROM PLAYER OBJ
	this->player.setAlive(true);
	this->atqMod[0].setAtqMod(this->atqMod[1].getAtqMod() * 1.5f);
	game_controller = new Controller(this->t, this->p, this->conio->getLine());
}

void Game::play() { //MAIN FUNC, WHO`LL CALL MOST OF FUNCS.
	this->conio->screen();
	this->playerstatus();
	this->t[2][1] = '2';
	while (key != 27) {
		this->key = _getch(); //WAIT FOR SOME INPUT AND ISERT THE INTEGER VALUE INTO KEY
		this->extremidade = false;
		this->game_controller->controller(this->key);
		this->conio->refresh();
		this->playerstatus();
		//Sleep(50);
	}
}

void Game::playerstatus() {
	std::cout << std::endl << "HEALTH: " << this->player.lifeToScreen() << std::endl;
	std::cout << "STAMIN: " << this->player.getStm() << std::endl;
	std::cout << "AMMO: " << this->player.getAm() << std::endl;
	if (this->player.getLvs() > 0) std::cout << "LIFES: " << this->player.getLvs() << std::endl;
	else std::cout << "LIFES: LAST" << std::endl;
	if (this->player.getLf() < 1) {
		this->player.setLvs(this->player.getLvs() - 1);
		this->player.setLf(100);
	}
	if (this->player.getLvs() < 0) {
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

