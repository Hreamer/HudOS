#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MAX_PROCS 254       //8-bit PID Means 254 Max Processes Allowed as one is reserved for NULL process

// CODE FOR PROCESS INFORMATION STORAGE --------------------------
struct process_entry {
    uint8_t PID;                  //PID of the process
    uint32_t priority;            //Priority number of process
    char* stackbase;              //Location in memory of the stackbase
    char* stacktop;               //Location in memory of top of stack 
    uint8_t state;
};

uint8_t currProcessID;            //Process ID currently running
process_entry process_table[];    //Process Table to store process entries
//-----------------------------------------------------------------


