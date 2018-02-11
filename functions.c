#include "set-point.h"

/*
 * Creates a Point
 */
struct Point createPoint(unsigned x, unsigned y) {

    struct Point tmpPoint;
    tmpPoint.x = x;
    tmpPoint.y = y;
    return tmpPoint;
}

/*
 * Creates a Set
 */
struct Set *createSet() {

    struct Set *tmpSet;
    tmpSet = (struct Set *)malloc(sizeof(struct Set));
    tmpSet->setSize = 0;
    tmpSet->setHead = (struct Point *)calloc(sizeStep, sizeof(struct Point));
    return tmpSet;
}

/*
 * Reduces or extends memory of a set
 * pass 0 to check while adding an element
 * pass 1 to check while deleting an element
 */
int checkMemory(struct Set **mainSet, int operationCode) {

    if(operationCode) {
        if ((*mainSet)->setSize % sizeStep == 0 && (*mainSet)->setSize >= sizeStep) {
            (*mainSet)->setHead = (struct Point *)realloc((*mainSet)->setHead, sizeof(struct Point)*((*mainSet)->setSize+sizeStep));
        }
    } else {
        if ((*mainSet)->setSize % sizeStep == 1 && (*mainSet)->setSize > sizeStep) {
            (*mainSet)->setHead = (struct Point *)realloc((*mainSet)->setHead, sizeof(struct Point)*((*mainSet)->setSize-sizeStep));
        }
    }
    return 1;
}

/*
 * Add a Point to the end of a Set
 */
int addElement(struct Set **mainSet, struct Point *newElement) {

    checkMemory(mainSet, addCode);
    (*mainSet)->setHead[(*mainSet)->setSize] = *newElement;
    (*mainSet)->setSize++;
    return 1;
}

/*
 * Delete the last Point of a Set
 */
int delElement(struct Set **mainSet) {

    checkMemory(mainSet, delCode);
    if((*mainSet)->setSize == 0) {
        return 0;
    } else {
        (*mainSet)->setSize--;
        return 1;
    }
}

/*
 * Checks whether there is the same Point in a Set
 */
int elementSearch (struct Set *mainSet, struct Point *requestPoint) {

    for(int i = 0; i<mainSet->setSize; i++) {
        if(mainSet->setHead[i].x == requestPoint->x) {
            if(mainSet->setHead[i].y == requestPoint->y) {
                return 1;
            }
        }
    }
    return 0;
};

/*
 * Encodes a Set to a text file
 */
int saveSet(struct Set *mainSet, char *filePath) {
    FILE *setFile = fopen(filePath, "w");
    if(setFile == NULL) {
        return 0;
    } else {
        char charPoint;
        for(int i = 0; i < mainSet->setSize; i++) {
            charPoint = (mainSet->setHead[i].x << 4) + mainSet->setHead[i].y;
            fprintf(setFile, "%c", charPoint);
        }
        fclose(setFile);
        return 1;
    }
}

/*
 * Decodes and adds Points to a Set
 */
int resetSet(struct Set **mainSet, char *filePath) {
    FILE *setFile = fopen(filePath, "r");
    if(setFile == NULL) {
        return 0;
    } else {
        char charPoint;
        struct Point newPoint;
        while((charPoint = getc(setFile)) != EOF) {
            newPoint = createPoint(charPoint>>4, charPoint & 15);
            addElement(mainSet, &newPoint);
        }
        return 1;
    }
}
