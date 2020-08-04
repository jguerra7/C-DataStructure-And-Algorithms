#include "ListsTest/VectorTest/VectorTest.h"
#include "ListsTest/ArrayListTest/ArrayListTest.h"
#include "LinkedListsTest/LinkedListTest/LinkedListTest.h"
#include "LinkedListsTest/DoublyLinkedListTest/DoublyLinkedListTest.h"
#include "StacksTest/StackTest/StackTest.h"
#include "StacksTest/DLinkedListStackTest/DLinkedListStackTest.h"
#include "QueuesTest/QueueTest/QueueTest.h"
#include "QueuesTest/StackQueueTest/StackQueueTest.h"
#include "QueuesTest/LinkedListQueueTest/LinkedListQueueTest.h"
#include "QueuesTest/PriorityQueueTest/PriorityQueueTest.h"
#include "DequesTest/DequeTest/DequeTest.h"
#include "DequesTest/DoublyLinkedListDequeTest/DoublyLinkedListDequeTest.h"
#include "MatricesTest/MatrixTest/MatrixTest.h"
#include "StringsTest/StringTest/StringTest.h"
#include "TablesTest/HashMapTest/HashMapTest.h"
#include "TablesTest/DounlyLinkedListHashMapTest/DoublyLinkedListHashMapTest.h"
#include "TablesTest/HashSetTest/HashSetTest.h"
#include "GraphsTest/DirectedGraphTest/DirectedGraphTest.h"

int main(void) {

    vectorUnitTest();
    arrayListUnitTest();
    linkedListUnitTest();
    doublyLinkedListUnitTest();
    stackUnitTest();
    doublyLinkedListStackUnitTest();
    queueUnitTest();
    stackQueueUnitTest();
    linkedListQueueUnitTest();
    priorityQueueUnitTest();
    dequeUnitTest();
    doublyLinkedListDequeUnitTest();
    matrixUnitTest();
    stringUnitTest();
    hashMapUnitTest();
    doublyLinkedListHashMapUnitTest();
    hashSetUnitTest();
    directedGraphUnitTest();

    return 0;

}

