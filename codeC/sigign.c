#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	if(signal(SIGINT, SIG_IGN) == SIG_ERR){
		perror("SIGINT\n");
		exit(3);
	}
	while(1);
	return 0;

}
