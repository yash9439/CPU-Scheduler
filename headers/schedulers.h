#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#include "process.h"

void fcfs(struct processes *loc, int process_number);
void sjf(struct processes *loc, int process_number);
void sjf_simulator(struct processes *loc, int process_number);
void priority_scheduler(struct processes *loc, int process_number);
void priority_scheduler_simulator(struct processes *loc, int process_number);
void robbin_round(struct processes *loc, int quantum, int process_number);

#endif