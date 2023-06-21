#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t wsem , x, z, rsem, y;
int readercount = 0, writecount = 0;

void* writer(void *arg){
    while(1){
        sem_wait(&y);
        writecount++;
        // reader preference와 비슷하게 writer가 1이된다면
        // rsem을 wait해 reader가 못들어오게 한다.
        if(writecount == 1) 
            sem_wait(&rsem);
        sem_post(&y);

        sem_wait(&wsem);
        //write unit
        printf("%s\n", "Write unit executed!");
        sem_post(&wsem);

        sem_wait(&y);
        writecount--;
        if(writecount == 0) sem_post(&rsem);
        sem_post(&y);
    }
}

void* reader(void *arg){
    while(1){
        sem_wait(&z);
        sem_wait(&rsem);
        sem_wait(&x);
        readercount++;
        if(readercount == 1) sem_wait(&wsem);
        sem_post(&x);
        sem_post(&rsem);
        sem_post(&z);

        //read unit
        printf("%s\n", "Read unit executed!");

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
    sem_init(&z, 0, 1);
    sem_init(&y, 0, 1);
    sem_init(&rsem, 0, 1); //reader

    pthread_create(&tid1, NULL, reader, NULL);
    pthread_create(&tid2, NULL, writer, NULL);
    pthread_join(tid1, NULL); pthread_join(tid2, NULL);

    sem_destroy(&wsem);
    sem_destroy(&x);
    sem_destroy(&z);
    sem_destroy(&y);
    sem_destroy(&rsem);

    printf("%s", "Success");

    return 0;


    
}