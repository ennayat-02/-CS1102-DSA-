#include <stdio.h>

int main() {
    int arr[11] = {10, 15, 20, 22, 25, 30, 35, 40, 45, 50};
    int n = 10;
    int new_element;


    printf("Enter the element to insert at the end of the array: ");
    scanf("%d", &new_element);

    arr[n] = new_element;


    n++;


    printf("Array after inserting the new element at the end:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

