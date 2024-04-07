#pragma once
#include <iostream>
#include "enemies.h"
#include <cmath>
#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED

class Battle {
public:
	void battleTrigger(bool trigger, char axis, Player* player, Enemies* enemy, Collider* collider, ArrayConio* mapscreen, size_t y, size_t x);
private:
	bool whowillatack();
	float enemyIndex;
	Enemies::Enemie01* tempEnemy;
	Player* player;
	ArrayConio* map;
	float atqPoints_player, defPoints_player, atqPoints_enemy, defPoints_enemy;
	void atacar(Player* player, Enemies::Enemie01* enemy);
	bool valido, gg;
	short menorvida;
	void modscreen();
	void vitoria();
	void derrota();
	void escapar();
	short key;
};

void Battle::battleTrigger(bool trigger, char axis, Player* player, Enemies* enemy, Collider* collider, ArrayConio* mapscreen, size_t y, size_t x) {
	//RANDOMIZER -- std::rand() % 12;
	for (size_t e = 0; e < enemy->enemiesString.length(); e++) {
		if (enemy->enemiesChar[e] == collider->temp) {
			if (e != 0) this->enemyIndex = 0.5 * e;
			else this->enemyIndex = 0.5 * ++e;
			this->valido = true;
			this->player = player;
			this->map = mapscreen;
			break;
		}
		else this->valido = false;
	}

	if (valido) {
		std::srand(time(NULL));
		this->tempEnemy = new Enemies::Enemie01(collider->temp, enemyIndex);
		for (size_t luta = 100; luta > 0; luta = menorvida) {
			system("cls");
			std::cout << "ENEMY LEVEL: " << enemyIndex << std::endl;
			this->modscreen();
			this->key = 0;
			this->atacar(this->player, this->tempEnemy);
			if (this->tempEnemy->getLife() < 1) {
				delete tempEnemy;
				this->tempEnemy = nullptr;
				this->vitoria();
				break;
			}
			else if (this->player->getLf() < 1) {
				delete tempEnemy;
				this->tempEnemy = nullptr;
				this->derrota();
				break;
			}
			Sleep(300);
		}
		
		switch (axis) {
		case 'Y':
			if (this->gg) this->map->getPtr()[y - 1][x] = '.';
			break;
		case 'y':
			if (this->gg) this->map->getPtr()[y + 1][x] = '.';
			break;
		case 'X':
			if(this->gg) this->map->getPtr()[y][x + 1] = '.';
			break;
		case 'x':
			if (this->gg) this->map->getPtr()[y][x - 1] = '.';
			break;
		}
	}

	if (this->tempEnemy != nullptr) {
		delete this->tempEnemy;
		this->tempEnemy = nullptr;
	}
}

bool Battle::whowillatack() {
	return std::rand() % 2;
}

