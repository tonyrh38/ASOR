#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main() {
	if(setuid(0) == -1)
		perror(strerror(errno));
	return 1;
}
