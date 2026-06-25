#include<stdio.h>
#include<string.h>
#include "../comands.h"
int main() {

    FILE *file = fopen("test.xml","r");

    ExtractName(file);

    fclose(file);
    return 0;
}