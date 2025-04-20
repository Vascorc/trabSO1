#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "process.h"
#include "scheduler.h"

SchedulingAlgorithm parse_algo(const char* str) {
    if (strcmp(str, "FCFS") == 0) return FCFS;
    if (strcmp(str, "SJF") == 0) return SJF;
    if (strcmp(str, "PRIORITY") == 0) return PRIORITY_NON_PREEMPTIVE;
    if (strcmp(str, "PPRIO") == 0) return PRIORITY_PREEMPTIVE;
    if (strcmp(str, "RR") == 0) return ROUND_ROBIN;
    if (strcmp(str, "RM") == 0) return RATE_MONOTONIC;
    if (strcmp(str, "EDF") == 0) return EDF;
    return FCFS;
}

int main(int argc, char* argv[]) {
    // 🌱 Semente aleatória ou fornecida
    int seed = (int)time(NULL);  // valor padrão se nenhuma seed for passada
    if (argc >= 6) {
        seed = atoi(argv[5]);
    }
    srand(seed);
    printf("Seed usada: %d\n", seed);

    if (argc < 3) {
        printf("Uso: %s <ALGO> <STATIC|DYNAMIC> [argumentos adicionais]\n", argv[0]);
        return 1;
    }

    SchedulingAlgorithm algo = parse_algo(argv[1]);
    int is_dynamic = strcmp(argv[2], "DYNAMIC") == 0;

    ProcessQueue* queue = create_process_queue(10);

    if (is_dynamic) {
        // Se fornecido, o número de processos é o 4º argumento
        int num_processes = (argc >= 4) ? atoi(argv[3]) : 5;
        if (num_processes <= 0) {
            printf("Erro: Número de processos inválido!\n");
            return 1;
        }

        for (int i = 0; i < num_processes; i++) {
            add_process(queue, generate_random_process(i + 1, i * 2));
        }

    } else {  // STATIC mode
        if (argc < 4) {
            printf("Erro: No modo STATIC, forneça o tempo máximo de simulação!\n");
            return 1;
        }

        int max_simulation_time = atoi(argv[3]);
        if (max_simulation_time <= 0) {
            printf("Erro: Tempo máximo de simulação inválido!\n");
            return 1;
        }

        load_processes_from_file(queue);
        printf("Tempo máximo de simulação: %d\n", max_simulation_time);
    }

    int quantum = (argc >= 5) ? atoi(argv[4]) : 2;
    run_scheduler(queue, algo, quantum);
    destroy_process_queue(queue);
    return 0;
}
