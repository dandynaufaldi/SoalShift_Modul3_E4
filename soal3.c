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
int gamestatus=1;
int ready=0;

void* lohancountdown(void *arg)
{
    
}
void* kepitingcountdown(void *arg)
{

}
void* control(void *arg)
{

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
