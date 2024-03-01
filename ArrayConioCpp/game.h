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

class Game : ArrayConio {
public:
	Game(short size, Player p);
	void play();
	void controller();
	~Game();
protected:

private:
	short key;
	char** t;
	char* p;
	Player player;
	bool extremidade = false;
	//ArrayConio arr;
};

Game::Game(short size, Player pl) : ArrayConio(size) {
	this->t = this->getPtr();
	this->player = pl;
	this->player.setPos(&(this->t[this->getLine() / 2][this->getColumn() / 2]));
	this->key = 0;
	*this->player.getPlayer() = '1';
	this->p = this->player.getPlayer();
}

void Game::play() {
	this->screen();
	while (key != 27) {
		this->key = _getch();
		this->extremidade = false;
		this->controller();
		this->refresh();
		Sleep(50);

	}
	
}

void Game::controller() {
	switch (key) {
	case KEY_UP:
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[0][c]) {
						this->extremidade = true;
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->extremidade) {
							*this->p = '.';
							this->p = &(this->t[l - 1][c]);
							*this->p = '1';
						}
					}
				}
				
			}
		}
		break;
	case KEY_DOWN:
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[this->getLine() - 1][c]) {
						this->extremidade = true;
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->extremidade) {
							*this->p = '.';
							this->p = &(this->t[++l][c]);
							*this->p = '1';
						}
					}
				}

			}
		}
		break;
	case KEY_LEFT:
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					/*if (this->p == &this->t[0][0]) {
						this->extremidade = true;
						this->p = &this->t[0][0];
						*this->p = '1';
					}
					else*/ if (this->p == &this->t[l][0]) {
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->extremidade) {
							*this->p = '.';
							this->p = &(this->t[l][c - 1]);
							*this->p = '1';
						}
					}
				}
				}

			}
		break;
	case KEY_RIGHT:
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
						if (!this->extremidade) {
							*this->p = '.';
							this->p = &(this->t[l][++c]);
							*this->p = '1';
						}
					}
				}
			}

		}
		break;
	}
}

Game::~Game() {
	
	this->p = nullptr;
	this->t = nullptr;
}
#endif // !GAME_H_INCLUDED

