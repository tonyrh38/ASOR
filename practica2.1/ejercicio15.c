#include <time.h>
#include <stdio.h>

int main() {
	time_t t;
	struct tm *res;
	char ptr [100];
	time(&t);
	res = localtime(&t);
	strftime(ptr,100,"Es %A, %d de %B de %G, %R",res);
	printf(ptr);
	return 1;
}
