#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define ITER 1000
#define MAX 50
void *thread_increment(void *arg);
void *thread_decrement(void *arg);
int x;
sem_t s, e, f; //이전 코드에서 e를 추가하였다.
// 상단에 서술한 empty를 나타내는 semaphore이다.


int main() {
    pthread_t tid1, tid2;

    sem_init(&s, 0, 1);
    sem_init(&e, 0, MAX);
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
        sem_wait(&e); //producer에서는 e를 1 줄여준다. 만약 버퍼가 가득 차있으면, 기다린다.
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
        sem_post(&e); // consumer에서는 e를 1 늘려 버퍼가 한칸 더 비었다는 것을 말한다.
    }
    pthread_exit(NULL);
    return NULL;
}