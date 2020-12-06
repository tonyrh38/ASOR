#include <time.h>
#include <stdio.h>

int main() {
	time_t t;
	struct tm *res;
	time(&t);
	res = localtime(&t);
	printf("Estamos en el año: %d", 1900 + res->tm_year);
	return 1;
}
