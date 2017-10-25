#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

typedef struct{
	char name[50];
	int poin;
	int lubang[17];
	int statemain;
}player;

void init(player *pemain){
	pemain->poin = 0;
	memset(pemain->lubang, 0, sizeof(pemain->lubang));
}

int main(int argc, char const *argv[])
{
	
	return 0;
}