#include "../Headers/SelectionSort.h"
#include "../Headers/SwapFunction.h"
#include "../../../System/Utils.h"





/** This function will take an array then it sort it with the selection sort algorithm.
 *
 * Time Complexity: worst: O(n ^ 2) , best: O (n ^ 2).
 * Space Complexity: O(1).
 *
 * @param arr the array pointer
 * @param length the length of the array
 * @param elemSize the size of the array elements in bytes
 * @param cmp the comparator function pointer
 */

void selectionSort(void *arr, int length, int elemSize, int (*cmp)(const void *, const void *)) {

    if (arr == NULL) {
        fprintf(stderr, NULL_POINTER_MESSAGE, "passed array", "selection sort");
        exit(NULL_POINTER);
    } else if (cmp == NULL) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "comparator function pointer", "selection sort");
        exit(INVALID_ARG);
    } else if (length < 0) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "array length", "selection sort");
        exit(INVALID_ARG);
    } else if (elemSize <= 0) {
        fprintf(stderr, INVALID_ARG_MESSAGE, "element size", "selection sort");
        exit(INVALID_ARG);
    }

    void *currentElement = NULL;

    for (int i = 0; i < length; i++) {
        currentElement = arr + i * elemSize; // the min or max element depends on if the sorting descending order or not
        for (int j = i; j < length; j++) {

            if ( cmp(currentElement, arr + j * elemSize ) > 0 )
                currentElement = arr + j * elemSize;

        }

        if (currentElement != arr + i * elemSize)
            swap(arr + i * elemSize, currentElement, elemSize);

    }


}