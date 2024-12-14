#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Глобальные переменные
int k, pnum, mod;
long long result = 1;
pthread_mutex_t mutex;

void* fact_thr(void* arg) {
    int thread_id = *(int*)arg;
    long long buf_res = 1;

    for (int i = thread_id + 1; i <= k; i += pnum) {
        buf_res = (buf_res * i) % mod;
    }

    pthread_mutex_lock(&mutex);
    result = (result * buf_res) % mod;
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char* argv[]) {
    int opt;

    // Инициализация переменных
    k = -1;
    pnum = -1;
    mod = -1;

    // Парсинг аргументов командной строки с использованием getopt
    while ((opt = getopt(argc, argv, "k:p:m:")) != -1) {
        switch (opt) {
            case 'k':
                k = atoi(optarg);
                break;
            case 'p':
                pnum = atoi(optarg);
                break;
            case 'm':
                mod = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Использование: %s -k <число> -p <потоки> -m <модуль>\n", argv[0]);
                return 1;
        }
    }

    if (k <= 0 || pnum <= 0 || mod <= 0) {
        fprintf(stderr, "Использование: %s -k <число> -p <потоки> -m <модуль>\n", argv[0]);
        return 1;
    }

    pthread_mutex_init(&mutex, NULL);

    pthread_t threads[pnum];
    int thread_ids[pnum];

    for (int i = 0; i < pnum; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, fact_thr, &thread_ids[i]);
    }

    for (int i = 0; i < pnum; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Факториал %d по модулю %d: %lld\n", k, mod, result);

    return 0;
}