
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


struct _a {
	int a; 				// 4 bytes
	int c; 				// 4 bytes
	double b; 			// 8 bytes
	long long int d; 	// 8 bytes
};

struct _b {
	int a; 				// 4 bytes
	double b; 			// 8 bytes
	int c; 				// 4 bytes
	long long int d; 	// 8 bytes
};

#define COUNT 4


int main()
{
	system("cls");


    return EXIT_SUCCESS;
}