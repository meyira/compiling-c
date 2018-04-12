#include <stdio.h> 
#include <stdlib.h> //atoi
#include <unistd.h> //Exit

int square(int a){
    return a*a; 
}

int main(int argc, char *argv[]){
    if(argc!=2) exit(1); 
    int a=atoi(argv[1]);
    //    int a=7;
    int sq=square(a);
    printf("The squared value is %d\n", sq);
    return 0;
}
