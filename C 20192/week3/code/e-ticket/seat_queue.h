#ifndef __SEAT_QUEUE__H__
#define __SEAT_QUEUE__H__

#define MAX_LEN 103
#include "request.h"

typedef struct Seat sq_element_t;
struct SeatQueue {
  sq_element_t data[MAX_LEN];
  int f, r;
};

typedef struct SeatQueue* sq_queue;
  
sq_queue create_queue();
int is_empty(sq_queue q);
int is_full(sq_queue q);

sq_queue sq_enqueue(sq_queue q, sq_element_t x);
sq_queue sq_dequeue(sq_queue q);
sq_element_t sq_front(sq_queue q);
sq_element_t sq_rear(sq_queue q);
int sq_length(sq_queue q);

void free_queue(sq_queue q);

#endif
