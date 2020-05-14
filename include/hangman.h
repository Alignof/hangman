#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<termio.h>

typedef struct{
	int len;
	int number;
	char *str;
}Words;

char getChar(void);
void readfile(Words *buffer);
int count_strlen(char **buffer);
