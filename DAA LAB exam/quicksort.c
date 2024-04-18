#include <stdio.h>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low ;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

// Function to perform Quick Sort on the array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    // Take input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Take input for the elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array: ");
    printArray(arr, n);

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
