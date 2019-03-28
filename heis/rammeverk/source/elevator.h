#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "elev.h"
#include "channels.h"
#include "io.h"
#include "queue.h"


#include <stdbool.h>


struct Elevator{
    int floor;
    bool valid_position;
    elev_motor_direction_t dir;
    bool safety;
    //Queue queue_m;  
};

// Elevator functions
int start(void);
void set_elevator();
void elevator_rest();

struct Elevator* getElevator();


#endif