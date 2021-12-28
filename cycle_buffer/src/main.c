#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "cycle_buffer.h"

void write_data_runner(pCycleBuffer pcb)
{
    
}

void read_data_runner(pCycleBuffer pcb)
{
}

int main(int argc, char const *argv[])
{
    pthread_t write_thread, read_thread;

    pCycleBuffer pcb = initCyclebuffer(20480);

    pthread_create(&write_thread, pcb, write_data_runner, NULL);
    pthread_create(&read_thread, pcb, read_data_runner, NULL);


    pthread_join(write_thread,NULL);
    pthread_join(read_thread,NULL);
    return 0;
}
