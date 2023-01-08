#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern int errno;

int main(void)
{
	typedef struct 
	{
		char name[50];
		int age;
	}id;

	id per1, per2, per2c;
	strcpy(per1.name, "William");
	strcpy(per2.name, "Ruby");
	per1.age = 16;
	per2.age = 16;

	errno = 0;
	char c;

	FILE *fptr;
	fptr = fopen("test_3.txt", "wb");
		
	fwrite(&per1, sizeof(per1), 1, fptr);
	fwrite(&per2, sizeof(per2), 1, fptr);
	fclose(fptr);

	fptr = fopen("test_3.txt", "rb");
	if(fptr == NULL)
	{
		printf("Open Wrong File");
		fprintf(stderr, "%s\n", strerror(errno));
		exit(-1);
	}
	fseek(fptr, sizeof(per1), SEEK_SET);
	fread(&per2c, sizeof(per2), 1, fptr);

	while((c = getc(fptr))!= EOF)
		printf("%c", c);

	if(ferror(fptr))
	{
		printf("I/O error reading file\n");
		exit(-1);
	}
	if(feof(fptr))
		printf("End of file reached\n");

	fclose(fptr);

	printf("%s %d\n", per2c.name, per2c.age);
	return 0;
}