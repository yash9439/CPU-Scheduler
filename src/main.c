#include <stdio.h>
#include <stdlib.h>
#include "headers/process.h"
#include "headers/schedulers.h"
#include "headers/utils.h"

int main(){
    int choice, es_proc, process_number, i, id, dur, prio, position=0;
    do{
    if (position==0){
        es_proc=painel();
    }
    else
        choice = menu();
    struct processes *list_proc, *tmp_proc;
    if(es_proc == 1){
        process_number = 4;
        list_proc = process_input(1, 12, 2);
        list_proc->next = process_input(2, 2, 1); tmp_proc = list_proc->next;
        tmp_proc->next  = process_input(3,  8, 4); tmp_proc = tmp_proc->next;
        tmp_proc->next  = process_input(4,  10, 3);
        choice = menu();
    }
    else if(es_proc==2){
        top();
        printf("\n\n  NOTE: Choose preferably for more than 3 processes.");
        printf("\n\n   Enter the number of processes: ");
        scanf("%d", &process_number);
        for(i=0; i<process_number;i++){
            system("clear");
            top();
            printf("\n             Process %d: ", i+1);
            printf("\n\nEnter your duration time (Burst time) P[%d]: ", i+1);
            scanf("%d", &dur);
            printf("Enter your execution priority P[%d]: ", i+1);
            scanf("%d", &prio);
            if(i==0)
                list_proc = process_input(i+1, dur, prio);
            else if(i==1){
                list_proc->next = process_input(i+1, dur, prio); tmp_proc = list_proc->next;
            }
            else if(i==process_number-1){
                tmp_proc->next  = process_input(i+1,  dur, prio);
            }
            else{
                tmp_proc->next  = process_input(i+1,  dur, prio); tmp_proc = tmp_proc->next;
            }
        }
        position=1;
        choice = menu();
    }

    if(choice == 1){
        system("clear");
        list_processes(list_proc);
        fcfs(list_proc, process_number);
        printf("\n\n\t< 1 > To go back\nChoose: ");
        int i;
        scanf("%d", &i);
    }
    else if (choice == 2){
        system("clear");
        list_processes(list_proc);
        sjf(list_proc, process_number);
        sjf_simulator(list_proc, process_number);
        printf("\n\n\t< 1 > To go back\nChoose: ");
        int i;
        scanf("%d", &i);
    }
    else if (choice == 3){
        system("clear");
        list_processes(list_proc);
        priority_scheduler(list_proc, process_number);
        priority_scheduler_simulator(list_proc, process_number);
        printf("\n\n\t< 1 > To go back\nChoose: ");
        int i;
        scanf("%d", &i);
    }
    else if(choice == 4){
        system("clear");
        int quantum;
        list_processes(list_proc);
        printf("\nEnter the desired time quantum: ");
        scanf("%d", &quantum);
        robbin_round(list_proc, quantum, process_number);
        printf("\n\n\t< 1 > To go back\nChoose: ");
        int i;
        scanf("%d", &i);
    }
    else if(choice == 5){
        printf("\n\nEnd of program.\n\n");
        exit(2);
    }
    }while(choice <= 6);
    return 0;
}