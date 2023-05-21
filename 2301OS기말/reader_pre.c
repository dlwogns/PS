#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define ITER 1000

sem_t wsem , x;
int readercount = 0;

void* writer(void *arg){
    for(int i=0; i<ITER; i++){
        sem_wait(&wsem);
        //write unit
        printf("%s\n", "Write unit executed!");
        printf("%s : %d\n", "readercount : ", readercount);
        sem_post(&wsem);
    }
}

void* reader(void *arg){
    for(int i=0; i<ITER; i++){
        sem_wait(&x);
        readercount++;
        if(readercount == 1) sem_wait(&wsem);
        sem_post(&x);

        //read unit
        printf("%s", "Read unit executed!\n");

        sem_wait(&x);
        readercount--;
        if(readercount == 0) sem_post(&wsem);
        sem_post(&x);
    }


}

int main(){
    pthread_t tid1, tid2;

    sem_init(&wsem, 0, 1); //writer
    sem_init(&x, 0, 1); // reader atomic을 위한 semaphore

    pthread_create(&tid1, NULL, reader, NULL);
    pthread_create(&tid2, NULL, writer, NULL);
    pthread_join(tid1, NULL); pthread_join(tid2, NULL);

    sem_destroy(&wsem);
    sem_destroy(&x);

    printf("%s", "Success");

    return 0;


    
}