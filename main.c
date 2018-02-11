#include "set-point.h"

const char filePath[20] = "..\\set.txt";

int main() {

    int x, y;
    puts("Enter X coordinate: ");
    scanf("%u", &x);
    puts("Enter Y coordinate: ");
    scanf("%u", &y);

    struct Point newPoint = createPoint(x, y), firstPoint = createPoint(5, 5), secondPoint = createPoint(x, y), thirdPoint = createPoint(5, 5);
    struct Set *newSet = createSet();

    addElement(&newSet, &newPoint);
    addElement(&newSet, &firstPoint);
    addElement(&newSet, &secondPoint);
    addElement(&newSet, &thirdPoint);
    if(saveSet(newSet, &filePath)) {
        puts("saved");
    } else {
        puts("no");
    }
    delElement(&newSet);
    delElement(&newSet);
    delElement(&newSet);
    delElement(&newSet);
    delElement(&newSet);

//    addElement(&newSet, &newPoint);
//
//    if(elementSearch(&newSet, &thirdPoint)) {
//        puts("yes\n");
//    } else {
//        puts("no\n");
//    }

    resetSet(&newSet, filePath);
    saveSet(newSet, "..\\set2.txt");

    return 1;
}
