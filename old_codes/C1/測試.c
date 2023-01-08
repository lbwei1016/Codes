#include <stdio.h>

#define NOW 2020 // rat
int main(void)
{
	int y;
	while(scanf("%d", &y) != EOF)
	{
		int diff = (y-NOW)%12;
		switch((diff+12)%12)
		{
			case 0:
				printf("Rat\n");
				break;
			case 1:
				printf("Ox\n");
				break;
			case 2:
				printf("Tiger\n");
				break;
			case 3:
				printf("Hare\n");
				break;
			case 4:
				printf("Dragon\n");
				break;
			case 5:
				printf("Snake\n");
				break;
			case 6:
				printf("Horse\n");
				break;
			case 7:
				printf("Sheep\n");
				break;
			case 8:
				printf("Monkey\n");
				break;
			case 9:
				printf("Rooster\n");
				break;
			case 10:
				printf("Dog\n");
				break;
			case 11:
				printf("Pig\n");
				break;
		}
	}
	return 0;
}