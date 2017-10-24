#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<string.h>
#include<unistd.h>

typedef long double LD;
void fact(void *arg){
	int *N = arg;
	int i;
	LD res = 1.0;
	for (i=1;i<=*N;i++) res = res*(LD)i;
	printf("Hasil %d! = %.0Lf\n", *N, res);

}
int main(int argc, char const *argv[])
{
	while(argv[i]){
		
		i++;
	}
	return 0;
}