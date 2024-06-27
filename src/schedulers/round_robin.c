#include <stdio.h>
#include <stdlib.h>
#include "headers/schedulers.h"

void robbin_round(struct processes *loc, int quantum, int process_number){
    int count, j, time, remain, flag=0;
    int waiting_time=0, turnaround_time=0, at[10], bt[10], rt[10];
    remain=process_number;
    struct processes *copy, *src_tmp, *tmp, *slot;
    printf("\n\t\tRound Robin (RR) - Quantum: %d\n", quantum);
    src_tmp = loc;
    for(count=0; count < process_number; count++){
            bt[count] = src_tmp->dur;
            rt[count] = bt[count];
            src_tmp = src_tmp->next;
    }
    for(time = 0, count = 0; remain !=0;){
        at[count]=time;
        if(rt[count] <= quantum && rt[count] > 0){
            time+=rt[count];
            rt[count]=0;
            flag=1;
        }
        else if(rt[count]>0){
            rt[count]-=quantum;
            time+=quantum;
        }
        if(rt[count]==0 && flag==1){
            remain--;
            printf("\tProcess: %d\tWaiting time: %d \tFinish: %d\n", count+1, time-bt[count], time);
            waiting_time+=time-bt[count];
            turnaround_time+=time;
            flag=0;
        }
        if(count == process_number-1)
            count=0;
        else if(at[count]<=time)
            count++;
        else
            count=0;
    }
    printf("\n\t      Average Waiting Time= %f\n",waiting_time*1.0/process_number); 
    printf("\t   Avgerage Turnaround Time = %f",turnaround_time*1.0/process_number);
    free(src_tmp);
}