#include "library.h"


int main(void)
{
	system("chcp 1252");
	int width = 20;
	int height = 20;
	int walls = 10;
	char object = ' ';
	int game = 1;
	MapT tMap;

	positionT *tPosition = (positionT*)malloc(sizeof(positionT));

	int nrKeys = 0;
	int nrPoints = 0;
	int x = 0;
	int y = 0;
	char selector;
	tMap = createMap(width, height, walls);

	for (int i = 0; i < 9; i++)
	{
		placeObject(tMap, x, y, 'P', tPosition, 1);
	}
	placeObject(tMap, x, y, '@', tPosition, 1);
	while (game == 1)
	{
		while ((getchar()) != '\n'); // for clearing the keyboard buffert.
		system("cls");
		printf("Antal nycklar %d \n", nrKeys);
		printf("Antal poäng %d", nrPoints);
		drawMap(tMap);
		
		

		selector = getchar();
		switch (selector)
		{

		case 'w':
		{

			object = placeObject(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1); // giving the var a char.
	
			if (object == 'K') // for picking up keys.
			{
				printf("du har hittat en nyckel");
				nrKeys++;
				getchar();
			}
			else if (object == 'D') // for opening doors
			{
				if (nrKeys > 0) // more than 0 keys to open doors.
				{
					doorMover(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1); // function to move kermit to a door location.

					printf("du har låst upp en dörr");
					nrKeys--;
					getchar();
				}
				else // when you do not  have enough keys.
				{
					printf("du har inte nog med nycklar");
					getchar();				}
			}
			else if (object == 'P') // function for picking upp keys.
			{
				doorMover(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1);

				printf("Du fick ett poäng");
				nrPoints++;
				getchar();

			}
			else if(object == 'e')
			{
				printf("du har stött på en vägg");
				getchar();
				
			}
			else if (object == 'M') // for exiting the main entrance.
			{
				if (nrPoints == 9)
				{
					doorMover(tMap, tPosition->row - 1, tPosition->col, '@', tPosition, 1);

					printf("Du har vunnit spelet");
					getchar();
					getchar();
					game = 0;
				}
				else  // not enough points to win.
				{
					printf("Du har inte tillräckligt med poäng, samla fler");
					getchar();
				}
			}
			removeObject(tMap, tPosition->row + 1, tPosition->col, ' ', tPosition, 1); //Removing the "Shadow" of kermit.
			
			break;
		}

		case 'a':
		{	

			object = placeObject(tMap, tPosition->row, tPosition->col - 1, '@', tPosition, 1);

			if (object == 'K')
			{

				printf("du har hittat en nyckel");
				nrKeys++;
				getchar();
			}
			else if (object == 'D')
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
				}
			}
			else if (object == 'e')
			{
				printf("du har stött på en vägg");
				getchar();
			}
			else if (object == 'P')
			{
				doorMover(tMap, tPosition->row, tPosition->col - 1, '@', tPosition, 1);

				printf("Du fick ett poäng");
				nrPoints++;
				getchar();

			}
			else if (object == 'M')
			{
				if (nrPoints == 9)
				{
					doorMover(tMap, tPosition->row, tPosition->col - 1, '@', tPosition, 1);

					printf("Du har vunnit spelet");
					getchar();
					getchar();
					game = 0;
				}
				else
				{
					printf("Du har inte tillräckligt med poäng, samla fler");
					getchar();
				}
			}
			removeObject(tMap, tPosition->row, tPosition->col + 1, ' ', tPosition, 1);

			break;
		}

		case 'd':
		{
	
				object = placeObject(tMap, tPosition->row, tPosition->col + 1, '@', tPosition, 1);

			if (object == 'K')
			{

				printf("du har hittat en nyckel");
				nrKeys++;
				getchar();
			}
			else if (object == 'D')
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
				}
				
			}
			else if (object == 'e')
			{
				printf("du har stött på en vägg");
				getchar();
				
			}
			else if (object == 'P')
			{
				doorMover(tMap, tPosition->row, tPosition->col + 1, '@', tPosition, 1);

				printf("Du fick ett poäng");
				nrPoints++;
				getchar();

			}
			else if (object == 'M')
			{
				if (nrPoints == 9)
				{
					doorMover(tMap, tPosition->row, tPosition->col + 1, '@', tPosition, 1);

					printf("Du har vunnit spelet");
					getchar();
					getchar();
					game = 0;
				}
				else
				{
					printf("Du har inte tillräckligt med poäng, samla fler");
					getchar();
				}
			}

			removeObject(tMap, tPosition->row, tPosition->col - 1, ' ', tPosition, 1);
			break;
		}

		case 's':
		{

			object = placeObject(tMap, tPosition->row + 1, tPosition->col , '@', tPosition, 1);

			if (object == 'K')
			{

				printf("du har hittat en nyckel");
				nrKeys++;
				getchar();
			}
			else if (object == 'D')
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
				}
			}
			else if (object == 'e')
			{
				printf("du har stött på en vägg");
				getchar();
			}
			else if (object == 'P')
			{
				doorMover(tMap, tPosition->row + 1, tPosition->col, '@', tPosition, 1);

				printf("Du fick ett poäng");
				nrPoints++;
				getchar();

			}
			else if (object == 'M')
			{
				if (nrPoints == 9)
				{
					doorMover(tMap, tPosition->row + 1, tPosition->col, '@', tPosition, 1);
					
					printf("Du har vunnit spelet");
					getchar();
					getchar();
					game = 0;
				}
				else 
				{
					printf("Du har inte tillräckligt med poäng, samla fler");
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