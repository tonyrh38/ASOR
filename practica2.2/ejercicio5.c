#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	
	int openOptions = O_WRONLY | O_CREAT;
	int userPer = S_IRUSR | S_IWUSR;
	int groupPer = S_IRGRP;
	int othersPer = S_IROTH | S_IXOTH;

	open("./ejercicio5.txt", openOptions, userPer | groupPer | othersPer);

	return 1;
}
