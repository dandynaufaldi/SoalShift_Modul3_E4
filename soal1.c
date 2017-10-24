#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char senjata[6][8] = {"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SPG1-V3", "MINE"};

void penjual(int *weapon)
{
    int modej;
    int amountj;
    char senjataj[8];
    for(int i=0;i<6;i++)
    {
	weapon[i] = 0;
    }
    while(1)
    {
	printf("Pilih Aksi:\n1. tambah stock senjata\n2. lihat stock senjata\n");
	scanf("%d",&modej);
	if(modej==1)
	{
	    scanf("%s %d",senjataj, &amountj);
	    if(!(strcmp(senjataj, senjata[0])))
	    {
		weapon[0] += amountj;
	    }
	    else if(!(strcmp(senjataj, senjata[1])))
	    {
		weapon[1] += amountj;
	    }
	    else if(!(strcmp(senjataj, senjata[2])))
	    {
		weapon[2] += amountj;
	    }
	    else if(!(strcmp(senjataj, senjata[3])))
	    {
		weapon[3] += amountj;
	    }
	    else if(!(strcmp(senjataj, senjata[4])))
	    {
		weapon[4] += amountj;
	    }
	    else if(!(strcmp(senjataj, senjata[5])))
	    {
		weapon[5] += amountj;
	    }
	}
	else if(modej==2)
	{
	    for(int i=0;i<6;i++)
	    {
		if(weapon[i] > 0)
		{
		    printf("%s %d\n",senjata[i], weapon[i]);
		}
	    }

	}
	else
	{
	    printf("Silahkan Coba Lagi\n");
	}
    }
}
void pembeli(int *weapon)
{
    int amountb;
    char senjatab[8];
    int modeb;
    while(1)
    {
	printf("Pilih Aksi:\n1. beli senjata\n2. lihat stock senjata\n");
	scanf("%d",&modeb);
	if(modeb==1)
	{
	    scanf("%s %d",senjatab, &amountb);
	    if(!(strcmp(senjatab, senjata[0])))
	    {
		if(amountb <= weapon[0])
		weapon[0] -= amountb;
		else
		printf("barang di stock tidak cukup\n");
	    }
	    else if(!(strcmp(senjatab, senjata[1])))
	    {
		if(amountb <= weapon[1])
		weapon[1] -= amountb;
		else
		printf("barang di stock tidak cukup\n");
	    }
	    else if(!(strcmp(senjatab, senjata[2])))
	    {
		if(amountb <= weapon[2])
		weapon[2] -= amountb;
		else
		printf("barang di stock tidak cukup\n");
	    }
	    else if(!(strcmp(senjatab, senjata[3])))
	    {
		if(amountb <= weapon[3])
		weapon[3] -= amountb;
		else
		printf("barang di stock tidak cukup\n");
	    }
	    else if(!(strcmp(senjatab, senjata[4])))
	    {
		if(amountb <= weapon[4])
		weapon[4] -= amountb;
		else
		printf("barang di stock tidak cukup\n");
	    }
	    else if(!(strcmp(senjatab, senjata[5])))
	    {
		if(amountb <= weapon[5])
		weapon[5] -= amountb;
		else
		printf("barang di stock tidak cukup\n");
	    }
	}
	else if(modeb==2)
	{
	    for(int i=0;i<6;i++)
	    {
		printf("%s %d\n",senjata[i], weapon[i]);
	    }
	}
	else
	{
	    printf("Silahkan Coba Lagi\n");
	}
    }
}

int main()
{
    int shmid;
    int* weapon;
    key_t key = 12345;

    shmid = shmget(key,6*(sizeof(int)),IPC_CREAT | 0666);
    weapon = (int*)shmat(shmid,NULL,0);
    char senjatab[8];
    int mode=0;
    while(!mode)
    {
	printf("Pilih Mode Akses:\n1. Penjual\n2. Pembeli\n");
	scanf("%d",&mode);
	if(mode<1 || mode >2)
	{
	    printf("Silahkan Coba Lagi\n");
	    mode=0;
	}
    }
    if(mode == 1)
    {
	penjual(weapon);
    }
    else if(mode == 2)
    {
	pembeli(weapon);
    }
    return 0;
    
    
}


