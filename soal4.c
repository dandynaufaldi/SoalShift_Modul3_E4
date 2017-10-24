#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<string.h>
#include<unistd.h>

typedef long double LD;
int key = 0;
pthread_mutex_t lock;
void* fact(void *arg){
	pthread_mutex_lock(&lock);
	int *N = arg;
	int i;
	LD res = 1.0;
	for (i=1;i<=*N;i++) res = res*(LD)i;
	printf("Hasil %d! = %.0Lf\n", *N, res);
	pthread_mutex_unlock(&lock);
}

int main(int argc, char const *argv[])
{
	int j;
	pthread_mutex_init(&lock, NULL);
	pthread_t thr[argc+1];
	int inp[argc+1];
	for(j=1;j<argc;j++){
		inp[j] = atoi(argv[j]);
		pthread_create(&thr[j], NULL, fact, (void*)&inp[j]);
	}
	for(j=1;j<argc;j++){
		pthread_join(thr[j], NULL);
	}
	return 0;
}