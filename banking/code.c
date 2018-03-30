#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>

void failure(char *message){
	perror(message), 
	exit(-1);
}

void printer(){
    printf("INT_MIN= %d\n", INT_MIN);
    printf("INT_MAX= %d\n", INT_MAX);
}

int get_account_balance(char *account){
	int balance;
	FILE *database=fopen(account, "a+");
    fscanf(database, "%d", &balance);
    fclose(database);
    return balance; 
}

void get_balance(char *account){//null pointer in get_account_balance, ask for balance of nonexistent file, literally never checking return value
    int balance=get_account_balance(account);
	printf("Your account has %d ¢ in it", balance); 
}

void add_account(char *account){ //buffer overflow

}

void withdraw(int amount, char *account){ //integer overflow
    int original=get_account_balance(account); 
    original-=amount; 
    char *buf=malloc(sizeof(int)); 
    sprintf(buf, "%d", original);
	FILE *database=fopen(account, "w");
    write(fileno(database), buf, sizeof(int));
    fclose(database); 
}

void deposit(int amount, char *account){

}

int main(int argc, char *argv[]){
	int c=0; 
	char *account; 
	int amount; 

	while ((c = getopt (argc, argv, "adwhmn:")) != -1)
		switch (c)
		{
			case 'm': 
				amount=atoi(optarg); //show compiler optimization
				break; 
			case 'n': 
				account=malloc(strlen(optarg)+1);
				account=optarg; 
				break;  
			case 'd':
				deposit(amount, account);
				break;
			case 'w':
				withdraw(amount, account);
				break;
			case 'a':
				add_account(account);
				break;
			case 'h':
				puts("Usage: -d deposit, -w withdraw, -a add_account, -h show this menu, -m specify amount, -n specify account");
				return 1;
			default:
				exit(1);
		}

}
