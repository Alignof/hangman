#include<hangman.h>
#define BUF_SIZE 100

void readfile(Words *words){
	FILE *fp;
	int line;
	char c;
	char buffer[BUF_SIZE];
	Words *new_word;

	if ((fp=fopen("./data/testdata.dat", "r")) == NULL) {
		fprintf(stderr,"File open error.\n");
		exit(1);
	}

	// get line number
	while((c=fgetc(fp))!=EOF)
		if(c=='\n') line++;

	printf("line:%2d\n",line);
	words=(Words *)malloc(line*sizeof(Words));
	new_word=words;

	fseek(fp, 0L, SEEK_SET);
	while(fgets(buffer,BUF_SIZE,fp)!=NULL){
		new_word->len=strlen(buffer);
		new_word->str=(char *)malloc(strlen(buffer)*sizeof(char));
		strncpy(new_word->str,buffer,new_word->len);

		new_word++;
	}

	for(int i=0;i<line;i++){
		printf("len:%3d\t word:%s",words[i].len,words[i].str);
	}
	fclose(fp);
}
