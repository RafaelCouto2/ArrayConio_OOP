#pragma once
#ifndef PLAYERCOLLIDERCHECKER_H_INCLUDED
#define PLAYERCOLLIDERCHECKER_H_INCLUDED

class Collider {
public:
	bool checkCollider(short modifier, size_t y, size_t x, char** map);
	bool battleChecker(short modifier, char** map, std::string enemy, size_t y, size_t x);
protected:

private:

};

bool Collider::checkCollider(short modifier, size_t y, size_t x, char** map) {
	//DETERMINE THE COLLIDER DIRECTION CHECKER BY MODIFIER
	switch (modifier) {
	case 'Y':
		return (map[y - 1][x] != '.');
		break;
	case '-Y':
		return (map[++y][x] != '.');
		break;
	case '-X':
		return ((map[y][x - 1] != '.'));
		break;
	case 'X':
		return (map[y][++x] != '.');
		break;
	default:
		return true;
		break;
	}
}

bool Collider::battleChecker(short modifier, char** map, std::string enemy, size_t y, size_t x) {
	switch (modifier) {
	case 'Y':
		for (size_t e = 0; e < enemy.length(); e++) {
			if (map[y - 1][x] == enemy.at(e)) {
				std::cout << "YOU`V TOUCHED A ENEMY! LET`S BATTLE!";
				Sleep(800);
				return true;
				break;
			}
		}
		return false;
		break;
	case '-Y':
		for (size_t e = 0; e < enemy.length(); e++) {
			if (map[y + 1][x] == enemy.at(e)) {
				std::cout << "YOU`V TOUCHED A ENEMY! LET`S BATTLE!";
				Sleep(800);
				return true;
				break;
			}
		}
		return false;
		break;
	case '-X':
		for (size_t e = 0; e < enemy.length(); e++) {
			if (map[y][x - 1] == enemy.at(e)) {
				std::cout << "YOU`V TOUCHED A ENEMY! LET`S BATTLE!";
				Sleep(800);
				return true;
				break;
			}
		}
		return false;
		break;
	case 'X':
		for (size_t e = 0; e < enemy.length(); e++) {
			if (map[y][x + 1] == enemy.at(e)) {
				std::cout << "YOU`V TOUCHED A ENEMY! LET`S BATTLE!";
				Sleep(800);
				return true;
				break;
			}
		}
		return false;
		break;
	default:
		return false;
		break;
	}
}

#endif // !PLAYERCOLLIDERCHECKER_H_INCLUDED
