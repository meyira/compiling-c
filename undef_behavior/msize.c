#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 2) return -1;
    int s=atoi(argv[1]);
    if(!s){
        puts("Division by zero detected -- aborting"); 
        s=1/s;
    }
    printf("The entered number was %d\n", s);
    return 0;
}
