#include "hangman.h"

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

void display_remain(int remain){
	int i;

	printf("\033[43m");
	for(i=0;i<remain;i++){
		printf("  ");
	}
	printf("\033[49m");
	printf("\n");
}

int display_data(Words *word,bool *used,char input,int *remain){
	int hit;

	printf("\033[1;1H");
	printf("\033[2J");
	printf("word:%s\n",word->str);
	hit=hint(word,used,input);
	display_used(used);

	if(hit==0 && input!=NULL) (*remain)--;
	printf("remain[%d]:",*remain);
	//display_remain(*remain);

	return hit;
}

void display_result(Words *words){
	int i;

	// display wrong word
	printf("\n------wrong words------\n");
	for(i=0;i<Wordsize;i++){
		if(words[i].is_wrong)
			printf("%s\n",words[i].str);
	}
	printf("-----------------------\n");
}
