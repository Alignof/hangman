#include "hangman.h"
#define TRY 7

char *hint(Words ans,char *input){
	int i,j;
	char *ret;
	ret=(char *)malloc(ans.len*sizeof(char));

	for(i=0;i<ans.len;i++){
		for(;*input!=NULL;input++){
			if(ans.str[i]==*input){
				ret[i]=*input;
			}else{
				ret[i]='-';
			}
		}
	}
	return ret;
}

void playgame(Words *words){
	int i;
	Words word;
	bool game_continue=true;
	char input[TRY]={0};

	srand((unsigned int)time(NULL));

	while(game_continue){
		word=words[rand()%Wordsize];
		if(word.is_collect) continue;
/*
		for(i=0;i<TRY;i++){
			printf("input char>");
			input[i]=getChar();
			printf("word:%s",hint(word,input));
			printf("used:%s",input);
			printf("remain:%d",TRY-i);
		}
*/

		printf("continue?[y/n]>");
		if(getchar()=='n') game_continue=false;
		getchar();//dummy input
	}
}
