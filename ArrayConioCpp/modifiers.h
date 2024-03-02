#pragma once
#ifndef MODIFIERS_H_INCLUDED
#define MODIFIERS_H_INCLUDED

class Atqmodifier {

public:
	void powerUp();
	void baseAtqUp();
	void baseAtqLower();
	void setAtqMod(float atm);
	void setBaseAtq(float batq);
	float getAtqMod();
	float getBaseAtq();
	Atqmodifier();
protected:

private:
	float atqmod;
	float baseatq;
};

Atqmodifier::Atqmodifier() {
	this->setBaseAtq(3);
	this->setAtqMod(0.5);
}
void Atqmodifier::powerUp() {
	
}
void Atqmodifier::baseAtqUp() {

}
void Atqmodifier::baseAtqLower() {

}

void Atqmodifier::setAtqMod(float atm) {
	this->atqmod = atm;
}
void Atqmodifier::setBaseAtq(float batq) {
	/*if (!batq < this->baseatq) {
		this->baseatq = batq;
	}*/
	this->baseatq = (batq < this->getBaseAtq())?this->baseatq = this->baseatq:this->baseatq = batq;
}
float Atqmodifier::getAtqMod() {
	return this->atqmod;
}
float Atqmodifier::getBaseAtq() {
	return this->baseatq;
}

#endif // !MODIFIERS_H_INCLUDED

