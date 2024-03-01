#pragma once
#ifndef PLAYERCONIO_H_INCLUDED
#define PLAYERCONIO_H_INCLUDED
#include "arrayconio.h"
class Player {
public:
	short getLf();
	short getStm();
	short getAm();
	void setLf(short l);
	void setStm(short s);
	void setAm(short a);
	char* getPlayer();
	void setPos(char* p);
	void setValue();
	~Player();
protected:
	bool alive;
private:
	short status[3] = { LIFE, STAMIN, AMMO };
	short* pstatus = status;
	enum st { LIFE = 100, STAMIN = 100, AMMO = 50 };
	char* p;
};

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
void Player::setValue() {
	*this->getPlayer() = '1';
}
Player::~Player() {
	this->pstatus = nullptr;
	this->p = nullptr;
}
#endif // !PLAYERCONIO_H_INCLUDED

