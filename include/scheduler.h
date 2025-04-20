#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

// Enum para os algoritmos de escalonamento
typedef enum {
    FCFS,
    SJF,
    PRIORITY_NON_PREEMPTIVE,
    PRIORITY_PREEMPTIVE,
    ROUND_ROBIN,
    RATE_MONOTONIC,
    EDF
} SchedulingAlgorithm;

// Funções para os algoritmos de escalonamento - modo dinâmico
void run_fcfs(ProcessQueue* queue);
void run_sjf(ProcessQueue* queue);
void run_priority(ProcessQueue* queue, int preemptive);
void run_round_robin(ProcessQueue* queue, int quantum);
void run_rm(ProcessQueue* queue);
void run_edf(ProcessQueue* queue);

// Funções para os algoritmos de escalonamento - modo estático
void run_fcfs_static(ProcessQueue* queue, int tempo_total);
void run_sjf_static(ProcessQueue* queue, int tempo_total);
void run_priority_static(ProcessQueue* queue, int preemptive, int tempo_total);
void run_round_robin_static(ProcessQueue* queue, int quantum, int tempo_total);
void run_rm_static(ProcessQueue* queue, int tempo_total);
void run_edf_static(ProcessQueue* queue, int tempo_total);

// Função para chamar o escalonador com base no algoritmo e no modo
void run_scheduler(ProcessQueue* queue, SchedulingAlgorithm algo, int quantum);
void run_scheduler_static(ProcessQueue* queue, SchedulingAlgorithm algo, int quantum, int tempo_total);

SchedulingAlgorithm parse_algo(const char* str);

#endif
