#ifndef PROCESS_H
#define PROCESS_H

struct processes{
    int id; 
    int dur;
    int prio;
    int execu;
    int esp;
    struct processes *next;
    /*
        id - process identification
        dur - process duration time
        exe - process runtime
        esp - process waiting time
    */
};

struct processes *process_input(int id, int dur, int prio);

#endif