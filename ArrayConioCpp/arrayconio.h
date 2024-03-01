#pragma once

#ifndef ARRAYCONIO_H_INCLUDED
#define ARRAYCONIO_H_INCLUDED

#include <iostream>
#include "playerconio.h"

class ArrayConio {
	
public:
	ArrayConio(short size); //CONSTRUTOR
	~ArrayConio(); //DESTRUTOR
	void screen(); //RENDERIZA
	void refresh(); //ATUALIZA SCREEN()
protected:
	size_t getLine();
	size_t getColumn();
	char** getPtr();
	Player getPlayer();
private:
	size_t LINE, COLUMN; //TAMANHO DAS LINHAS E COLUNAS
	char** t; //PONTEIRO PARA PONTEIRO t;
	const char MAP = '.'; // CHAR PADRÃO QUE SERÁ O MAPA.
};

ArrayConio::ArrayConio(short size) {
	this->LINE = size;
	this->COLUMN = (size * 2) + 1;
	t = new char* [this->LINE]; //PONTEIRO PARA PONTEIRO T RECEBE ARRAY DE PONTEIRO DO TIPO CHAR.
	for (size_t l = 0; l < this->LINE; l++) { //ALOCA NA MEMÓRIA, APONTADA POR 't', CINCO ÍNDICES DE CHAR.
		this->t[l] = new char[COLUMN];
	}
	for (size_t l = 0; l < this->LINE; l++) { //INICIALIZA A MATRIZ DE 't'.
		for (size_t c = 0; c < this->COLUMN; c++) {
			this->t[l][c] = this->MAP;
		}
	}
}

ArrayConio::~ArrayConio() {
	for (size_t l = 0; l < this->LINE; l++) {
		delete[] t[l];
	}
	delete[] t;
}

void ArrayConio::screen() { //RENDERIZA A MATRIZ NA TELA.
	std::cout << ' ';
	for (size_t upperl = 0; upperl < this->COLUMN + 2; upperl++) {
		std::cout << '_';
	}
	std::cout << std::endl;
	for (size_t l = 0; l < this->LINE; l++) {
		std::cout << "| ";
		for (size_t c = 0; c < this->COLUMN; c++) {
			std::cout << this->t[l][c];
		}
		std::cout << " |";
		std::cout << std::endl;
	}
	std::cout << ' ';
	for (size_t lowerl = 0; lowerl < this->COLUMN + 2; lowerl++) {
		std::cout << "−";
	}
}

void ArrayConio::refresh() {
	system("cls");
	this->screen();
}

size_t ArrayConio::getLine() {
	return this->LINE;
}

size_t ArrayConio::getColumn() {
	return this->COLUMN;
}

char** ArrayConio::getPtr() {
	return this->t;
}

#endif // !ARRAYCONIO_H_INCLUDED
