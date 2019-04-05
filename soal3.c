#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

pthread_t iraj;
pthread_t agmal;
pthread_t allstatus;

int WakeUp_Status=0;
int Spirit_Status=100;
int y,z;
int input=0;
int cek=0;
int flag=1;
void* wakeup(void* args){
    while(1){
        if(WakeUp_Status>=100){
            flag=0;
            printf("WakeUp_Status = %d\tIter = %d\nSpirit_Status = %d\titer = %d\n", WakeUp_Status, y, Spirit_Status, z);
            printf("Agmal terbangun, mereka bangun pagi dan berolahraga\n");
            exit(0);
        }  
        else if(input==1){
             input=0;
            if(z==3){
                // printf("\n");
                z=0;
                sleep(10);
            }
            else{
            puts("Agmal Ayo Bangun");
            WakeUp_Status = WakeUp_Status+15;
            if(y<3) y++;
            if(y==3) input=2;
            cek=1;
            }
        }
        
    }
}

void *spirit(void* args){
    while(1){
        if(Spirit_Status<=0){
             flag=0;
            printf("WakeUp_Status = %d\tIter = %d\nSpirit_Status = %d\titer = %d\n", WakeUp_Status, y, Spirit_Status, z);
            printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal\n");
            exit(0);
            
        }
        else if(input==2){
            input=0;
            if(y==3){
                // printf("\n");
                y=0;
                sleep(10);
            }
            else{
            puts("Iraj Ayo Tidur");
            Spirit_Status = Spirit_Status-20;
            if((z<3)z++;
            if(z==3) input=1;
            cek=1;
            }
        }
       
    }
}

void *status(void* args){
    while(flag==1){
        if(cek==1){
        printf("WakeUp_Status = %d\tIter = %d\nSpirit_Status = %d\titer = %d\n", WakeUp_Status, y, Spirit_Status, z);
        cek=0;
        }
    }
}

int main()
{
   int n;

    printf("1. Agmal Ayo Bangun\n2. Iraj Ayo Tidur\n");
    pthread_create(&iraj, NULL, spirit, NULL);
    pthread_create(&agmal, NULL, wakeup, NULL);
    pthread_create(&allstatus, NULL, status, NULL);
    while(flag==1)
    {
        scanf("%d", &n);
        if(n==1 || n==2){
            input=n;
        }
    }
    
   
    return 0;
}