#pragma once
#ifndef PLAYERCONIO_H_INCLUDED
#define PLAYERCONIO_H_INCLUDED
#include "arrayconio.h"
class Player {
public:
	short getLf(); //RETURN THE LIFE OF THE PLAYER
	short getStm(); //RETURN THE STAMIN OF THE PLAYER
	short getAm(); //RETURN THE AMMO OF THE PLAYER
	void setLf(short l); //CHANGE THE LIFE --
	void setStm(short s); //CHANGE THE STAMIN --
	void setAm(short a); //CHANGE THE AMMO --
	char* getPlayer(); //RETURN THE PTR PLAYER
	void setPos(char* p); //CHANGE POS X Y FROM PTR P
	void setValue(); //CHANGE VALUE OF *PTR
	~Player(); //DESTRUCTOR
protected:
	bool alive; //STATUS
private:
	short status[3] = { LIFE, STAMIN, AMMO }; //3 INDEX ARRAY WHO'LL HAVE THE BASE VALUES OF CONSTATS. (CHANGEABLE)
	short* pstatus = status; // PTR TO STATUS
	enum st { LIFE = 100, STAMIN = 100, AMMO = 50 }; //LIFE, STAMIN, AMMO ENUM VALUES. CONSTANTS
	char* p; //PTR P
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

