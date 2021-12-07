#include <stdbool.h>
#include <time.h>
#include <stdio.h>

double time_taken;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], int n)
{
    int switched, pass, i;
    clock_t initial, final;

    initial = clock();                                   // initial process time
    switched = true;                                    // check if array swaped or not

    for (pass = 0; pass < n - 1 && switched; pass++)    // if no swaps it stops working
    {
        switched = false;
        for (i = 0; i < n - 1 - pass; i++)
        {
            if (A[i] > A[i + 1])                        // compare adjacent array elements    
            {
                switched = true;                        // states elements have been swapped
                swap(&A[i], &A[i + 1]);
            }
        }
    }

    final = clock();                                    // final processor time
    
    time_taken = (double)(final - initial) / CLOCKS_PER_SEC; // total time taken by the sorting 
}

int main()
{
    int n = 1000, i;
    // printf("Enter the size of array: ");
    // scanf("%d", &n);
    // // n = 100;
    // int A[n];
    // printf("Enter elements of array: \n");
    // for (i = 0; i < n; i++)
    // {
    //     scanf("%d", &A[i]);
    // }
    int A[]= {47, 54, 36, 31, 41, 100, 44, 14, 9, 71, 97, 51, 51, 69, 62, 22, 9, 37, 69, 16, 74, 48, 29, 71, 8, 89, 76, 53, 32, 83, 87, 30, 50, 36, 56, 85, 57, 19, 70, 34, 80, 80, 84, 48, 45, 22, 21, 4, 14, 19, 56, 51, 32, 52, 53, 3, 84, 90, 79, 18, 63, 80, 78, 66, 59, 17, 6, 100, 81, 23, 62, 66, 86, 96, 47, 39, 40, 2, 92, 
97, 59, 21, 31, 25, 19, 88, 89, 43, 52, 62, 27, 22, 12, 54, 24, 15, 63, 48, 82, 65, 1, 94, 65, 48, 2, 26, 25, 10, 60, 77, 11, 71, 43, 80, 34, 66, 42, 42, 29, 53, 52, 33, 65, 76, 45, 70, 63, 54, 76, 44, 51, 36, 68, 35, 75, 45, 21, 42, 14, 88, 74, 9, 9, 4, 66, 72, 45, 22, 78, 63, 47, 34, 65, 83, 91, 37, 59, 81, 50, 62, 93, 65, 76, 83, 91, 15, 71, 71, 6, 3, 12, 5, 89, 14, 92, 79, 49, 8, 62, 41, 23, 82, 14, 9, 66, 46, 91, 1, 62, 84, 24, 66, 98, 85, 84, 24, 4, 72, 46, 
91, 71, 40, 78, 99, 66, 75, 9, 18, 34, 14, 9, 80, 96, 42, 91, 54, 100, 13, 11, 55, 63, 69, 21, 30, 61, 54, 45, 75, 17, 45, 85, 23, 86, 89, 32, 19, 62, 11, 66, 82, 6, 67, 20, 71, 54, 44, 3, 63, 18, 97, 92, 32, 4, 48, 42, 87, 11, 43, 52, 35, 3, 89, 70, 76, 87, 83, 0, 66, 28, 45, 38, 49, 19, 48, 83, 69, 42, 30, 39, 12, 47, 50, 75, 84, 94, 84, 40, 82, 79, 98, 45, 71, 7, 19, 23, 44, 5, 93, 41, 96, 9, 76, 19, 54, 19, 50, 91, 17, 82, 18, 46, 56, 3, 100, 23, 100, 67, 83, 
19, 36, 2, 39, 3, 28, 54, 98, 87, 7, 6, 24, 88, 41, 19, 11, 94, 15, 47, 0, 72, 5, 58, 1, 23, 88, 17, 2, 50, 70, 47, 6, 87, 42, 56, 64, 24, 1, 41, 84, 15, 52, 12, 40, 41, 70, 24, 26, 81, 69, 33, 35, 80, 46, 31, 43, 69, 87, 13, 91, 91, 70, 70, 87, 26, 73, 57, 41, 78, 0, 32, 24, 86, 60, 2, 39, 86, 100, 97, 79, 66, 1, 60, 1, 42, 1, 8, 97, 88, 12, 0, 6, 71, 30, 3, 96, 94, 20, 8, 19, 20, 77, 10, 1, 32, 52, 16, 41, 32, 86, 89, 62, 86, 28, 63, 43, 2, 62, 18, 74, 85, 70, 81, 72, 75, 29, 7, 30, 9, 41, 11, 21, 73, 60, 72, 27, 47, 2, 85, 15, 73, 98, 42, 63, 54, 73, 47, 81, 8, 37, 83, 40, 99, 13, 28, 62, 85, 44, 0, 13, 82, 58, 48, 14, 46, 67, 40, 48, 33, 79, 41, 14, 89, 4, 56, 28, 66, 36, 92, 15, 97, 43, 34, 75, 26, 54, 85, 88, 100, 90, 15, 16, 17, 28, 43, 88, 50, 43, 74, 16, 70, 50, 22, 80, 43, 24, 0, 43, 8, 14, 4, 83, 91, 34, 21, 24, 11, 85, 78, 12, 73, 37, 76, 4, 77, 16, 48, 56, 11, 80, 6, 66, 5, 82, 63, 67, 26, 93, 72, 92, 32, 3, 63, 60, 70, 93, 66, 7, 74, 52, 44, 14, 14, 45, 41, 67, 90, 39, 18, 100, 100, 76, 32, 23, 78, 29, 9, 6, 6, 58, 78, 46, 17, 91, 89, 77, 6, 2, 98, 87, 51, 86, 38, 96, 49, 69, 100, 46, 30, 40, 94, 7, 12, 51, 77, 77, 99, 66, 15, 63, 33, 18, 41, 67, 57, 31, 31, 32, 14, 92, 21, 81, 67, 64, 33, 25, 96, 98, 21, 18, 17, 40, 64, 92, 42, 13, 95, 26, 83, 44, 51, 71, 77, 85, 66, 39, 6, 61, 64, 88, 62, 0, 19, 9, 13, 75, 56, 98, 37, 50, 56, 42, 14, 8, 84, 69, 0, 25, 41, 57, 50, 35, 68, 2, 44, 57, 78, 9, 35, 79, 89, 87, 55, 62, 17, 16, 28, 50, 97, 7, 67, 34, 70, 66, 80, 45, 37, 12, 13, 32, 75, 80, 11, 16, 99, 91, 83, 1, 47, 18, 31, 24, 6, 60, 32, 94, 73, 81, 93, 95, 96, 84, 14, 9, 43, 8, 99, 34, 44, 48, 62, 68, 49, 14, 100, 60, 74, 90, 50, 97, 89, 98, 26, 47, 54, 42, 95, 80, 66, 93, 45, 
21, 90, 67, 24, 38, 27, 5, 51, 71, 82, 62, 44, 46, 17, 99, 28, 15, 7, 98, 35, 1, 53, 25, 73, 87, 56, 83, 96, 49, 53, 94, 83, 70, 68, 52, 79, 61, 99, 27, 6, 
76, 64, 66, 95, 41, 41, 37, 70, 33, 96, 28, 58, 29, 45, 35, 10, 33, 46, 54, 30, 41, 40, 84, 81, 24, 73, 27, 64, 2, 50, 18, 78, 72, 44, 50, 92, 67, 97, 73, 51, 100, 50, 75, 88, 44, 91, 17, 56, 77, 82, 31, 24, 9, 26, 45, 44, 76, 68, 24, 3, 37, 83, 82, 85, 86, 14, 71, 47, 85, 70, 99, 15, 1, 54, 10, 11, 30, 20, 30, 74, 70, 75, 43, 64, 100, 91, 44, 61, 40, 16, 100, 7, 83, 33, 2, 55, 46, 63, 83, 63, 86, 32, 85, 26, 98, 70, 85, 48, 66, 90, 88, 96, 9, 24, 63, 21, 88, 34, 
9, 73, 32, 64, 79, 38, 0, 76, 87, 39, 11, 11, 20, 57, 89, 91, 35, 89, 10, 77, 16, 31, 17, 34, 3, 76, 20, 54, 96, 60, 8, 85, 60, 16, 28, 35, 38, 81, 93, 37, 
31, 96, 63, 16, 7, 13, 9, 91, 19, 73, 84, 69, 20, 49, 14, 78, 50, 16, 1, 43, 51, 75, 55, 72, 72, 97, 19, 3, 90, 33, 1, 64, 91, 56, 59, 27, 37, 47, 46, 63, 54, 31, 58};

    bubbleSort(A, n);

    printf("\nSorted items:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t", A[i]);
    }
    printf("\nTime taken to sort %d items = %lf sec", n, time_taken);
    return 0;
}