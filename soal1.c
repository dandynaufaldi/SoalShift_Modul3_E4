#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>

key_t = 1234;
long long int **weapon;
int shmid = shmget(key, 6*sizeof(int*), IPC_CREAT | 0666);
weapon = shmat(shmid, NULL, 0);

void penjual()
{
    for(int i=0;i<6;i++)
    {
	*weapon[i] = 0;
    }
    
}
void pembeli()
{
}

int main()
{
    
    int mode=0;
    while(!mode)
    {
	printf("Pilih Mode Akses:\n1. Penjual\n2. Pembeli\n")
	scanf("%d",mode);
	if(mode<1 || mode >2)
	{
	    printf("Silahkan Coba Lagi\n");
	    mode=0;
	}
    }
    if(mode == 1)
    {
	penjual();
    }
    else if(mode == 2)
    {
	pembeli();
    }
    return 0;
    
    
}


