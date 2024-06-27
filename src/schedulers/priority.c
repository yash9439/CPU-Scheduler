#include <stdio.h>
#include <stdlib.h>
#include "headers/schedulers.h"

void priority_scheduler(struct processes *loc, int process_number){
    int execution_time, start, maior, end, waiting_time, duration;
    struct processes *copy, * src_tmp, *tmp, *maior_prio;
    printf("\n\t\tPriority scheduler \n\n");
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
    while(copy != NULL){/*check next process*/
        maior_prio = NULL;
        maior = copy->prio;
        tmp = copy->next;
        src_tmp = copy;
        while(tmp != NULL){
            if(tmp->prio < maior){
                maior = tmp->prio;
                maior_prio = src_tmp;
            }
            src_tmp = tmp;
            tmp = tmp->next;
        }
        if(maior_prio == NULL){/*ver se 1º tem prioridade maior*/
            start = execution_time;
            execution_time += copy->dur;
            duration = copy->dur;
            end = execution_time;
            printf("\tProcess: %d\t Duration: %d\tWaiting time: %d \tFinish: %d\n", copy->id, duration, start, end);
            waiting_time += end;
            src_tmp = copy->next;
            free(copy);
            copy = src_tmp;
        }
        else {/*if 1st does not have higher priority*/
            tmp = maior_prio->next;
            start = execution_time;
            execution_time += tmp->dur;
            duration = tmp->dur;
            end = execution_time;
            printf("\tProcess: %d\t Duration: %d\tWaiting time: %d \tFinish: %d\n", tmp->id, duration, start, end);
            maior_prio->next = tmp->next;
            free(tmp);
        }
    }
    printf("\n\t\tAverage Waiting Time= %f\n",waiting_time*1.0/process_number);
}

void priority_scheduler_simulator(struct processes *loc, int process_number){
    int execution_time, start, maior, end, duration, i=0, p[process_number];
    struct processes *copy, * src_tmp, *tmp, *maior_prio;
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
    while(copy != NULL){/*check next process*/
        maior_prio = NULL;
        maior = copy->prio;
        tmp = copy->next;
        src_tmp = copy;
        while(tmp != NULL){
            if(tmp->prio < maior){
                maior = tmp->prio;
                maior_prio = src_tmp;
            }
            src_tmp = tmp;
            tmp = tmp->next;
        }
        if(maior_prio == NULL){/*see if 1st has higher priority*/
            start = execution_time;
            execution_time += copy->dur;
            p[i]=execution_time;
            duration = copy->dur;
            end = execution_time;
            printf("| P%d ", copy->id);
            src_tmp = copy->next;
            free(copy);
            copy = src_tmp;
        }
        else {/* if 1st does not have higher priority*/
            tmp = maior_prio->next;
            start = execution_time;
            execution_time += tmp->dur;
            p[i]=execution_time;
            duration = tmp->dur;
            end = execution_time;
            printf("| P%d ", tmp->id);
            maior_prio->next = tmp->next;
            free(tmp);
        }
        i++;
    }
    printf("|");
    printf("\n\t\t  0  ");
    for (i=0; i<process_number; i++)
        printf("  %d ", p[i]);
}