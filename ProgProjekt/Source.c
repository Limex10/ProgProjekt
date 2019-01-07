#include "library.h"


int main(void)
{
	int width = 20;
	int height = 20;
	int walls = 10;
	char door = ' ';
	char key = ' ';
	char points = ' ';
	char master = ' ';
	MapT tMap;

	positionT *tPosition = (positionT*)malloc(sizeof(positionT));

	int nrKeys = 0;
	int nrPoints = 0;
	int x = 0;
	int y = 0;
	char selector;
	tMap = createMap(width, height, walls);

	placeObject(tMap, x, y, 'P', tPosition, 1);
	placeObject(tMap, x, y, 'P', tPosition, 1);
	placeObject(tMap, x, y, 'P', tPosition, 1);
	placeObject(tMap, x, y, 'P', tPosition, 1);
	placeObject(tMap, x, y, 'P', tPosition, 1);
	placeObject(tMap, x, y, 'P', tPosition, 1);
	placeObject(tMap, x, y, 'P', tPosition, 1);
	placeObject(tMap, x, y, 'P', tPosition, 1);
	placeObject(tMap, x, y, 'P', tPosition, 1);
	placeObject(tMap, x, y, '@', tPosition, 1);
	

	


	while (1)
	{
		
		system("cls");
		printf("Antal nycklar %d \n", nrKeys);
		printf("Antal poäng %d", nrPoints);
		drawMap(tMap);
		
		selector = getchar();
		switch (selector)
		{

		case 'w':
		{

			door = placeObject(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1);
			key = door;
			points = key;
			master = points;
			
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
			else if (points == 'P')
			{
				doorMover(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1);

				printf("Du fick ett poäng");
				nrPoints++;
				getchar();

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
			else if (master == 'M')
			{
				if (nrPoints == 9)
				{
					doorMover(tMap, tPosition->row + 1, tPosition->col, '@', tPosition, 1);
					
					printf("Du har vunnit spelet");
				}
				else 
				{
					printf("Du har inte tillräckligt med poäng, samla fler");
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