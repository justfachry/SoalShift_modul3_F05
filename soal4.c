#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>


void *thread1(void *arg)
{
    char command[150];
   
    strcpy(command, "ps aux | head -n 11 > Proses1.txt");
    system(command);

    strcpy(command, "mv Proses1.txt Documents/Proses1/");
    system(command);

    strcpy(command, "zip KompresProses1.zip Documents/Proses1/Proses1.txt && mv KompresProses1.zip Documents/Proses1/ && rm Documents/Proses1/Proses1.txt");
    system(command);

    
    return NULL;
}

void *thread2(void *arg)
{
    char command1[150];
   
    strcpy(command1, "ps aux | head -n 11 > Proses2.txt");
    system(command1);

    strcpy(command1, "mv Proses2.txt Documents/Proses2/");
    system(command1);

    strcpy(command1, "zip KompresProses2.zip Documents/Proses2/Proses2.txt && mv KompresProses2.zip Documents/Proses2/ && rm Documents/Proses2/Proses2.txt");
    system(command1);

    return NULL;
}

void *thread3(void *arg)
{
    char command2[150];
   
    strcpy(command2, "unzip Documents/Proses1/KompresProses1.zip && unzip Documents/Proses2/KompresProses2.zip");
    system(command2);

    return NULL;
}

int main()
{

    pthread_t tid[3];

    pthread_create(&tid[0], NULL, thread1, NULL);
    pthread_create(&tid[1], NULL, thread2, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    puts("Menunggu 15 detik untuk mengekstrak kembali");
    sleep(15);
    
    pthread_create(&tid[2], NULL, thread3, NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[2], NULL);

    pthread_exit(NULL);
    return 0;
}
