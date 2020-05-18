#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<termio.h>

typedef struct{
	int len;
	char *str;
	bool is_wrong;
	bool is_collect;
	bool is_answered;
}Words;

char getChar(void);
void readfile(Words *words,int argc,char **argv);
int count_strlen(char *buffer);
