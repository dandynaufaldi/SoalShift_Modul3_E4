#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
pthread_t lohant;
pthread_t kepitingt;
pthread_t controller;
int lohan=100;
int kepiting=100;
int ready=0;

void* lohancountdown(void *arg)
{
    ready++;
    while(ready<3);
    while(1)
    {
	sleep(10);
	lohan-=15;
    }
}
void* kepitingcountdown(void *arg)
{
    ready++;
    while(ready<3);
    while(1)
    {
	sleep(20);
	kepiting-=10;
    }
}
void* control(void *arg)
{
    int action;
    ready++;
    while(ready<3);
    while(1)
    {
		if((kepiting<=0 || kepiting > 100) || (lohan <=0 || lohan > 100))
		{
			pthread_cancel(kepitingt);
		    pthread_cancel(lohant);
		    if(kepiting<=0)
		    {
			printf("Game Berakhir: Kepiting Mati Kelaparan\n");
		    }
		    if(kepiting>100)
		    {
			printf("Game Berakhir: Kepiting Mati Kekenyangan\n");
		    }
		    if(lohan<=0)
		    {
			printf("Game Berakhir: Lohan Mati Kelaparan\n");
		    }
		    if(lohan>100)
		    {
			printf("Game Berakhir: Lohan Mati Kekenyangan\n");
		    }
		    break;
		}
		printf("Pilih Aksi:\n1. beri makan lohan\n2. beri makan kepiting\n");
		scanf("%d", &action);
		if(action==1)
		{
		    lohan+=10;
		}
		else if(action==2)
		{
		    kepiting+=10;
		}
		else
		{
		    printf("Aksi tidak dikenali. Silahkan Coba Lagi\n");
		}
    }
}
int main(void)
{
    int err;
    err=pthread_create(&lohant,NULL,&lohancountdown,NULL);
    if(err!=0)
    {
        printf("\n can't create thread lohant : [%s]",strerror(err));
    }
    err=pthread_create(&kepitingt,NULL,&kepitingcountdown,NULL);
    if(err!=0)
    {
        printf("\n can't create thread kepitingt : [%s]",strerror(err));
    }
    err=pthread_create(&controller,NULL,&control,NULL);
    if(err!=0)
    {
        printf("\n can't create thread controller : [%s]",strerror(err));
    }
    pthread_join(lohant,NULL);
    pthread_join(kepitingt,NULL);
    pthread_join(controller,NULL);
    return 0;
}
