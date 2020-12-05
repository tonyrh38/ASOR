#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
	printf("UID real: %d\n", getuid());
	printf("UID efectivo: %d\n", geteuid());

	return 1;
}

// Si el usuario del fichero del programa y el EUID del proceso son el mismo, el fichero tiene el bit setuid activo.
