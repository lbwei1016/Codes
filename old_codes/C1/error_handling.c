#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<limits.h>
#include<locale.h>
#include<string.h>
#include<math.h>

#include<errno.h>
int errno;

int main(void)
{
	// printf("%.*f\n", DBL_DIG, 3.1);
	// printf("%.*f\n", DBL_DECIMAL_DIG, 3.1);
	// printf("%d\n", DBL_DIG);
	// printf("%d\n", DBL_DECIMAL_DIG);
	// //printf("%lf\n", DBL_MAX);
	// printf("%d", INT_MAX);
	// int a = 10/3;
	// float b = (float)10/3;
	// float c = 10.0/3;
	// printf("%d %f %f", a, b, c);

	// FILE *fptr;

	// errno = 0;
	// fptr = fopen("wewr.txt", "rb");
	// if(fptr == NULL)
	// {
	// 	fprintf(stderr, "Error Code: %d\n", errno);
	// 	perror("Boo");
	// 	fprintf(stderr, "%s\n", strerror(errno));
	// 	exit(EXIT_FAILURE);
	// }
	//fclose(fptr);
	float a = -1;
	float b = 1000000;
	float c;
	errno = 0;

	c = sqrt(a);
	if(errno == EDOM)
		fprintf(stderr, "%s\n", strerror(EDOM));//domain error

	errno = 0;
	c = exp(b) * (-1);
	if(errno)
	{
		perror("BOO");
		fprintf(stderr, "%s\n", strerror(ERANGE));//result too large(or small)
	}
	else
		fprintf(stdout, "%f", c);

	// for(int i = 0; i<135; i++)
	// {
	// 	fprintf(stderr, "%d: %s\n", i, strerror(i));
	// }
}