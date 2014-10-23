#ifndef VIRTIX_PROC_H
#define VIRTIX_PROC_H

#include "common.h"
#include "isr.h"

typedef struct virtix_proc {
	registers_t* registers;

	unsigned int pid;
	char* name;
	
	int state;
	int thread;

	struct virtix_proc* parent;
	struct virtix_proc* next;
	struct virtix_proc* last;
} virtix_proc_t;

void kill_proc(unsigned int pid);				//End a process
void spawn_proc(virtix_proc_t* process);			//Start a process
void susp_proc(unsigned int pid);				//Suspend a process
void wake_proc(unsigned int pid);				//Wake a process back up
void child_proc(virtix_proc_t* process, unsigned int pid);	//Sleep the process
void fork_proc(unsigned int pid);				//Fork the process

void init_procs(virtix_proc_t* process);			//maps a process handler to the PIT

#define PROC_RUNNING	0
#define PROC_ASLEEP	1

#define PROC_THREAD	0
#define PROC_PROC	1
#define PROC_ROOT	2

#endif
