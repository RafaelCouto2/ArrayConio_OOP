#pragma once
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

class Controller {
public:
	Controller(short s);
	char *p;
	short SIZE;
	char** virtualm;
private:
protected:

};
Controller::Controller(short s) {
	this->virtualm = new char* [SIZE];

	
}

#endif // !CONTROLLER_H_INCLUDED

