#include "queue.h"

struct Queue m_queue;


void set_queue(int floor){
    m_queue.queue[floor] = 1;
}

struct Queue* get_queue(){
    return &m_queue;
}

void pop_queue(int floor) {
    m_queue.queue[floor] = 0;
}


void listen(void) {
    elev_set_button_lamp(BUTTON_CALL_UP, 2, 1);
    /*for (int i = 0; i < 3; i++) {
                
        if (elev_get_button_signal(BUTTON_CALL_UP,  i)) {
            set_queue(2*i);
            elev_set_button_lamp(BUTTON_CALL_UP, i, 1);
        }

        if (elev_get_button_signal(BUTTON_CALL_DOWN,i)) {
            set_queue(2*i+1);
            elev_set_button_lamp(BUTTON_CALL_DOWN,i,1);
        }
    }
    */
}

