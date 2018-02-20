#ifndef SETPOINT_SET_POINT_H
#define SETPOINT_SET_POINT_H

#include <stdio.h>
#include <stdlib.h>

#define sizeStep 10
#define delCode 0
#define addCode 1

/*
 * A simple structure to store a coordinate
 */
struct Point {
    unsigned char x:4, y:4;
};

/*
 * A set of Points
 */
struct Set {
    unsigned setSize;
    struct Point *setHead;
};


struct Point createPoint(unsigned char x, unsigned char y);
struct Set *createSet();
int checkMemory(struct Set *mainSet, int operationCode);
int addElement(struct Set *mainSet, const struct Point *newElement);
int delElement(struct Set *mainSet);
int elementSearch (struct Set *mainSet, struct Point *requestPoint);
int saveSet(struct Set *mainSet, char *filePath);
int resetSet(struct Set *mainSet, char *filePath);

#endif
