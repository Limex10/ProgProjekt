#include "library.h"


int main(void)
{
	int width = 20;
	int height = 20;
	int walls = 10;
	MapT tMap;
	positionT tPosition;
	tPosition.col = 0;
	tPosition.row = 0;

	
	tMap = createMap(width, height, walls);
	placeObject(tMap, 0, 0, '@', &tPosition, 1);


	drawMap(tMap);
	
	getchar();

	return 0;
}