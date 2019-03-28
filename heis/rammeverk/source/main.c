#include "elev.h"
#include <stdio.h>
#include "elevator.h"


int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");

    elev_set_motor_direction(DIRN_DOWN);
    start();
    elev_set_button_lamp(BUTTON_CALL_UP, 2, 0);

    static int count = 0;
    while(count < 5) {
        count += elev_get_button_signal(BUTTON_CALL_DOWN, 1);
        listen();

        //Nå funker listen, men må fikse get_button
    }

    elev_set_motor_direction(DIRN_STOP);


    while (1) {
        // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }

        // Stop elevator and exit program if the stop button is pressed
        if (elev_get_stop_signal()) {
            elev_set_motor_direction(DIRN_STOP);
            break;
        }
    }

    return 0;
}
