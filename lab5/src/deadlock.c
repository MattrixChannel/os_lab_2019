#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Объявление двух мьютексов
pthread_mutex_t mut1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;

void* thr1_fun(void* arg) {
    pthread_mutex_lock(&mut1);
    printf("Thread 1 blocking mut1\n");

    sleep(2);

    printf("Thread 1 blocking mut2\n");
    pthread_mutex_lock(&mut2);
    printf("Thread 1 blocking mut2 - done\n");

    pthread_mutex_unlock(&mut2);
    pthread_mutex_unlock(&mut1);
}

// Функция, которую будет выполнять второй поток
void* thr2_fun(void* arg) {
    pthread_mutex_lock(&mut2);
    printf("Thread 2 blocking mut2\n");

    sleep(2);

    printf("Thread 2 blocking mut1\n");
    pthread_mutex_lock(&mut1);
    printf("Thread 2 blocking mut1 - success\n");

    pthread_mutex_unlock(&mut1);
    pthread_mutex_unlock(&mut2);
}

void* thr1_funv2(void* arg) {
    pthread_mutex_lock(&mut1);
    printf("Thread 1 locking mut1\n");

    sleep(3);

    pthread_mutex_unlock(&mut1);
    printf("Thread 1 unlocking mut1\n");
}

void* thr2_funv2(void* arg) {
    sleep(1);

    printf("Thread 2 locking mut1\n");
    pthread_mutex_lock(&mut1);
    printf("Thread 2 blocking mut1 - success\n");

    pthread_mutex_unlock(&mut1);
}

int main() {
    pthread_t thr1, thr2;

    pthread_create(&thr1, NULL, thr1_fun, NULL);
    pthread_create(&thr2, NULL, thr2_fun, NULL);

    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);

    printf("End\n");

    return 0;
}