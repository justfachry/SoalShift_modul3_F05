#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int arr[100];
void* sort(void *input)
{
    intptr_t n= (intptr_t)input;
    int i;
    int j;
    for(i=1; i<n; i++){
        for(j=i; j>0; j--){
            if(arr[j-1]>arr[j]){
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}

void* faktorial(void *args){
    intptr_t n = (intptr_t)args;
    int num=n;
    if(n<0) printf("%d! = undefined\n", num);
    else{
        unsigned long long sum=1;
        while(n>0){
            sum=sum*n;
            n--;
        }
        printf("%d! = %llu\n", num, sum);
    }
}
int main(int argc, char *argv[])
{
    pthread_t thread;
    pthread_t tid[argc-1];
    int i=1;
    int j=0;
    while(i<argc){
        int n;
        n = atoi(argv[i]);
        arr[j]=n;
        i++;
        j++;
    }
    intptr_t tes = argc-1;
    pthread_create(&thread, NULL, &sort, (void*)tes);
    pthread_join(thread, NULL);

    int t = 0;
    while(t<argc-1){
        intptr_t num = arr[t];
        pthread_create(&(tid[t]), NULL, &faktorial,(void *) num);
        pthread_join(tid[t], NULL);
        t++;
    }
   return 0; 
} 