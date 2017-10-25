#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

typedef struct{
	char name[50];
	int poin;
	int lubang[17];
	int count;
	int statemain;
}player;

void init(player *pemain){
	pemain->poin = 0;
	memset(pemain->lubang, 0, sizeof(pemain->lubang));
	pemain->count = 0;
}

player A,B;
pthread_t p1, p2, ctrl;

int turn=0;
int run = 0;

void* player1(void* arg){
	A.statemain = 1;
	run++;
	while(run<3);
	while(1){
		while(turn){

		}
		//printf("\n\nA %d\n", turn);
		printf("Player %s turn ", A.name);
		if (A.statemain){
			printf("to place bomb\n");
			if(A.count == 16)
			{
				printf("No holes remaining\n");
				B.statemain ^=1;
			}
			else
			{
				printf("Holes remaining : %d",16-A.count);
				printf("Input amount of bomb =");
				int x; scanf("%d", &x);
				int i, n;
				printf("Input %d holes' number [1-16]:", x);
				for(i=0;i<x;i++){
					scanf("%d", &n);
					if(A.lubang[n])
					{
						printf("Hole %d has been filled. Choose another hole\n",n);
						i--;
					}
					else
					{
						A.lubang[n] = 1;
						A.count++;
					}
						
				}
			}
			
			sleep(1);
			system("clear");
			turn=1;
		}
		else{
			printf("to guess 4 lucky holes\n");
			printf("Input your guess [1-16] : ");
			int i, n;
			for(i=0;i<4;i++){
				scanf("%d", &n);
				if (B.lubang[n]){
					printf("Hole %d got MINE\n", n);
					B.poin++;
				}
				else A.poin++;
			}
		}
		A.statemain^=1;
		
	}
}

void* player2(void* arg){
	B.statemain = 0;
	run++;
	while(run<3);
	while(1){
		while(!turn){

		}
		//printf("\n\nB %d\n", turn);
		printf("Player %s turn ", B.name);
		if (B.statemain){
			printf("to place bomb\n");
			if(B.count == 16)
			{
				printf("No holes remaining\n");
				A.statemain ^=1;
			}
			else
			{
				printf("Holes remaining : %d",16-B.count);
				printf("Input amount of bomb =");
				int x; scanf("%d", &x);
				int i, n;
				printf("Input %d holes' number [1-16]:", x);
				for(i=0;i<x;i++){
					scanf("%d", &n);
					if(B.lubang[n])
					{
						printf("Hole %d has been filled. Choose another hole\n",n);
						i--;
					}
					else
					{
						B.lubang[n] = 1;
						B.count++;
					}
					
				}
			}
			sleep(1);
			system("clear");
			turn=0;
		}
		else{
			printf("to guess 4 lucky holes\n");
			printf("Input your guess [1-16] : ");
			int i, n;
			for(i=0;i<4;i++){
				scanf("%d", &n);
				if (A.lubang[n]){
					printf("Hole %d got MINE\n", n);
					A.poin++;
				}
				else B.poin++;
			}
		}
		B.statemain^=1;
	}
}

void* control(void* arg){
	run++;
	while(run<3);
	while(1){
		if (A.poin>=10){
			printf("Player %s win\n", A.name);
			exit(0);
		}
		else if (B.poin>=10){
			printf("Player %s win\n", B.name);
			exit(0);
		}
		else if (A.count==16 && B.count==16){
			if (A.poin > B.poin) printf("Player %s win\n", A.name);
			else if (A.poin < B.poin) printf("Player %s win\n", B.name);
			else printf("Draw\n");
			exit(0);
		}
	}
}

int main(int argc, char const *argv[])
{
	init(&A);
	init(&B);
	printf("Input player1 name >");
	scanf(" %s",A.name);
	printf("Input player2 name >");
	scanf(" %s",B.name);
	

	int err;
	err = pthread_create(&p1, NULL, player1, NULL);
	if (err) printf("Can not create thread for player %s\n", A.name);
	err = pthread_create(&p2, NULL, player2, NULL);
	if (err) printf("Can not create thread for player %s\n", B.name);
	err = pthread_create(&ctrl, NULL, control, NULL);
	if (err) printf("Can not create thread for game control\n");
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(ctrl, NULL);
	return 0;
}