#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void makeDir(char name[]);
int exist(char name[] );
void removeDir(char name[]);

void lsToFile(char name[]);





void removeDir(char name[]) {
    if (exist(name) == 1) {
        char Comm[100];

        sprintf(Comm,"rm -r %s",name);
        system(Comm);
    } else {
        printf("no existe\n");
    }
}



int exist(char name[] ) {
    char test[40];
    sprintf(test,"[ -d '%s' ]",name);
    int status = system(test);
    if (status == 0) return 1;
    else return 0; 
}

void makeDir(char name[]){
    char Comm[200];
    
    if (exist(name) == 1) {
        printf("Existe el directorio\n");

    } else {
        sprintf(Comm, "mkdir %s",name);
        system(Comm);
    }
    
}