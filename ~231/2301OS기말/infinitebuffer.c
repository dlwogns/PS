#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define ITER 1000
void *thread_increment(void *arg);
void *thread_decrement(void *arg);
int x;
sem_t s, f; // s, fill


int main() {
    pthread_t tid1, tid2;

    sem_init(&s, 0, 1); //s는 1로 초기화.
    sem_init(&f, 0, 0); // 처음에 버퍼는 비어있기 때문에 0으로 초기화 해준다.

    pthread_create(&tid1, NULL, thread_increment, NULL);
    pthread_create(&tid2, NULL, thread_decrement, NULL);
    pthread_join(tid1, NULL); pthread_join(tid2, NULL);
    
    if (x != 0)
        printf("BOOM! counter=%d\n", x);
    else
        printf("OKcounter=%d\n", x);
    
    sem_destroy(&s);
    sem_destroy(&f);
    return 0;
}


/* thread routine */
void * thread_increment (void *arg) {
    int i, val;
    
    for (i=0; i< ITER ; i++) {
        sem_wait(&s);
        val = x;
        printf("%u: %d\n", (unsigned int) pthread_self(), val);
        x = val + 1;
        sem_post(&s);
        sem_post(&f);// increment가 된다면 버퍼에 자원이 들어간다는 가정이기 때문에 post 해준다.
    }
    pthread_exit(NULL);
    return NULL;
}
void * thread_decrement (void *arg) { int i, val;
    
    for (i=0; i< ITER ; i++) {
        sem_wait(&f); //만약 f가 0이라면 기다린다.
        sem_wait(&s);
        val = x;
        printf("%u: %d\n", (unsigned int) pthread_self(), val);
        x = val - 1;
        sem_post(&s);
    }
    pthread_exit(NULL);
    return NULL;
}