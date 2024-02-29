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
	char* p;
protected:
	bool alive;
private:
	short status[3] = { LIFE, STAMIN, AMMO };
	short* pstatus = status;
	enum st { LIFE = 100, STAMIN = 100, AMMO = 50 };

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


#endif // !PLAYERCONIO_H_INCLUDED

