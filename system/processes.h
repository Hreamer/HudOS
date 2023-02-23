#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MAX_PROCS 200


struct process_table_entry {
    uint8_t PID;            //PID of the process
    uint32_t priority;     //Priority number of process
    char* stackbase;       //Location in memory of the stackbase
};

struct process_node {
    uint32_t priority;      //process priority 
    uint32_t index;         //index into the process table
    char* next;             //pointer to next node in the queue
};

struct process_node endOfQueue;     //end of the process queue 
struct process_node frontOfQueue;   //start of the process queue

