#include<stdio.h>
#include<string.h>

#define CHARMAX 200

#include "comands.h"


int main() {

    char name[CHARMAX];

    char bus[30] = "Nombre=\"";

    FILE *f = fopen("new/0c69630b-e478-4388-a0fa-a106d8cc0b53.xml","r");


    char rt[100];
    Search(f,bus,rt);
    // printf("%s\n",rt);
    fclose(f);

    

    printf("%s",rt);
}

