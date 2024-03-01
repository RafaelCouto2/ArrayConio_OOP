#pragma once
#include "arrayconio.h"
#include <conio.h>
#include <windows.h>
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Game : ArrayConio { //GAME INHERIT ARRAYCONIO
public:
	Game(short size, Player p); //CONSTRUCTOR
	void play();
	~Game(); //DESTRUCTOR
protected:

private:
	void controller(); //CONTROLLER FUNC.
	short key;
	char** t; // PTR TO PTR FOR MAP MATRIX
	char* p; // PLAYER PTR
	Player player; // PLAYER OBJ
	bool extremidade = false; //`-` NO USE
	bool checkCollider(short modifier, short y, short x, char ** map); //COLLIDER CHECKER
	//ArrayConio arr;
};

Game::Game(short size, Player pl) : ArrayConio(size) { //GAME AND (SUPER)ARRAYCONIO CONSTRUCTOR.
	this->t = this->getPtr();
	this->player = pl;
	this->player.setPos(&(this->t[this->getLine() / 2][this->getColumn() / 2])); //SET PLAYER POS *PTR TO THE MIDDLE OF MAP MATRIX ADRESS
	this->key = 0;
	*this->player.getPlayer() = '1'; // CHANGE VALUE OF PLAYER PTR TO '1'
	this->p = this->player.getPlayer(); //SET PTR P TO GET PLAYER *PTR FROM PLAYER OBJ
}

void Game::play() { //MAIN FUNC, WHO`LL CALL MOST OF FUNCS.
	this->t[2][2] = '-'; //JUST A FEW RANDOM "OBJECTS" TO TEST THE COLLIDER
	this->t[3][1] = '0'; //
	this->t[4][4] = 'L'; //
	this->t[1][4] = '['; // --
	this->screen();
	while (key != 27) {
		this->key = _getch(); //WAIT FOR SOME INPUT AND ISERT THE INTEGER VALUE INTO KEY
		this->extremidade = false;
		this->controller();
		this->refresh();
		//Sleep(50);

	}
	
}

void Game::controller() {
	switch (key) {
	case KEY_UP: //MOV PLAYER +Y
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[0][c]) {
						this->extremidade = true;
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->checkCollider('Y', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[l - 1][c]);
								*this->p = '1';
							}
						}
					}
				}
			}
		}
		break;
	case KEY_DOWN: //MOV PLAYER -Y
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[this->getLine() - 1][c]) {
						this->extremidade = true;
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->checkCollider('-Y', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[++l][c]);
								*this->p = '1';
							}
						}
					}
				}
			}
		}
		break;
	case KEY_LEFT: //MOV PLAYER -X
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					/*if (this->p == &this->t[0][0]) {
						this->extremidade = true;
						this->p = &this->t[0][0];
						*this->p = '1';
					}
					else*/ 
					if (this->p == &this->t[l][0]) {
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->checkCollider('-X', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[l][c - 1]);
								*this->p = '1';
							}
						}
					}
				}
			}
		}
		break;
	case KEY_RIGHT: //MOV PLAYER +X
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					/*if (this->p == &this->t[this->getLine() - 1][this->getColumn() - 1]) {
						this->extremidade = true;
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else*/
					if (this->p == &this->t[l][this->getColumn() - 1]) {
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->checkCollider('X', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[l][++c]);
								*this->p = '1';
							}
						}
					}
				}
			}
		}
		break;
	}
}

bool Game::checkCollider(short modifier, short y, short x, char** map) {
	//DETERMINE THE COLLIDER DIRECTION CHECKER BY MODIFIER
	switch (modifier) {
	case 'Y':
		return (map[y - 1][x] != '.');
		break;
	case '-Y':
		return (map[++y][x] != '.');
		break;
	case '-X':
		return ((map[y][x - 1] != '.'));
		break;
	case 'X':
		return (map[y][++x] != '.');
		break;
	}
}

Game::~Game() {
	this->p = nullptr;
	this->t = nullptr;
}
#endif // !GAME_H_INCLUDED

