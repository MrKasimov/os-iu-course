#include <stdio.h>

// bubble_sort sorts int array in asceding order
void bubble_sort(int arr[], int length) {
    int i;
    for (i = 0; i < length - 1; i++) {
        int j;
        for (j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Test of bubble_sort function
int main(){
    int length;
    printf("Please input the length of array:\n");
    scanf("%d", &length);

    int arr[length];
    printf("Please list %d integers:\n", length);

    int i;
    for (i = 0; i < length; i++)
        scanf("%d", &arr[i]);

    bubble_sort(arr, length);

    printf("This is the result of bubble sort:\n");
    for (i = 0; i < length; i++)
        printf("%d ", arr[i]);
    return 0;
}
