#include "HPriorityQueue.h"
#include "../../System/Utils.h"
#include "../../Unit Test/CuTest/CuTest.h"
#include "../Trees/Headers/BinaryHeap.h"
#include "../Trees/Sources/BinaryHeap.c"




/** This function will allocate a new heap priority queue then it will return its pointer.
 *
 * @param freeFn the free function pointer, that will be called to free the queue items
 * @param cmp the comparator function pointer, that will be called to compare the queue items
 * @return it will return the new allocated queue pointer
 */

HPriorityQueue *hPriorityQueueInitialization(void (*freeFn)(void *), int (*cmp)(const void *, const void *)) {

    if (freeFn == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = INVALID_ARG;
        return NULL;
#else
        fprintf(stderr, INVALID_ARG_MESSAGE, "free function pointer", "heap priority queue data structure");
        exit(INVALID_ARG);
#endif
    } else if (cmp == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = INVALID_ARG;
        return NULL;
#else
        fprintf(stderr, INVALID_ARG_MESSAGE, "comparator function pointer", "heap priority queue data structure");
        exit(INVALID_ARG);
#endif
    }

    HPriorityQueue *queue = (HPriorityQueue *) malloc(sizeof(HPriorityQueue));
    if (queue == NULL) {
        fprintf(stderr, FAILED_ALLOCATION_MESSAGE, "queue", "heap priority queue data structure");
        exit(FAILED_ALLOCATION);
    }

    queue->heap = binaryHeapInitialization(freeFn, cmp);

    return queue;

}





/** This function will insert the passed item in the queue.
 *
 * @param queue the queue pointer
 * @param item the new item pointer
 */

void hpQueueEnqueue(HPriorityQueue *queue, void *item) {

    if (queue == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = NULL_POINTER;
        return;
#else
        fprintf(stderr, NULL_POINTER_MESSAGE, "queue", "heap priority queue data structure");
        exit(NULL_POINTER);
#endif

    } else if (item == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = INVALID_ARG;
        return;
#else
        fprintf(stderr, INVALID_ARG_MESSAGE, "item pointer", "heap priority queue data structure");
        exit(INVALID_ARG);
#endif
    }

    binaryHeapInsert(queue->heap, item);

}




/** This function will insert all the passed array items in the queue.
 *
 * @param queue the queue pointer
 * @param items the new items array pointer
 * @param length the length of the new items array
 */
void hpQueueEnqueueAll(HPriorityQueue *queue, void *items, int length) {

    if (queue == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = NULL_POINTER;
        return;
#else
        fprintf(stderr, NULL_POINTER_MESSAGE, "queue", "heap priority queue data structure");
        exit(NULL_POINTER);
#endif

    } else if (items == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = INVALID_ARG;
        return;
#else
        fprintf(stderr, INVALID_ARG_MESSAGE, "items array pointer", "heap priority queue data structure");
        exit(INVALID_ARG);
#endif
    }

    binaryHeapInsertAll(queue->heap, items, length);

}




/** This function will remove the first item from the queue,
 * then it will return it.
 *
 * @param queue the queue pointer
 * @return it will return the first item in the queue
 */

void *hpQueueDequeue(HPriorityQueue *queue) {

    if (queue == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = NULL_POINTER;
        return NULL;
#else
        fprintf(stderr, NULL_POINTER_MESSAGE, "queue", "heap priority queue data structure");
        exit(NULL_POINTER);
#endif

    } else if (hpQueueIsEmpty(queue)) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = EMPTY_DATA_STRUCTURE;
        return NULL;
#else
        fprintf(stderr, EMPTY_DATA_STRUCTURE_MESSAGE, "heap priority queue data structure");
        exit(EMPTY_DATA_STRUCTURE);
#endif

    }

    return binaryHeapDeleteRootWtoFr(queue->heap);

}




/** This function will return the first item in the queue without removing it from the queue.
 *
 * @param queue the queue pointer
 * @return it will return the first item in the queue
 */

void *hpQueuePeek(HPriorityQueue *queue) {

    if (queue == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = NULL_POINTER;
        return NULL;
#else
        fprintf(stderr, NULL_POINTER_MESSAGE, "queue", "heap priority queue data structure");
        exit(NULL_POINTER);
#endif

    } else if (hpQueueIsEmpty(queue)) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = EMPTY_DATA_STRUCTURE;
        return NULL;
#else
        fprintf(stderr, EMPTY_DATA_STRUCTURE_MESSAGE, "heap priority queue data structure");
        exit(EMPTY_DATA_STRUCTURE);
#endif

    }

    return *queue->heap->arr;

}




/** This function will return the number of items in the queue.
 *
 * @param queue the queue pointer
 * @return it will return the number of items in the queue
 */

int hpQueueGetLength(HPriorityQueue *queue) {

    if (queue == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = NULL_POINTER;
        return -1;
#else
        fprintf(stderr, NULL_POINTER_MESSAGE, "queue", "heap priority queue data structure");
        exit(NULL_POINTER);
#endif

    }

    return binaryHeapGetSize(queue->heap);

}




/** This function will check if the queue is empty or not,
 * and if it was the function will return one (1),
 * other wise it will return zero (0).
 *
 * @param queue the queue pointer
 * @return it will return 1 if the queue was empty, other wise it will return 0
 */

int hpQueueIsEmpty(HPriorityQueue *queue) {

    if (queue == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = NULL_POINTER;
        return -1;
#else
        fprintf(stderr, NULL_POINTER_MESSAGE, "queue", "heap priority queue data structure");
        exit(NULL_POINTER);
#endif

    }

    return binaryHeapIsEmpty(queue->heap);

}




/** This function will return a double void array that contains the queue items.
 *
 * Note: the array will be sorted.
 *
 * @param queue the queue pointer
 * @return it will return a double void array pointer, that contains the queue items
 */

void **hpQueueToArray(HPriorityQueue *queue) {

    if (queue == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = NULL_POINTER;
        return NULL;
#else
        fprintf(stderr, NULL_POINTER_MESSAGE, "queue", "heap priority queue data structure");
        exit(NULL_POINTER);
#endif

    }

    void **arr =  binaryHeapToArray(queue->heap);

    int length = hpQueueGetLength(queue);

    while (length-- > 0) {
        binaryHeapSwap(arr, 0, length);
        binaryHeapDown(arr, 0, length, queue->heap->cmp);
    }

    return arr;

}




/** This function will clear the queue and free all it's items,
 * without freeing the queue itself.
 *
 * @param queue the queue pointer
 */

void clearHPQueue(HPriorityQueue *queue) {

    if (queue == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = NULL_POINTER;
        return;
#else
        fprintf(stderr, NULL_POINTER_MESSAGE, "queue", "heap priority queue data structure");
        exit(NULL_POINTER);
#endif

    }

    clearBinaryHeap(queue->heap);

}




/** This function will destroy and free the queue and it's items.
 *
 * @param queue the queue pointer
 */

void destroyHPQueue(HPriorityQueue *queue) {

    if (queue == NULL) {
#ifdef C_DATASTRUCTURES_ERRORSTESTSTRUCT_H
        ERROR_TEST->errorCode = NULL_POINTER;
        return;
#else
        fprintf(stderr, NULL_POINTER_MESSAGE, "queue", "heap priority queue data structure");
        exit(NULL_POINTER);
#endif

    }

    destroyBinaryHeap(queue->heap);

    free(queue);

}