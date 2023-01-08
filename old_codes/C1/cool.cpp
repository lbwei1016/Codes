#include <stdio.h>
#include <string.h>

int main()
{
	struct person
	{
		int age;
		char name[50];
		float height, weight;
	};
	
	typedef struct
	{
		int a;
		char s[50];
	}good;
	
	struct person p1 = {16, "Willam", 161.1, 53.0};
	struct person p2;
	p2 = (struct person){16, "Ruby"};
	
	good g1;
	g1.a = 10;
	strcpy(g1.s, "Wow");
	
	printf("%d %s %.3f\b %.3f%%", p1.age, p1.name, p1.height, p1.weight);
	printf("\n%d %s", p2.age, p2.name);
	printf("\n\t%d, %s", g1.a, g1.s);
	return 0;
}
