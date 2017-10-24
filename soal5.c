#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
int key = 0;
void* findName(void* arg){
	while(key!=0){

	}
	key = 1;
	char command[100];
	char *name = arg;
	sprintf(command, "echo \"%s : \" `grep -c %s Novel.txt`", name, name);
	system(command);
	key = 0;
}

int main(int argc, char const *argv[])
{
	int i;
	pthread_t thr[argc+1];
	for(i=1;i<argc;i++){
		pthread_create(&thr[i], NULL, findName, (void*)argv[i]);
	}
	for(i=1;i<argc;i++){
		pthread_join(thr[i], NULL);
	}
	return 0;
}