void Battle::atacar(Player* player, Enemies::Enemie01* enemy) {
	std::string atacante, defensor;
	float rangeAtq, rangeDef;
	float dadoatq, dadodef;
	short first;
	bool acertou = false, fugiu = false;
	
	while (this->key != 32) {
		this->key = _getch();
		switch (this->key) {
		case 112:
			this->player->usePotion();
			break;
		case 32:
			first = this->whowillatack();
			break;
		case 27:
			if (std::rand() % 20 > 15) {
				this->escapar();
				this->key = 32;
				fugiu = true;
				std::cout << "VOCÊ ESCAPOU!";
			}
			else {
				first = 1;
				this->key = 32;
				std::cout << "VOCÊ NÃO PODE ESCAPAR!";
			}
			break;
		}
	}

	if (!fugiu) {
		if ((int)first == 0) {
			atacante = player->getPlayer();
			defensor = enemy->getEnemy();
			rangeAtq = player->getPlayerMod()->getBaseAtq();
			rangeDef = enemy->getEnemyMod()->getBaseDef();
		}
		else {
			atacante = enemy->getEnemy();
			defensor = player->getPlayer();
			rangeAtq = enemy->getEnemyMod()->getBaseAtq();
			rangeDef = player->getPlayerMod()->getBaseDef();
		}

		dadoatq = rangeAtq + ((float(std::rand()) / float((RAND_MAX)) * 1.0)) * (12 + 1);
		dadodef = rangeDef + ((float(std::rand()) / float((RAND_MAX)) * 1.0)) * (12 + 1);

		if ((dadoatq > 0) && (dadodef < dadoatq)) {
			if (dadoatq > 1) {
				dadoatq *= 1.2;
			}
			else if (dadoatq > 5) {
				dadoatq *= 1.5;
			}
			else if (dadoatq > 9) {
				dadoatq *= 1.2;
			}

			if (first == 0) {
				std::cout << "VOCÊ ACERTOU O ATAQUE! " << "SEU DADO DE ATAQUE: " << dadoatq << std::endl;
				std::cout << "DADO DE DEFESA DO INIMIGO: " << dadodef << std::endl;
				this->tempEnemy->setLife(this->tempEnemy->getLife() - dadoatq);
			}
			else {
				std::cout << "INIMIGO " << this->tempEnemy->getEnemy() << " ACERTOU O ATAQUE! " << "DADO DE ATAQUE: " << dadoatq << std::endl;
				std::cout << "DADO DE DEFESA DO INIMIGO: " << dadodef << std::endl;
				this->player->setLf(this->player->getLf() - dadoatq);
			}
		}
		else {
			first == 0 ? std::cout << '<' << this->tempEnemy->getEnemy() << "> DEFENDEU!" << std::endl : std::cout << "[PLAYER] DEFENDEU!" << std::endl;
		}

		this->menorvida = min(this->tempEnemy->getLife(), this->player->getLf());
		if (this->menorvida < 0) {
			this->menorvida = 0;
		}
	}
}

void Battle::modscreen() {
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "BATALHA!" << std::endl << "PLAYER[x]" << " VS " << "Enemy[" << this->tempEnemy->getEnemy() << ']' << std::endl << std::endl;
	std::cout << "<MODIFICADORES DE ATAQUE>" << std::endl;
	std::cout << "[PLAYER]: " << this->player->getPlayerMod()->getBaseAtq() << std::endl;
	std::cout << "[INIMIGO]<" << this->tempEnemy->getEnemy() << ">: " << this->tempEnemy->getEnemyMod()->getBaseAtq() << std::endl << std::endl;
	std::cout << ">MODIFICADORES DE DEFESA<" << std::endl;
	std::cout << "[PLAYER]: " << this->player->getPlayerMod()->getBaseDef() << std::endl;
	std::cout << "[INIMIGO]<" << this->tempEnemy->getEnemy() << ">: " << this->tempEnemy->getEnemyMod()->getBaseDef() << std::endl << std::endl;
	std::cout << "<><><><><>[PLAYER INVENTORY]<><><><><>" << std::endl;
	std::cout << "[POTIONS]: " << this->player->getPotions() << std::endl;
	std::cout << "<><><><><><><><><><><><><><><><><><><>" << std::endl << std::endl;
	std::cout << "[PLAYER HEALTH]:..[" << this->player->lifeToScreen() << ']' << std::endl;
	std::cout << "[ENEMY HEALTH]:...[" << this->tempEnemy->lifeToScreen() << ']' << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "['SPACE BAR' para atacar]" << std::endl;
	std::cout << "['P' para usar poção]" << std::endl;
}

void Battle::vitoria() {
	if (this->player->getLf() > 10) {
		this->player->getPlayerMod()->baseAtqUp();
		this->player->getLf() <= 90 ? this->player->setLf(this->player->getLf() + 10) : this->player->setLf(this->player->getLf());
	}
	this->gg = true;
	if (std::rand() % 30 > 20) {
		this->player->setPotions(this->player->getPotions() + 1);
	}
}
void Battle::derrota() {
	this->player->setLvs(this->player->getLvs() - 1);
	this->player->setLf(100);
	this->gg = false;
}

void Battle::escapar() {
	this->menorvida = 0;
}

#endif // !BATTLE_H_INCLUDED

