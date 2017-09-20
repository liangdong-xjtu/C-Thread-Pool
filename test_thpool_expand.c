#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "thpool.h"

int max_print = 0;

void* print(void* argp) {
    int num = *((int*)argp);
    if ( max_print < num )
        max_print = num;
    int i=0;
    while(i<1) {
        printf("%d.", num);
        usleep(500*1000);
        fflush(stdout);
        i++;
    }
}

int main(int argc, char *argv[]) {

    char* p;
    if (argc != 3){
        puts("This testfile needs excactly two arguments");
        exit(1);
    }
    int num_jobs    = strtol(argv[1], &p, 10);
    int num_threads = strtol(argv[2], &p, 10);
    int np[num_jobs];

    threadpool thpool = thpool_init(num_threads);

    int n;
    for (n=0; n<num_jobs; n++){
        np[n] = n;
        thpool_add_work(thpool, (void*)print, (void*)(&np[n]));
        //thpool_scale(thpool, num_threads);
    }
    thpool_wait(thpool);
    printf("\nDone: max_print = %d\n", max_print);
    thpool_destroy(thpool);
    sleep(1);

    return 0;
}
