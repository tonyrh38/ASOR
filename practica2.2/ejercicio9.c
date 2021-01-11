#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>


int main(int argc, char *argv[]){

	if(argc != 2) return 0;
	else{
		struct stat status;
		if(stat(argv[1], &status) == -1) return 0;

		printf("Major: %lx Minor: %lx\n",(long)major(status.st_dev), (long)minor(status.st_dev));
		printf("i-node: %ld\n", status.st_ino);
		switch(status.st_mode & S_IFMT){
               	case S_IFDIR: printf("Tipo de fichero: Directorio\n");
			break;
		case S_IFLNK: printf("Tipo de fichero: Enlace simbolico\n");
			break;
		case S_IFREG: printf("Tipo de fichero: Fichero\n");
			break;
		default: printf("Tipo de fichero: iokeze illo\n");
			break;
			}
		printf("Ultimo acceso: %s", ctime(&status.st_atime));

	return 1;
	}
}
