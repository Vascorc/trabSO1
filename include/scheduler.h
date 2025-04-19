#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

typedef enum {
    FCFS,
    SJF,
    PRIORITY_PREEMPTIVE,
    PRIORITY_NON_PREEMPTIVE,
    ROUND_ROBIN,
    RATE_MONOTONIC,
    EDF
} SchedulingAlgorithm;

void run_scheduler(ProcessQueue* queue, SchedulingAlgorithm algo, int quantum);
void run_fcfs(ProcessQueue* queue);

#endif
