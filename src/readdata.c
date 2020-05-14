#include<hangman.h>
#define BUF_SIZE 1000

int count_strlen(char **buffer){
	int len=0;
	char *buf;
	
	buf=*buffer;
	// count string len
	while((*buf) != ' ' && *buf != NULL){
		buf++;
		len++;
	}

	return len;
}

void readfile(Words *words){
	FILE *fp;
	int line;
	char c;
	char *buffer;
	char *start;
	Words *new_word;

	start=buffer;
	buffer=(char *)malloc(BUF_SIZE*sizeof(char));

	if ((fp=fopen("./data/toeic1500.dat", "r")) == NULL) {
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
		// consume number
		new_word->number=(int)strtol(buffer,&buffer,10);

		// consume space
		while((*buffer) == ' ') buffer++;

		// get string len
		new_word->len=count_strlen(&buffer);

		// string copy
		new_word->str=(char *)malloc((new_word->len)*sizeof(char));
		strncpy(new_word->str,buffer,new_word->len);

		new_word++;
		buffer=start;
	}
	
	for(int i=0;i<line;i++)
		printf("len:%d\tstr:%s\n",words[i].len,words[i].str);

	fclose(fp);
}
