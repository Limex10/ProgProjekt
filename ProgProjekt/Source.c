#include "library.h"


int main(void)
{
	int width = 20;
	int height = 20;
	int walls = 10;
	char door = ' ';
	char key = ' ';
	MapT tMap;

	positionT *tPosition = (positionT*)malloc(sizeof(positionT));

	int nrKeys = 0;
	int x = 0;
	int y = 0;
	char selector;
	tMap = createMap(width, height, walls);
	placeObject(tMap, x, y, '@', tPosition, 1);
	


	while (1)
	{
		
		system("cls");
		printf("%d", nrKeys);
		drawMap(tMap);
		
		selector = getchar();
		switch (selector)
		{

		case 'w':
		{

			door = placeObject(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1);
			key = door;
			if (key == 'K')
			{

				printf("du har hittat en nyckel");
				nrKeys++;
				getchar();
			}
			else if (door == 'D')
			{
				if (nrKeys > 0)
				{
					doorMover(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1);

					printf("du har låst upp en dörr");
					nrKeys--;
					getchar();
				}
				else
				{
					printf("du har inte nog med nycklar");
					getchar();
					getchar();
				}
			}
			removeObject(tMap, tPosition->row + 1, tPosition->col, ' ', tPosition, 1);
			
			break;
		}

		case 'a':
		{	

			door = placeObject(tMap, tPosition->row, tPosition->col - 1, '@', tPosition, 1);
			key = door;
			if (key == 'K')
			{

				printf("du har hittat en nyckel");
				nrKeys++;
				getchar();
			}
			else if (door == 'D')
			{
				if (nrKeys > 0)
				{
					doorMover(tMap, tPosition->row, tPosition->col - 1, '@', tPosition, 1);

					printf("du har låst upp en dörr");
					nrKeys--;
					getchar();
				}
				else
				{
					printf("du har inte nog med nycklar");
					getchar();
					getchar();
				}
			}
			removeObject(tMap, tPosition->row, tPosition->col + 1, ' ', tPosition, 1);

			break;
		}

		case 'd':
		{
	
				door = placeObject(tMap, tPosition->row, tPosition->col + 1, '@', tPosition, 1);
				key = door;
			if (key == 'K')
			{

				printf("du har hittat en nyckel");
				nrKeys++;
				getchar();
			}
			else if (door == 'D')
			{
				if(nrKeys > 0)
				{
					doorMover(tMap, tPosition->row, tPosition->col + 1, '@', tPosition, 1);

					printf("du har låst upp en dörr");
					nrKeys--;
					getchar();
				}
				else
				{
					printf("du har inte nog med nycklar");
					getchar();
					getchar();
				}
				
			}
			removeObject(tMap, tPosition->row, tPosition->col - 1, ' ', tPosition, 1);
			break;
		}

		case 's':
		{

			door = placeObject(tMap, tPosition->row + 1, tPosition->col , '@', tPosition, 1);
			key = door;
			if (key == 'K')
			{

				printf("du har hittat en nyckel");
				nrKeys++;
				getchar();
			}
			else if (door == 'D')
			{
				if (nrKeys > 0)
				{
					doorMover(tMap, tPosition->row + 1, tPosition->col, '@', tPosition, 1);

					printf("du har låst upp en dörr");
					nrKeys--;
					getchar();
				}
				else
				{
					printf("du har inte nog med nycklar");
					getchar();
					getchar();
				}
			}

			removeObject(tMap, tPosition->row - 1, tPosition->col, ' ', tPosition, 1);

			break;
		}

		default:
			break;
		}


		
	}

	return 0;
}