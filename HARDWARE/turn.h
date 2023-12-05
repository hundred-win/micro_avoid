#ifndef __MICRO_TURN_H
#define __MICRO_TURN_H


void turn_init(void);
void set_angle(float angle);

int front_detection(void);
int left_detection(void);
int right_detection(void);

#endif

