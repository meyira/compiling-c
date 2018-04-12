#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_overflow(){
    exit(-1); 
}

void add_x(int x){
    if((x+100)<x){
        puts("this is too large"); 
        handle_overflow(); 
    }
    printf("The nr+100 is %d\n", x+100); 

}

int main(int argc, char *argv[]){
    if(argc != 2){
        puts("Please supply a starting value!");
        return 1;
    }
    int x=atoi(argv[1]);
    add_x(x); 
    return 0; 
}
