#include <sys/time.h>
#include <stdio.h>

int main() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	for(int i = 0; i < 1000000; i++);
	struct timeval tv2;
	gettimeofday(&tv2, NULL);
	printf("El bucle tarda %d microsegundos\n", tv2.tv_usec - tv.tv_usec);	

	return 1;
}
