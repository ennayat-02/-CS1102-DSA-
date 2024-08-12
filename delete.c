#include <stdio.h>

int main() {
    int pos;
    printf("Enter the position of the element to delete: ");
    scanf("%d", &pos);


    int arr[] = {10, 12, 18, 22, 26, 39, 36, 41, 45};
    int size = sizeof(arr) / sizeof(arr[0]);


    if (pos < 0 || pos >= size) {
        printf("Invalid position.\n");
        return 1;
    }

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[size - 1] = 0;


    printf("Updated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
