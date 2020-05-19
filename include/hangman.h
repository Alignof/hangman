#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<termio.h>

typedef struct{
	int len;
	char *str;
	bool is_wrong;
	bool is_collect;
	bool is_answered;
}Words;

int Wordsize;
int count_strlen(char *buffer);
void readfile(Words **words,int argc,char **argv);
void playgame(Words *words);
char getChar(void);
char *hint(Words ans,char *input);
