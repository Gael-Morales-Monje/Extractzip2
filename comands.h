#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void makeDir(char name[]);
int exist(char name[] );
void removeDir(char name[]);

void lsToFile(char name[]);

void Search(FILE *test,char search[],char end,char rt[]);



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


void Search(FILE *test,char search[],char end,char rt[]) {
    char c;
    int count = 1;
    int k = 0;
    
    char text[100];
    int rtCount = 0;
    while ((c = fgetc(test)) != EOF) {
        int i;
        if (c == search[0] && k == 0){
            for (i = 1; i < strlen(search); i++) {
                if ((c = fgetc(test)) == search[i]) {
                    count++;
                    if (count == strlen(search)) {
                        k = 1;
                    }
                } else {
                    count = 1;
                    break;
                }
            }
        }
        if (k == 1){
            int i;
            for (i = 0;(c = fgetc(test)) != end; i++) {
                if (c == ' ') {
                    rt[i] = '-';
                } else {
                    rt[i] = c;
                }
            }
            rt[i] = '\0';
            return;
        }
    }
    
}




void ExtractName(FILE *file) {
    char Emisor[12] = "cfdi:Emisor";
    char REceptor[14] = "cfdi:Receptor";



    char StrEmisor[100];

    Search(file,Emisor,'>',StrEmisor);

    printf("%s",StrEmisor);



}