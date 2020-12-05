#include <unistd.h>
#include <stdio.h>

int main() {
	printf("Numero maximo de enlaces: %ld\n", pathconf("/",_PC_LINK_MAX
));
	printf("Tamaño maximo de ruta: %ld\n", pathconf("/",_PC_PATH_MAX));
	printf("Tamaño maximo de nombre de fichero: %ld\n", pathconf("/",_PC_NAME_MAX));

	return 1;
}
