#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
    Expenses simulator. 
    argv[1] = the starting amount you currently have in your account. 
    add money with 
        a amount
    take money out of the account with
        s amount
    if you are done, type
        q
*/
int main (int argc, char *argv[]){
    int stop=0; 
    if(argc != 2){
        puts("Please supply a starting amount of money you would like to simulate your expenses with!");
        return 1;
    }
    int amount=atoi(argv[1]);
    char c; 
    int nr; 
    printf("You have %d money in your account! \n", amount);
    while(stop !=1){
        puts("Enter a to add money to or s to take money out of your account. Press q 0 to quit.");
        scanf("%c ", &c);
        if(c=='a'){
            scanf("%d", &nr);
            amount += nr; 
        }
        else if (c=='s'){
            scanf("%d", &nr);
            amount -=nr; 
        }
        else if (c=='q'){
            puts("Exiting. Thanks for using the expense simulator");
            stop=1;
        }
        else {
            puts("Sorry, I did not understand");
        }
        printf("Your current balance is %d money.\n", amount);
    }
    return 0;
}
