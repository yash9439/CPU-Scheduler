#include <stdio.h>
#include "headers/schedulers.h"

void fcfs(struct processes *loc, int process_number) {
    int time = 0, start, end, waiting_time=0, turnaround_time=0;
    int p[process_number], i=0;
    struct processes *tmp = loc;
    printf("\n\t\tFirts-Come, First-Serve (FCFS) Scheduling\n\n");
    while (tmp != NULL){
        start = time;
        time += tmp->dur;
        p[i] = time;
        end = time;
        printf("\tProcess: %d\t Duration: %d\tWaiting time: %d \tFinish: %d\n", tmp->id, tmp->dur, start, end);
        waiting_time += start;
        tmp = tmp->next;
        i++;
    }
    i=0;
    printf("\n\t\tAverage Waiting Time= %f\n\n\n",waiting_time*1.0/process_number);
    printf("\t    Visually simulating scaling.");
    printf("\n\n\t\t    ");
    for (i=0; i<process_number; i++){
            printf("| P%d ", i+1);
    }
    printf("|");
    printf("\n\t\t    0  ");
    for (i=0; i<process_number; i++)
        printf("  %d ", p[i]);
}