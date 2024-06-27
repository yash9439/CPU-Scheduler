#include <stdio.h>
#include <stdlib.h>
#include "headers/process.h"

struct processes *process_input(int id, int dur, int prio){
    struct processes *loc;
    loc = (struct processes*)malloc(sizeof(struct processes));
    if(loc == NULL){
        printf("Allocation error.\nEnd of execution\n");
        exit(1);
    };
    loc->id = id;
    loc->dur = dur;
    loc->prio = prio;
    loc->execu = 0;
    loc->esp = 0;
    loc->next = NULL;
    return loc;
}