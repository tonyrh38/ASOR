#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <string.h>

int link(const char *oldpath, const char *newpath);
int symlink(const char *oldpath, const char *newpath);

int main(int argc, char *argv[]){
	if(argc != 2) return 0;
	struct stat status;
	if(stat(argv[1], &status) == -1) return 0;
	if(status.st_mode & S_IFMT != S_IFREG) return 0;
	char hlink[99], slink[99];
	strcpy(hlink, argv[1]);
	strcpy(slink, argv[1]);
	link(argv[1], strcat(hlink, ".hard"));
	symlink(argv[1], strcat(slink, ".sym"));

	return 1;
}
