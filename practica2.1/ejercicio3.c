#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main() {
	for(int i = 0; i < 255; i++)
		perror(strerror(i));
	return 1;
}
