#include "Collision.h"

bool Collision::Box(int posX, int posY, int radius, int posX2, int posY2, int radius2)
{
	if (posX-radius<posX2 + radius2 && posX + radius>posX2 - radius2 &&
		posY-radius<posY2 + radius2 && posY + radius>posY2 - radius2) {
		return true;
	}

	return false;
}
