#ifndef QUEUE_H
#define QUEUE_H

#include "elev.h"
#include "elevator.h"
#include "channels.h"

#include <stdbool.h>

enum floor_name{ONE_UP,TWO_DOWN,TWO_UP,THREE_DOWN,THREE_UP,FOUR_DOWN};


struct Queue{
    int queue[6];
    int empty_queue;
};

void set_queue(int floor);
struct Queue* get_queue();
void pop_queue(int floor);

void listen(void);



#endif