#pragma once
#include <fstream>
#include <string>
#ifndef ENM1_H_INCLUDED
#define ENM1_H_INCLUDED

class Enemies {
public:
	struct Enemie1;
	std::string enemiesString;
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
	this->enemiesFile.close();
}

struct Enemies::Enemie1 {

};



#endif // !ENM1_H_INCLUDED
