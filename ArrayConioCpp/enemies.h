#pragma once
#include <fstream>
#include <string>
#ifndef ENM1_H_INCLUDED
#define ENM1_H_INCLUDED

class Enemies {
public:
	struct Enemie01;
	std::string enemiesString;
	char enemiesChar[30];
	Enemies();
protected:
	
private:
	std::string enemiesTemp;
	std::ifstream enemiesFile;
};

Enemies::Enemies() {
	if (!this->enemiesFile.is_open()) {
		this->enemiesFile.open("enemies.txt");
	}

	while (std::getline(this->enemiesFile, this->enemiesTemp)) {
		this->enemiesString += this->enemiesTemp += '\n';
	}
	
	strcpy_s(enemiesChar, enemiesString.c_str());
	this->enemiesFile.close();
}

//STRUCT

struct Enemies::Enemie01 {
public:
	Enemie01(char e, short baseatq);
	char getEnemy();
	Atqmodifier* getEnemyMod();
	short getLife();
	void setLife(short life);
	std::string lifeToScreen();
protected:

private:
	short life;
	short baseAtq;
	short baseDef;
	Atqmodifier modifier;
	char enemy;
	char lifeScreen[100];
};

Enemies::Enemie01::Enemie01(char e, short baseatq) {
	this->enemy = e;
	this->modifier.setBaseAtq(baseatq);
	this->modifier.setBaseDef(baseatq / (1.5 * 0.52));
	this->baseAtq = this->modifier.getBaseAtq();
	this->baseDef = this->modifier.getBaseDef();
	this->life = 100;
}

char Enemies::Enemie01::getEnemy() {
	return this->enemy;
}

Atqmodifier* Enemies::Enemie01::getEnemyMod() {
	return &this->modifier;
}

void Enemies::Enemie01::setLife(short life) {
	this->life = life;
}

short Enemies::Enemie01::getLife() {
	return this->life;
}

std::string Enemies::Enemie01::lifeToScreen() {
	short newLife = this->getLife() / 10;
	for (size_t l = 0; l < this->getLife() / 10; l++) {
		this->lifeScreen[l] = '|';
	}
	if (this->getLife() / 10 < 10) {
		for (size_t i = newLife; i < 10; i++) {
			this->lifeScreen[i] = ' ';
		}
	}
	return lifeScreen;
}

#endif // !ENM1_H_INCLUDED
