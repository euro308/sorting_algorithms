#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>

int number_of_sorts = 0;

void bogo_sort(int *array, int size) {
    int temp[size];
    bool swapped[size];
    bool sorted = true;
    int i = 0;

    while (i < size) {
        int random_selected = rand() % size;

        if (!swapped[random_selected]) {
            temp[i] = array[random_selected];
            swapped[random_selected] = true;
            i++;
        }
    }

    // Set the array to be the result from the Bogo sort
    for (int j = 0; j < size; j++) {
        array[j] = temp[j];
    }

    // Check if array is correctly sorted
    for (int k = 1; k < size; k++) {
        if (array[k - 1] > array[k]) {
            sorted = false;
        }
    }

    if (sorted) {
        printf("The sorted array is as follows: ");
        for (int l = 0; l < size; l++) {
            printf("%d ", array[l]);
        }
        printf("\n");
        number_of_sorts++;
        printf("Sorts: %d\n", number_of_sorts);
    } else {
        number_of_sorts++;
        bogo_sort(array, size);
    }
}

void selection_sort(int *array, int size) {
    for(int currentIndex = 0; currentIndex < size - 1; currentIndex++) {
        // Výběr nejmenšího čísla
        int minIndex = currentIndex;

        for (int i = currentIndex; i < size; i++) {

            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }

        // Updatování arraye (prohození našeho nejmenšího čísla s prvním číslem v poli)
            int temp = array[currentIndex];
            array[currentIndex] = array[minIndex];
            array[minIndex] = temp;
    }
}

bool compare_arrays(int *array1, int *array2, int size) {
    for (int i = 0; i < size; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
        return true;
}

void bubble_sort(int *array, int size) {
    int temp[size];
    int cycles = 0;

    while (!compare_arrays(array, temp, size)) {
        // Nastavit temp jako náš array
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }

        for (int j = 0; j < size; j++) {

            if (array[j] > array[j+1]) {
                int tempNum = array[j+1];
                array[j+1] = array[j];
                array[j] = tempNum;
            }
        }
        cycles++;
    }
    printf("\nBubble sort cycles: %d\n", cycles);
}
