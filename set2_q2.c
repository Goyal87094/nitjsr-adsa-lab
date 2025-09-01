#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int left, right, step;
} Task;


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}


void mergeSortIterative(int arr[], int n) {
    Task stack[2 * n];  
    int top = -1;


    stack[++top] = (Task){0, n - 1, 0};

    while (top >= 0) {
        Task current = stack[top--];
        int left = current.left, right = current.right, step = current.step;

        if (left >= right) continue;  

        int mid = left + (right - left) / 2;

        if (step == 0) {
           
            stack[++top] = (Task){left, right, 1};

           
            stack[++top] = (Task){mid + 1, right, 0};
            stack[++top] = (Task){left, mid, 0};
        } else {
            
            merge(arr, left, mid, right);
        }
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {34,21,13,76,43};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    mergeSortIterative(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;

}
