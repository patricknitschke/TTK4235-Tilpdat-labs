#include "elevator.h"


struct Elevator elevator;

int start(void){
    int floor = elev_get_floor_sensor_signal();
    //motor_dir already set direction up from main() 
        
    while(floor==-1){
        floor = elev_get_floor_sensor_signal();
    }

    elev_set_motor_direction(DIRN_STOP);
    elevator.dir = DIRN_STOP;    
    set_elevator();
    return floor;
    
}

void set_elevator(){
    elevator.floor = elev_get_floor_sensor_signal();
    if (elevator.floor != -1){
        elevator.valid_position = true;
    }
    else{
        elevator.valid_position = false;
    }
}


void elevator_rest(){
    //checks if queue if empty. If so -> stop and rest.
}

struct Elevator* getElevator() {
    return &elevator;
}