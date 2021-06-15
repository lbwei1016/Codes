#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr;
	int times = 0, age, count = 0, data2;
	char mode[5], name[50], gender[10], data1[50];
	printf("Please enter mode and numbers:\n");
	scanf("%s%d", mode, &times);
	printf("Enter files:\n");
	
	fptr = fopen("test_1.txt", mode);
	if(fptr == NULL)
		return -1;
	while(times--)
	{
		scanf("%s%d%s", name, &age, gender);
		fprintf(fptr, "Name: %s\nAge: %d\nGender: %s\n", name, age, gender);
		count++;
	}
	fclose(fptr);

	fptr = fopen("test_1.txt", "r");
	if(fptr == NULL)
		return -1;
	while(count--)
	{
		fgets(data1, 50, fptr);
		printf("%s", data1);
		fscanf(fptr, "%s%d", data1, &data2);
		printf("%s %d\n", data1, data2);
		fgets(data1, 10, fptr);//for reading '\n'
		fgets(data1, 50, fptr);
		printf("%s", data1);
	}
	printf("\n%ld\n",ftell(fptr));
	fclose(fptr);


	return 0;
}