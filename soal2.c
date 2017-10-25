#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

typedef struct{
	char name[50];
	int poin;
	int lubang[17];
	int cnt;
	int statemain;
}player;

void init(player *pemain){
	pemain->poin = 0;
	memset(pemain->lubang, 0, sizeof(pemain->lubang));
	pemain->cnt = 0;
}

player A,B;
pthread_t p1, p2;
init(&A);
init(&B);
int turn=0;
void* player1(void* arg){
	A.statemain = 0;
	while(1){
		while(turn&1){

		}
		printf("Player %s turn ", A.name);
		if (A.statemain){
			printf("to place bomb\n");
			printf("Input amount of bomb =");
			int x; scanf("%d", &x);
			int i, n;
			printf("Input %d holes' number [1-16]:", x);
			for(i=0;i<x;i++){
				scanf("%d", &n);
				A.lubang[n] = 1;
				A.cnt++;
			}
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
		turn++;	
	}
}

void* player2(void* arg){
	B.statemain = 1;
	while(1){
		while(!(turn&1)){

		}
		printf("Player %s turn ", B.name);
		if (B.statemain){
			printf("to place bomb\n");
			printf("Input amount of bomb =");
			int x; scanf("%d", &x);
			int i, n;
			printf("Input %d holes' number [1-16]:", x);
			for(i=0;i<x;i++){
				scanf("%d", &n);
				B.lubang[n] = 1;
				B.cnt++;
			}
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
		turn++;	
	}
}

int main(int argc, char const *argv[])
{
	printf("Input player1 name >");
	scanf(" %s",A.name);
	printf("Input player2 name >");
	scanf(" %s",B.name);
	

	int err;
	err = pthread_create(&p1, NULL, player1, NULL);
	if (!err) printf("Can not create thread for player %s\n", A.name);
	err = pthread_create(&p2, NULL, player2, NULL);
	if (!err) printf("Can not create thread for player %s\n", B.name);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	
	return 0;
}