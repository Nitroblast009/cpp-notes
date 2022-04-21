/*
    - Allocating memory on stack in literally just one CPU instruction (just move stack pointer to next address) and is fast and simple
    - Allocating memory to heap is a whole ordeal which can be costly; must also be manually deleted at end of program
 */
#include <iostream>
#include <string>

int* getArr() {
    int arr[20]; // The memory here is on the stack, meaning it gets destroyed by the end of this function
    return arr;
}

int main()
{
    int value = 5;          // Create new int in stack memory
    int arr[3] = {1, 2, 3}; // Pointer to stack memory

    int* arrPtr = getArr(); // Retuns pointer to deleted memory (cuz it was on the stack)

    int *heapValue = new int; // Create new int in heap memory (new keyword is usually used for heap memory)
    *heapValue = 5;
    int *heapArr = new int[3]; // Pointer to heap memory
    heapArr[0] = 1;            // Index pointer for arrays
    heapArr[1] = 2;
    heapArr[2] = 3;

    delete heapValue;
    delete[] heapArr; // Need to use delete[] to delete an entire array from memory
}