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
protected:

private:
	short key;
	char** t = this->getPtr();
	char* p;
	//ArrayConio arr;
};

Game::Game(short size, Player pl) : ArrayConio(size, pl) {
	this->p = &(this->t[this->getLine() / 2][this->getColumn() / 2]);
	this->key = 0;
	*this->p = '1';
}

void Game::play() {
	this->screen();
	while (key != 101) {
		this->key = _getch();
		this->controller();
		this->refresh();

		Sleep(50);

	}
	
}

void Game::controller() {
	switch (key) {
	case 72:
		
		break;
	case 80:

		break;
	case 75:

		break;
	case 77:

		break;
	}
}
#endif // !GAME_H_INCLUDED

