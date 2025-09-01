#include <stdio.h>
#include <stdlib.h>


void combine(int arr[], int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int *leftArr = (int*)malloc(leftSize * sizeof(int));
    int *rightArr = (int*)malloc(rightSize * sizeof(int));

   
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    
    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftSize) arr[k++] = leftArr[i++];
    while (j < rightSize) arr[k++] = rightArr[j++];

    free(leftArr);
    free(rightArr);
}


void mergeSortIterative(int arr[], int n) {
    for (int size = 1; size < n; size *= 2) {
        for (int start = 0; start < n - 1; start += 2 * size) {
            int mid = start + size - 1;
            int end = (start + 2 * size - 1 < n - 1) ? (start + 2 * size - 1) : (n - 1);

            if (mid < end) {
                combine(arr, start, mid, end);
            }
        }
    }
}


void showArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    // 🔹 Fixed input array
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    showArray(arr, n);

    mergeSortIterative(arr, n);

    printf("After sorting:\n");
    showArray(arr, n);

    return 0;
}

