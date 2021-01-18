#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	if(argc != 2) return 0;
	DIR *dir = opendir(argv[1]);
	if(dir == NULL) return 0;
	struct stat *buf;
	struct dirent *dit;
	int nbytes = 0;
	int bufsiz = 256;
	char buff[bufsiz];
	while ((dit = readdir(dir)) != NULL){
		switch(dit->d_type){
			case DT_REG:
				stat(dit->d_name, buf);
				//nbytes = nbytes + buf->st_size;	Me da Segmentation Fault				
				if(buf->st_mode & S_IXUSR | S_IXGRP | S_IXOTH){
					printf("%s *\n", dit->d_name);
				}
				else printf("%s\n", dit->d_name);			
				break;		
			case DT_DIR: 
				printf("%s /\n", dit->d_name);
				break;
			case DT_LNK: 
				readlink(dit->d_name, buff, bufsiz);
				printf("%s -> %s", dit->d_name, buff); // No me reconoce buff por algun motivo
				break;
			default:
				break;
		} 
    }
	printf("Size(Kb): %f\n", nbytes / 1024);	

	return 1;
}
