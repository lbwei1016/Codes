#include<stdio.h>

int main(void)
{
	FILE *fptr;
	char t[10];
	int i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	fptr = fopen("test_2.dat", "wb");
	if(fptr == NULL)
	{
		printf("Error");
	}
	printf("%ld\n", ftell(fptr));
	fwrite(i, sizeof(i[0]), sizeof(i)/sizeof(i[0]), fptr);
	fprintf(fptr, "\n");
	printf("%ld\n", ftell(fptr));
	fclose(fptr);
	return 0;
}