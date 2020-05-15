#include "hangman.h"
#define WORD_SIZE 1000

int main(int argc,char *argv[]){
	Words *buffer;

	readfile(buffer,argc,argv);
	return 0;
}
