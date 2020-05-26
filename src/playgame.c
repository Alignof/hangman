#include "hangman.h"
#define TRY 7

bool hint(Words *word,bool *used,char input){
	int i;
	bool hit=false;
	int counter=0;
	char output;

	printf("hint:");
	for(i=0;i<word->len;i++){
		output='-';
		if(used[word->str[i]-'a']){
			output=word->str[i];
			if(word->str[i]==input) hit=true;
			counter++;
		}
		printf("%c",output);
	}
	printf("\n");

	if(counter==word->len) word->is_correct=true;
	return hit;
}

void display_used(char *used){
	char c;

	printf("================================\nused:");
	for(c='a';c<='z';c++){
		if(used[c-'a']){
			printf("\033[41m");
			printf("%c",c);
			printf("\033[49m");
		}else{
			printf("%c",c);
		}
	}
	printf("\n================================\n");

}

int display_data(Words *word,bool *used,char input,int *remain){
	int hit;

	printf("\033[1;1H");
	printf("\033[2J");
	printf("word:%s\n",word->str);
	hit=hint(word,used,input);
	display_used(used);

	if(hit==0 && input!=NULL) (*remain)--;
	printf("remain:%d\n",*remain);

	return hit;
}

void playgame(Words *words){
	int i;
	int remain;
	bool hit;
	char input=0;
	Words word;
	bool game_continue=true;
	bool used['z'-'a'+1]={0};

	srand((unsigned int)time(NULL));

	while(game_continue){
		word=words[rand()%Wordsize];
		if(word.is_correct) continue;

		remain=TRY;
		input=NULL;

		// initial
		display_data(&word,used,input,&remain);
		while(remain>0){
			printf("input char>");
			do{
				input=getChar();
			}while(!('a'<=input && input<='z') || used[input-'a']);

			used[input-'a']=true;
			display_data(&word,used,input,&remain);

			if(word.is_correct) break;
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

		memset(used,0,sizeof(used));
	}
}
