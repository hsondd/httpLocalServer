#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void newhandler(int sig){
    printf("\nI received signal %d", sig);
}
int main(){
    int i =0;
    if(signal(SIGINT, newhandler) == SIG_ERR){
        perror("\nSIGINT");
        exit(3);
    }
    while (1);
    return 0;
    
}