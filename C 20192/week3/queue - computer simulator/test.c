#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue-list.h"
#include "queue-list.c"

queue run;
queue wait;
int maxPrg, prgRun;
int memCap,memUsed;

void configuration_input();
void create_program();
void kill_program();
void show_status();
void processNewProgram(struct Program prg);

int main() {
	int running = 1;
  int selection;
  run = create_queue();
	wait = create_queue();

//  initialize();

  while (running) {
    printf("\n1. Enter configuration input\n");
    printf("2. Create a new program\n");
    printf("3. Kill a program\n");
    printf("4. Show status\n");
    printf("5. Quit\n");
    printf("Choose an option:");
    scanf("%d", &selection);
    switch (selection) {
    case 1:
      configuration_input();
      break;
    case 2:
      create_program();
      break;
    case 3:
      kill_program();
      break;
    case 4:
      show_status();
      break;
    case 5:
      running = 0;
      break;
    }
  }
	free_queue(run);
  free_queue(wait);
  return 0;
}

void configuration_input(){
	memUsed = 0;
	printf("-Enter num of process and memory capacity: ");
//	scanf("%d %d",&num, &memCap);
	maxPrg=7; memCap = 10; 
}

void create_program(){
	struct Program prg;
	printf("-Enter program ID and its memory: ");
	scanf("%s %d",prg.id, &prg.memory);
	processNewProgram(prg);
}

void kill_program(){
	if (is_empty(run)) printf("-No program running\n");
	else {
		memUsed -=front(run).memory;
		run = dequeue(run);
		prgRun--;
		printf("-Kill a program successfully\n");
		
		//check if possible to run a program in wait queue
		if (!is_empty(wait) && memUsed + front(wait).memory<=memCap) {
			run = enqueue(run, front(wait));
			wait = dequeue(wait);
			prgRun++;
			printf("-Run a waiting program successfully");
		}
	}

}

void show_status(){
	printf("-Printing the run queue: \n");
	node_t p=run->f;
	while (p!=NULL) {
		printf("Id = %s, Memory = %d\n", p->data.id, p->data.memory);
		p=p->next;
	}
	printf("-Printing the wait queue: \n"); 
	p=wait->f;
	while (p!=NULL) {
		printf("Id = %s, Memory = %d\n", p->data.id, p->data.memory);
		p=p->next; 
	}
}

void processNewProgram(struct Program prg){
	if (prg.memory+memUsed <= memCap && prgRun<maxPrg) {
		memUsed += prg.memory;
		run = enqueue(run, prg);
		prgRun++;
		printf("Program is now running !");
	} else {
		printf("Program is now waiting !");
		wait = enqueue(wait,prg);
	}
}
