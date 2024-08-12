#include <stdio.h>

int main() {
    int arr[14] = {10, 12, 18, 22, 26, 39, 36, 41, 45};
    int size1 = 9;

    int b[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(b) / sizeof(b[0]);

    for (int i = 0; i < size2; i++) {
        arr[size1 + i] = b[i];
    }

    printf("Merged array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
