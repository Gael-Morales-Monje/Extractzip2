

#include "comands.h"
// #include <sys/wait.h>

int main (int argc, char *argv[]) {

	char path[50];
	FILE *ap = fopen("path.dat","r");
	fscanf(ap,"%s",path);
	fclose(ap);

	

	chdir(path);
	system("ls > tem.dat");

	FILE *af = fopen("tem.dat","r");
	char c;
	int count = 0;
	while ((c = fgetc(af)) != EOF) {
		if(c == '\n') count++;
	}
	
	rewind(af);
	

	char list[count][50];
	int i = 0;
	while (fscanf(af,"%s",list[i]) == 1 )i++;
	
	fclose(af);

	
	for (int i = 0; i < count; i++) {
		printf("%s\n",list[i]);
	}


	chdir("new8");
	system("ls > zip.name");


	FILE *zip = fopen("zip.name","r");
	char zipName[100];

	fscanf(zip,"%s",zipName);

	fclose(zip);
	system("rm zip.name");

	char Comm[200];



	sprintf(Comm,"unzip %s",zipName);
	system(Comm);

	system("ls > resul.dat");



	
	return 0;
}
