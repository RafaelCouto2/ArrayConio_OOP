#pragma once
#include "playercolliderchecker.h"
#include "battle.h"
#include "enemies.h"
#include <fstream>
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Controller {
public:
	Controller(char** map, char* p, size_t LC);
	void controller(short key, char ingameplayer = '1');
private:
	char** t;
	char* p;
	bool extremidade;
	size_t LINE, COLUMN;
	Collider collider;
	Battle battle;
	Enemies enemiesKeyCode;
	
protected:
	
};
Controller::Controller(char** map, char* p, size_t LC) {
	this->t = map;
	this-> p = p;
	this->LINE = LC;
	this->COLUMN = (LC * 2) + 1;
	this->extremidade = false;
}

void Controller::controller(short key, char ingameplayer) {
	switch (key) {
	case KEY_UP: //MOV PLAYER +Y
		for (size_t l = 0; l < this->LINE; l++) {
			for (size_t c = 0; c < this->COLUMN; c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[0][c]) {
						this->p = &this->t[l][c];
						*this->p = ingameplayer;
					}
					else {
						if (!this->collider.checkCollider('Y', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[l - 1][c]);
								*this->p = ingameplayer;
							}
						}
						else {
							this->collider.battleChecker('Y', this->t, this->enemiesKeyCode.enemiesString, l, c);
						}
					}
				}
			}
		}
		break;
	case KEY_DOWN: //MOV PLAYER -Y
		for (size_t l = 0; l < this->LINE; l++) {
			for (size_t c = 0; c < this->COLUMN; c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[this->LINE - 1][c]) {
						this->p = &this->t[l][c];
						*this->p = ingameplayer;
					}
					else {
						if (!this->collider.checkCollider('-Y', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[++l][c]);
								*this->p = ingameplayer;
							}
						}
						else {
							this->collider.battleChecker('-Y', this->t, this->enemiesKeyCode.enemiesString, l, c);
						}
					}
				}
			}
		}
		break;
	case KEY_LEFT: //MOV PLAYER -X
		for (size_t l = 0; l < this->LINE; l++) {
			for (size_t c = 0; c < this->COLUMN; c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[l][0]) {
						this->p = &this->t[l][c];
						*this->p = ingameplayer;
					}
					else {
						if (!this->collider.checkCollider('-X', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[l][c - 1]);
								*this->p = ingameplayer;
							}
						}
						else {
							this->collider.battleChecker('-X', this->t, this->enemiesKeyCode.enemiesString, l, c);
						}
					}
				}
			}
		}
		break;
	case KEY_RIGHT: //MOV PLAYER +X
		for (size_t l = 0; l < this->LINE; l++) {
			for (size_t c = 0; c < this->COLUMN; c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[l][this->COLUMN - 1]) {
						this->p = &this->t[l][c];
						*this->p = ingameplayer;
					}
					else {
						if (!this->collider.checkCollider('X', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[l][++c]);
								*this->p = ingameplayer;
							}
						}
						else {
							this->battle.battleTrigger(this->collider.battleChecker('X', this->t, this->enemiesKeyCode.enemiesString, l, c));
						}
					}
				}
			}
		}
		break;
	}
}
#endif // !CONTROLLER_H_INCLUDED

