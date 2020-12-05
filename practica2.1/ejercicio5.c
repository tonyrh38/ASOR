#include <sys/utsname.h>
#include <stdio.h>

int main() {
	struct utsname data;
	uname(&data);

	printf("\nName: %s\n", data.sysname);
	printf("\nNode: %s\n", data.nodename);
	printf("\nRelease: %s\n", data.release);
	printf("\nVersion: %s\n", data.version);
	printf("\nMachine: %s\n", data.machine);

	return 1;
}
