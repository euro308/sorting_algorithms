#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include <time.h>

void print_array(int *array, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {

    int cisla[] = {2, 4, 1, 3, 5, 4, 2, 1, 3};

    print_array(cisla, 9);
    bubble_sort(cisla, 9);
    print_array(cisla, 9);

    return 0;
}
