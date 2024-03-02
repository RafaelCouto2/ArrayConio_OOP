#pragma once
#ifndef PLAYERCOLLIDERCHECKER_H_INCLUDED
#define PLAYERCOLLIDERCHECKER_H_INCLUDED

class Collider {
public:
	bool checkCollider(short modifier, size_t y, size_t x, char** map);
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
	}
}

#endif // !PLAYERCOLLIDERCHECKER_H_INCLUDED
