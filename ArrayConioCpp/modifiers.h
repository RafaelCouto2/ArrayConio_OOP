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
	void setBaseDef(float bdef);
	float getAtqMod();
	float getBaseAtq();
	float getBaseDef();
	Atqmodifier();
protected:

private:
	float atqmod;
	float baseatq;
	float basedef;
};

Atqmodifier::Atqmodifier() {
	//this->setBaseAtq(0);
	//this->setBaseDef(this->getBaseAtq() / (1.5 * 0.52));
	this->baseatq = 0;
	this->basedef = 0;
	this->setAtqMod(0.5);
}
void Atqmodifier::powerUp() {
	
}
void Atqmodifier::baseAtqUp() {
	//this->setBaseAtq(this->getBaseAtq() * 1.11);
	this->baseatq *= 1.11;
}
void Atqmodifier::baseAtqLower() {

}

void Atqmodifier::setAtqMod(float atm) {
	this->atqmod = atm;
}
void Atqmodifier::setBaseAtq(float batq) {
	this->baseatq = (batq < this->getBaseAtq())? this->baseatq = this->baseatq :this->baseatq = batq;
	//this->baseatq = batq;
}
void Atqmodifier::setBaseDef(float bdef) {
	this->basedef = (bdef < this->getBaseDef()) ? this->basedef = this->basedef : this->basedef = bdef;
}
float Atqmodifier::getAtqMod() {
	return this->atqmod;
}
float Atqmodifier::getBaseAtq() {
	return this->baseatq;
}
float Atqmodifier::getBaseDef() {
	return this->basedef;
}

#endif // !MODIFIERS_H_INCLUDED

