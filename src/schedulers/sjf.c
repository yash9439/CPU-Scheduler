#include <stdio.h>
#include <stdlib.h>
#include "headers/schedulers.h"

void sjf(struct processes *loc, int process_number){
    int execution_time, shortest, start, end, waiting_time, duration;
    struct processes *copy, *src_tmp, *tmp, *before_shortest;
    printf("\n\t\tShortest-Job-First- (SRTF)\n\n ");
    src_tmp = loc;
    copy = tmp = NULL;
    while (src_tmp != NULL){/*making copies of the processes*/
        if(copy == NULL){
            copy = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = copy;
        }
        else{
            tmp->next = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = tmp->next;
        }
        src_tmp = src_tmp->next;
    }
    execution_time = 0;
    while(copy != NULL){/*new process search*/
        before_shortest = NULL;
        shortest = copy->dur;
        tmp = copy->next;
        src_tmp = copy;
        while(tmp != NULL){
            if(tmp->dur < shortest){
                shortest = tmp->dur;
                before_shortest = src_tmp;
            }
            src_tmp = tmp;
            tmp = tmp->next;
        }
        if(before_shortest == NULL){/*process is executed and copy is killed and allocates the 1st process s is less*/
            start = execution_time;
            execution_time += copy->dur;
            duration = copy->dur;
            end = execution_time;
            printf("\tProcess: %d\t Duration: %d\tWaiting time: %d \tFinish: %d\n", copy->id, duration, start, end);
            waiting_time += end;
            src_tmp = copy;
            copy = copy->next;
            free(src_tmp);
        }
        else{ /*allocates the 1st process if there is no smaller one*/
            tmp = before_shortest->next;
            start = execution_time;
            execution_time += tmp->dur;
            duration = tmp->dur;
            end = execution_time;
            printf("\tProcess: %d\t Duration: %d\tWaiting time: %d \tFinish: %d\n", tmp->id, duration, start, end);
            before_shortest->next = tmp->next;
            free(tmp);
        }
    }
    printf("\n\t\tAverage Waiting Time= %f\n",waiting_time*1.0/process_number);
} 

void sjf_simulator(struct processes *loc, int process_number){
    int execution_time, shortest, start, end, duration, i=0, p[process_number];
    struct processes *copy, *src_tmp, *tmp, *before_shortest;
    printf("\n\t    Visually simulating scaling\n\n ");
    src_tmp = loc;
    copy = tmp = NULL;
    while (src_tmp != NULL){/*copying the processes*/
        if(copy == NULL){
            copy = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = copy;
        }
        else{
            tmp->next = process_input(src_tmp->id, src_tmp->dur, src_tmp->prio);
            tmp = tmp->next;
        }
        src_tmp = src_tmp->next;
    }
    execution_time = 0;
    printf("\t\t  ");
    while(copy != NULL){/*new process search*/
        before_shortest = NULL;
        shortest = copy->dur;
        tmp = copy->next;
        src_tmp = copy;
        while(tmp != NULL){
            if(tmp->dur < shortest){
                shortest = tmp->dur;
                before_shortest = src_tmp;
            }
            src_tmp = tmp;
            tmp = tmp->next;
        }
        if(before_shortest == NULL){/*process is executed and copy is killed and allocates the 1st process s is less*/
            start = execution_time;
            execution_time += copy->dur;
            duration = copy->dur;
            end = execution_time;
            p[i]=execution_time;
            printf("| P%d ", copy->id);
            src_tmp = copy;
            copy = copy->next;
            free(src_tmp);
        }
        else{ /*allocates the 1st process if there is no smaller one*/
            tmp = before_shortest->next;
            start = execution_time;
            execution_time += tmp->dur;
            duration = tmp->dur;
            p[i]=execution_time;
            end = execution_time;
            printf("| P%d ", tmp->id);
            before_shortest->next = tmp->next;
            free(tmp);
        }
        i++;
    }
    printf("|");
    printf("\n\t\t  0  ");
    for (i=0; i<process_number; i++)
        printf("  %d ", p[i]);
}