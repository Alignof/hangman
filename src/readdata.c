#include<hangman.h>
#define BUF_SIZE 100

void readfile(char **words){
	FILE *fp;
	int line;
	char c;
	char buffer[BUF_SIZE];

	if ((fp=fopen("./data/testdata.dat", "r")) == NULL) {
		fprintf(stderr,"File open error.\n");
		exit(1);
	}

	// get line number
	while((c=fgetc(fp))!=EOF)
		if(c=='\n') line++;

	words=(char **)malloc(line*sizeof(char*));
	printf("line:%2d\n",line);

	fseek(fp, 0L, SEEK_SET);
	while(fgets(buffer,BUF_SIZE,fp)!=NULL){
		printf("len:%2d\t word:%s",strlen(buffer),buffer);
	}
		

	fclose(fp);
}
