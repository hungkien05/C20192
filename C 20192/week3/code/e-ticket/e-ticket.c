#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "request.h"
#include "seat_queue.h"
#include "request_list.h"

#include "seat_queue.c"
#include "request_list.c"

sq_queue w_seats;
sq_queue c_seats;
sq_queue n_seats;
rl_list rqs;

void initialize();
void cleanup();
struct Request process(struct Request rq);
void enqueue_seats_back(struct Request rq);

void make_new_request();
void cancel_request();
void print_requests();
void search_request();

int main() {
  int running = 1;
  int selection;

  initialize();

  while (running) {
    printf("\n1. Make new request\n");
    printf("2. Cancel request\n");
    printf("3. Print all requests\n");
    printf("4. Search by name\n");
    printf("5. Quit\n");
    printf("Choose an option:");
    scanf("%d", &selection);
    switch (selection) {
    case 1:
      make_new_request();
      break;
    case 2:
      cancel_request();
      break;
    case 3:
      print_requests();
      break;
    case 4:
      search_request();
      break;
    case 5:
      running = 0;
      break;
    }
  }

  cleanup();
  return 0;
}


void initialize() {
  struct Seat seat;
  int i;
  
  w_seats = sq_create();
  c_seats = sq_create();
  n_seats = sq_create();
  
  // Initialize available seats
  for (i = 1; i <= 50; i++) {
    seat.row = i;
    seat.col = 'A';
    w_seats = sq_enqueue(w_seats, seat);
    seat.row = i;
    seat.col = 'F';
    w_seats = sq_enqueue(w_seats, seat);
    seat.row = i;
    seat.col = 'B';
    n_seats = sq_enqueue(n_seats, seat);
    seat.row = i;
    seat.col = 'E';
    n_seats = sq_enqueue(n_seats, seat);
    seat.row = i;
    seat.col = 'C';
    c_seats = sq_enqueue(c_seats, seat);
    seat.row = i;
    seat.col = 'D';
    c_seats = sq_enqueue(c_seats, seat);
  }

  // Initialize request list
  rqs = rl_create();
}

void cleanup() {
  sq_free(w_seats);
  sq_free(c_seats);
  sq_free(n_seats);

  rl_free(rqs);
}


void make_new_request() {
  printf("Nhap ?: ");
  struct Request rq;
  strcpy(rq.name, "Yen");
  rq.quantity=5;
  rq.seat_type=1;
  rq=process(rq);
  rqs = rl_insert_after(rqs,rqs,rq);
  
}


void cancel_request() {
  char name[20]="Yen";
  printf("Enter request's name to cancel: ");
//  scanf("%s",name);
  int kt=0;
  rl_node_t p=rqs;
  while (p!=NULL){
  	if (strcmp(p->data.name, name)==0) {
  		kt=1;
  		break;
		}
		p=p->next;
	}
	if (kt==1){
		rqs = rl_remove_at(rqs, p);
		if (p->data.result==1){
	  	enqueue_seats_back(p->data);
		}
		printf("kt=%d",kt);
	} 
	
	
}
void print_requests() {
  rl_node_t p;
  p=rqs;
  printf("Printing all request...\n");
  while (p!=NULL) {
  	printf("-Request: %s %d %d %d\n", p->data.name, p->data.quantity, p->data.seat_type, p->data.result);
  	int i;
		if ( p->data.result==1) {
			printf("Here are your arranged seats:");
			for (i=0; i< p->data.quantity; i++) printf("%d%c ", p->data.reserved_seats[i].row, p->data.reserved_seats[i].col);
		} else printf("Request refused");
		printf("\n");
  	p=p->next;
	}
}
void search_request() {
	char name[20]="Yen";
  printf("Enter name to search: ");
//  scanf("%s",name);
  int kt=0;
  rl_node_t p=rqs;
  while (p!=NULL){
  	if (strcmp(p->data.name, name)==0) {
  		printf("Name found !\n");
  		printf("-Request: %s %d %d %d\n", p->data.name, p->data.quantity, p->data.seat_type, p->data.result);
  		kt=1;
		}
		p=p->next;
	}
	if (kt==0) printf("Name not found\n");
}

struct Request process(struct Request rq){
	switch (rq.seat_type){
		case 1:
			if (sq_length(w_seats)<rq.quantity) rq.result=0;
			else {
				int i;
				rq.result=1;
				for (i=0; i<rq.quantity; i++){
					rq.reserved_seats[i]= sq_front(w_seats);
					w_seats = sq_dequeue(w_seats);
				}
			}
			break;
		case 2:
			if (sq_length(c_seats)<rq.quantity) rq.result=0;
			else {
				int i;
				rq.result=1;
				for (i=0; i<rq.quantity; i++){
					rq.reserved_seats[i]=sq_front(c_seats);
					c_seats = sq_dequeue(c_seats);
				}
			}
			break;
		case 3:
			if (sq_length(n_seats)<rq.quantity) rq.result=0;
			else {
				int i;
				rq.result=1;
				for (i=0; i<rq.quantity; i++){
					rq.reserved_seats[i]= sq_front(n_seats);
					n_seats = sq_dequeue(n_seats);
				}
			}
			break;
	}
	return rq;
}

void enqueue_seats_back(struct Request rq){
	int i;
	switch (rq.seat_type){
		case 1:
			rq.result=1;
			for (i=0; i<rq.quantity; i++){
				w_seats = sq_enqueue(w_seats, rq.reserved_seats[i]);				
			}
			break;
		case 2:
			rq.result=1;
			for (i=0; i<rq.quantity; i++){
				c_seats = sq_enqueue(c_seats, rq.reserved_seats[i]);				
			}
			break;
		case 3:
			rq.result=1;
			for (i=0; i<rq.quantity; i++){
				n_seats = sq_enqueue(n_seats, rq.reserved_seats[i]);
			}
			break;
	}
}
