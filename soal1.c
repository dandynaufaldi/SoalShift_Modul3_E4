#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>

key_t = 1234;
long long int **weapon;
int shmid = shmget(key, 6*sizeof(long long int*), IPC_CREAT | 0666);
weapon = shmat(shmid, NULL, 0);
char senjata[6][8];
senjata[0] = "MP4A1";
senjata[1] = "PM2-V1";
senjata[2] = "SPR-3";
senjata[3] = "SS2-V5";
senjata[4] = "SPG1-V3";
senjata[5] = "MINE";

void penjual()
{
    int modej;
    long long int amountj;
    char senjataj[8];
    for(int i=0;i<6;i++)
    {
	*weapon[i] = 0;
    }
    while(1)
    {
	printf("Pilih Aksi:\n1. Tambah stock senjata\n2. Lihat stock senjata");
	scanf("%d",&modej);
	if(modej==1)
	{
	    scanf("%s %d",senjataj, amountj);
	    if(strcmp(senjataj, senjata[0])
	    {
		*weapon[0] += amountj;
	    }
	    else if(strcmp(senjataj, senjata[1])
	    {
		*weapon[1] += amountj;
	    }
	    else if(strcmp(senjataj, senjata[2])
	    {
		*weapon[2] += amountj;
	    }
	    else if(strcmp(senjataj, senjata[3])
	    {
		*weapon[3] += amountj;
	    }
	    else if(strcmp(senjataj, senjata[4])
	    {
		*weapon[4] += amountj;
	    }
	    else if(strcmp(senjataj, senjata[5])
	    {
		*weapon[5] += amountj;
	    }
	}
	else if(modej==2)
	{
	    for(int i=0;i<6;i++)
	    {
		if(*weapon[i] > 0)
		{
		    printf("%s %lld",senjata[i], *weapon[i]);
		}
	    }
	}
	else
	{
	    printf("Silahkan Coba Lagi\n);
	}
    }
}
void pembeli()
{
    int modeb;
    while(1)
    {
    }
}

int main()
{
    char senjatab[8];
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


