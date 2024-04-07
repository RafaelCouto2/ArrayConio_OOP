#pragma once
#include "arrayconio.h"
#include <string>
#include "modifiers.h"
#ifndef PLAYERCONIO_H_INCLUDED
#define PLAYERCONIO_H_INCLUDED

class Player {
public:
	~Player(); //DESTRUCTOR
	Player();
	short getLf(); //RETURN THE LIFE OF THE PLAYER
	short getStm(); //RETURN THE STAMIN OF THE PLAYER
	short getAm(); //RETURN THE AMMO OF THE PLAYER
	short getLvs(); //RETURN THE REMAIN LIVES OF THE PLAYER
	void setLvs(short lvs); //CHANGE THE TOTAL LIVES OF THE PLAYER
	void setLf(short l); //CHANGE THE LIFE --
	void setStm(short s); //CHANGE THE STAMIN --
	void setAm(short a); //CHANGE THE AMMO --
	char* getPlayer(); //RETURN THE PTR PLAYER
	void setPos(char* p); //CHANGE POS X Y FROM PTR P
	void setInGameValue(char value); //CHANGE VALUE OF *PTR
	char getInGameValue();
	bool isAlive(); //RETURN THE ALIVE STATUS OF THE PLAYER
	void setAlive(bool l); //CHANGE THE ALIVE STATUS OF THE PLAYER
	std::string lifeToScreen();
	Atqmodifier* getPlayerMod();
	float getBaseAtq();
	float getBaseDef();
	void setBaseAtq(float batq);
	void setBaseDef();
	void setPotions(short totPot);
	short getPotions();
	void setInvCap(short cap);
	short getInvCap();
	void usePotion();
protected:
	bool alive; //STATUS
	Atqmodifier modifier;
private:
	enum st { LIFE = 100, STAMIN = 100, AMMO = 50, LIVES = 3 }; //LIFE, STAMIN, AMMO ENUM VALUES. CONSTANTS
	char lifeScreen[100];
	short status[4] = { LIFE, STAMIN, AMMO, LIVES }; //4 INDEX ARRAY WHO'LL HAVE THE BASE VALUES OF CONSTATS. (CHANGEABLE)
	short* pstatus = status; // PTR TO STATUS
	char* p; //PTR P
	float baseAtq, baseDef;
	short invCap;
	short potions;
};

Player::Player() {
	this->setLf(100);
	this->setLvs(3);
	this->modifier.setBaseAtq(1.11);
	this->baseAtq = this->modifier.getBaseAtq();
	this->modifier.setBaseDef(baseAtq / (1.5 * 0.52));
	this->baseDef = this->modifier.getBaseDef();
	this->setInvCap(10);
	this->setPotions(3);
}

short Player::getLf() {
	return this->pstatus[0];
}
short Player::getStm() {
	return this->pstatus[1];
}
short Player::getAm() {
	return this->pstatus[2];
}
void Player::setLf(short l) {
	this->pstatus[0] = l;
}
void Player::setStm(short s) {
	this->pstatus[1] = s;
}
void Player::setAm(short a) {
	this->pstatus[2] = a;
}
char* Player::getPlayer() {
	return this->p;
}
void Player::setPos(char* p) {
	this->p = p;
}
void Player::setInGameValue(char value) {
	*this->getPlayer() = value;
}
Player::~Player() {
	//delete this->modifierPlayer;
	this->pstatus = nullptr;
	this->p = nullptr;
}

std::string Player::lifeToScreen() {
	short newLife = this->getLf() / 10;
	for (size_t l = 0; l < this->getLf() / 10; l++) {
		this->lifeScreen[l] = '|';
	}
	if (this->getLf() / 10 < 10) {
		for (size_t i = newLife; i < 10; i++) {
			this->lifeScreen[i] = ' ';
		}
	}
	return lifeScreen;
}

bool Player::isAlive() {
	return this->alive;
}
void Player::setAlive(bool l) {
	this->alive = l;
}
short Player::getLvs() {
	return this->pstatus[3];
}
void Player::setLvs(short lvs) {
	this->pstatus[3] = lvs;
}

Atqmodifier* Player::getPlayerMod() {
	return &this->modifier;
}

void Player::setBaseAtq(float batq) {
	this->baseAtq = batq;
}

void Player::setPotions(short totPot) {
	this->potions = totPot;
}

short Player::getPotions() {
	return this->potions;
}

void Player::setInvCap(short cap) {
	this->invCap = cap;
}

short Player::getInvCap() {
	return this->invCap;
}

void Player::usePotion() {
	if (this->getLf() < 100 and this->getPotions() >= 1) {
		this->setPotions(this->getPotions() - 1);
		this->setLf(100);
	}
}

char Player::getInGameValue() {
	return *this->getPlayer();
}
#endif // !PLAYERCONIO_H_INCLUDED

