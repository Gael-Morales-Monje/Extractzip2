#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include "comands.h"
int main(int argc, char *argv[]) {

    char root[120] = "/home/gael/Downloads";

    char comm[200];

    sprintf(comm,"ls %s/*.zip > list.dat",root);

    system(comm);

    FILE *list = fopen("list.dat","r");


    char name[120];
    fscanf(list,"%s",name);

    char comm2[200];

    sprintf(comm2,"cp %s new",name);
    system(comm2);
    chdir("new");
    

    char comm3[200];

    sprintf(comm3,"unzip %s",name);
    system(comm3);

    system("ls *.xml > ../xmlNames.dat");
    
    FILE *xmln = fopen("../xmlNames.dat","r");

    char xmlFIle[200];

    fscanf(xmln, "%s",xmlFIle);
    

    FILE *xml = fopen(xmlFIle,"r");

    
    char rt[100];
    Search(xml,"Nombre=\"",'\"',rt);
    rewind(xml);

    char Date[100];

    Search(xml,"Fecha=\"",'\"',Date);

    fclose(xml);

    char month[5];
    for (int i = 0; i < strlen(Date); i++) {
        if( Date[i] == '-' ){
            month[0] = Date[i+1];
            month[1] = Date[i+2];
            month[2] = '\0';
            break;
        }
    }
    
    makeDir(rt);
    char comm10[300];

    chdir(rt);
    makeDir(month);
    chdir("../");
    sprintf(comm10,"mv *.xml %s/%s/",rt,month);
    system(comm10);
    char final[200];
    sprintf(final,"rm -r %s",name);

    // system(final);

    fclose(xmln);
    fclose(list);

    // system("rm -r *");

    return 0;

}