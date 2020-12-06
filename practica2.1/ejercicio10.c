#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
	printf("UID real: %d\n", getuid());
	printf("UID efectivo: %d\n", geteuid());

	struct passwd *pw =  getpwuid(getuid());
	printf("Nombre de usuario: %s\n", pw->pw_name);
	printf("Directorio home: %s\n", pw->pw_dir);
	printf("Descripcion del usuario: %s\n", pw->pw_gecos);

	return 1;
}
