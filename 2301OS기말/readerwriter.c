#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define ITER 100
void *thread_increment(void *arg);
void *thread_decrement(void *arg);
int x;
sem_t s, e, f;


int main() {
    pthread_t tid1, tid2;

    sem_init(&s, 0, 1);
    sem_init(&e, 0, ITER);
    sem_init(&f, 0, 0);

    pthread_create(&tid1, NULL, thread_increment, NULL);
    pthread_create(&tid2, NULL, thread_decrement, NULL);
    pthread_join(tid1, NULL); pthread_join(tid2, NULL);
    
    if (x != 0)
        printf("BOOM! counter=%d\n", x);
    else
        printf("OKcounter=%d\n", x);
    
    sem_destroy(&s);
    sem_destroy(&e);
    sem_destroy(&f);
    return 0;
}


/* thread routine */
void * thread_increment (void *arg) {
    int i, val;
    
    for (i=0; i< ITER ; i++) {
        sem_wait(&e);
        sem_wait(&s);
        val = x;
        printf("%u: %d\n", (unsigned int) pthread_self(), val);
        x = val + 1;
        sem_post(&s);
        sem_post(&f);
    }
    pthread_exit(NULL);
    return NULL;
}
void * thread_decrement (void *arg) { int i, val;
    
    for (i=0; i< ITER ; i++) {
        sem_wait(&f);
        sem_wait(&s);
        val = x;
        printf("%u: %d\n", (unsigned int) pthread_self(), val);
        x = val - 1;
        sem_post(&s);
        sem_post(&e);
    }
    pthread_exit(NULL);
    return NULL;
}