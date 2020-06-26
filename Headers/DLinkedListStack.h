#ifndef C_DATASTRUCTURES_DLINKEDLISTSTACK_H
#define C_DATASTRUCTURES_DLINKEDLISTSTACK_H

#include "DoublyLinkedList.h"

typedef struct DLinkedListStack {

    DoublyLinkedList *linkedList;

} DLinkedListStack;


DLinkedListStack *dlStackInitialization(int sizeOfType);


void dlStackPush(DLinkedListStack *stack, void *item);


void *dlStackPop(DLinkedListStack *stack);


int dlStackIsEmpty(DLinkedListStack *stack);


void *dlStackPeek(DLinkedListStack *stack);


void clearDLStack(DLinkedListStack *stack);


void destroyDLStack(DLinkedListStack *stack);


#endif //C_DATASTRUCTURES_DLINKEDLISTSTACK_H