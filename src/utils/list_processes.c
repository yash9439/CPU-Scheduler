#include <stdio.h>
#include <stdlib.h>
#include "headers/utils.h"

int menu(){
    int choice;
 
    system("clear");
    printf("\n\n                              CPU SCHEDULER");
    printf("\n-------------------------------------------------------------------------------");
    printf("\n     Choose the algorithm you want to use to simulate the scheduler. \n");
    printf("\n                  < 1 > Firts-Come, First-Serve (FCFS)");
    printf("\n                  < 2 > Shortest-Job-First- (SRTF) ");
    printf("\n                  < 3 > Priority scheduler ");
    printf("\n                  < 4 > Round Robin (RR) ");
    printf("\n                  < 5 > Exit \n");
    printf("\n     Your choice: ");
    scanf("%i", &choice);

    return choice;
}

int painel(){
    int choice;
    system("clear");
    printf("\n\n                              CPU SCHEDULER");
    printf("\n-------------------------------------------------------------------------------\n\n");
    printf("                           Process definition.\n\n");
    printf("\n                  < 1 > Use processes established by the program.");
    printf("\n                  < 2 > Introduce new processes.");
    printf("\n\n    Your choice: ");
    scanf("%i", &choice);
    if (choice>2)
        painel();
    else
        return choice;
}

void top(){
    system("clear");
    printf("\n\n                              CPU SCHEDULER");
    printf("\n-------------------------------------------------------------------------------\n\n");
}

void list_processes(struct processes *loc){
    struct processes *tmp = loc;
    printf("\n\n\t\t\tList of processes\n\n");
    while(tmp != NULL){
        printf("\tProcess: %d\tPriority: %d\tDuration: %d\n", tmp->id, tmp->prio, tmp->dur);
        tmp = tmp->next;
    }
    printf("\n");
}