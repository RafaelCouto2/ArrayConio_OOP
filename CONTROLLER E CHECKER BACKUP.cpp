void Game::controller() {
	switch (key) {
	case KEY_UP: //MOV PLAYER +Y
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[0][c]) {
						this->extremidade = true;
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->checkCollider('Y', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[l - 1][c]);
								*this->p = '1';
							}
						}
					}
				}
			}
		}
		break;
	case KEY_DOWN: //MOV PLAYER -Y
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[this->getLine() - 1][c]) {
						this->extremidade = true;
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->checkCollider('-Y', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[++l][c]);
								*this->p = '1';
							}
						}
					}
				}
			}
		}
		break;
	case KEY_LEFT: //MOV PLAYER -X
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) { 
					if (this->p == &this->t[l][0]) {
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->checkCollider('-X', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[l][c - 1]);
								*this->p = '1';
							}
						}
					}
				}
			}
		}
		break;
	case KEY_RIGHT: //MOV PLAYER +X
		for (size_t l = 0; l < this->getLine(); l++) {
			for (size_t c = 0; c < this->getColumn(); c++) {
				if (&this->t[l][c] == this->p) {
					if (this->p == &this->t[l][this->getColumn() - 1]) {
						this->p = &this->t[l][c];
						*this->p = '1';
					}
					else {
						if (!this->checkCollider('X', l, c, this->t)) {
							if (!this->extremidade) {
								*this->p = '.';
								this->p = &(this->t[l][++c]);
								*this->p = '1';
							}
						}
					}
				}
			}
		}
		break;
	case 100:
		this->player.setLf(this->player.getLf() - 5);
		break;
	}
}

bool Game::checkCollider(short modifier, short y, short x, char** map) {
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