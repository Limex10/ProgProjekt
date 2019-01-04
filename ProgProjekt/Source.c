#include "library.h"


int main(void)
{
	int width = 20;
	int height = 20;
	int walls = 10;
	MapT tMap;

	positionT *tPosition = (positionT*)malloc(sizeof(positionT));

	int x = 0;
	int y = 0;
	char selector;
	tMap = createMap(width, height, walls);
	placeObject(tMap, x, y, '@', tPosition, 1);


	while (1)
	{
		system("cls");
		drawMap(tMap);
		selector = getchar();
		switch (selector)
		{

		case 'w':
		{
			placeObject(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1);
			removeObject(tMap, tPosition->row + 1, tPosition->col, ' ', tPosition, 1);
			if (keyChecker(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1) == 1)
			{
				
				printf("du har hittat en nyckel");

				getchar();
				getchar();
			}
			
			removeObject(tMap, tPosition->row + 1, tPosition->col, ' ', tPosition, 1);
			
			
			
			break;
		}

		case 'a':
		{
			
			placeObject(tMap, tPosition->row , tPosition->col - 1, '@', tPosition, 1);
			removeObject(tMap, tPosition->row, tPosition->col + 1, ' ', tPosition, 1);
			keyChecker(tMap, tPosition->row, tPosition->col - 1, '@', tPosition, 1);

			break;
		}

		case 'd':
		{
			placeObject(tMap, tPosition->row, tPosition->col + 1, '@', tPosition, 1);
			removeObject(tMap, tPosition->row, tPosition->col - 1, ' ', tPosition, 1);
			keyChecker(tMap, tPosition->row, tPosition->col + 1, '@', tPosition, 1);
			break;
		}
		case 's':
		{
			placeObject(tMap, tPosition->row + 1, tPosition->col, '@', tPosition, 1);
			removeObject(tMap, tPosition->row - 1, tPosition->col, ' ', tPosition, 1);
			keyChecker(tMap, tPosition->row + 1, tPosition->col, '@', tPosition, 1);
			break;
		}

		default:
			break;
		}


		
	}


	return 0;
}