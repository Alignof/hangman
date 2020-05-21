#include "hangman.h"
#define TRY 7

char *hint(Words *ans,char *input){
	int i,j;
	int counter=0;
	char *ret;
	ret=(char *)malloc((ans->len+1)*sizeof(char));

	for(i=0;i<ans->len;i++){
		ret[i]='-';
		for(j=0;input[j]!=NULL;j++){
			if(ans->str[i]==input[j]){
				ret[i]=input[j];
				counter++;
				break;
			}
		}
	}

	if(counter==ans->len) ans->is_correct=true;
	ret[ans->len]='\0';
	return ret;
}

void playgame(Words *words){
	int i;
	Words word;
	bool game_continue=true;
	bool used['z'-'a']={0};
	char input[TRY]={0};

	srand((unsigned int)time(NULL));

	while(game_continue){
		word=words[rand()%Wordsize];
		if(word.is_correct) continue;

		for(i=0;i<TRY+1;i++){
			printf("\033[1;1H");
			printf("\033[2J");
			//printf("\033c");

			printf("word:%s\n",word.str);
			printf("hint:%s\n",hint(&word,input));
			printf("used:%s\n",input);
			printf("remain:%d\n",TRY-i);

			if(word.is_correct) break;

			if(i!=TRY){
				printf("input char>");
				input[i]=getChar();
				used[input[i]]=true;
			}
		}

		if(word.is_correct){
			printf("correct!\n");
		}else{
			printf("wrong...\n");
			word.is_wrong=true;
		}
		word.is_answered=true;


		printf("\ncontinue?[y/n]>");
		if(getChar()=='n') game_continue=false;

		memset(input,0,sizeof(input));
		memset(used,0,sizeof(used));
	}
}
