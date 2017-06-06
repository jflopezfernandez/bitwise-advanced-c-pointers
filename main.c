
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


int main()
{
	system("cls");

	char *s;
	int i = sizeof("hello");
	s = (char *) malloc(i);

	strncpy(s, "hello", i);
	printf("s is %s\n", s);

	realloc(s, 12);
	strncpy(s, "hello", i);
	strcat(s, " world");

	printf("s is now %s\n", s);

	free(s);
    return EXIT_SUCCESS;
}