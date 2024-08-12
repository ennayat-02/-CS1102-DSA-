#include <stdio.h>

int main() {
    int pos,i,value;
    int arr[] = {10,12,18,22,26,39,36,41,45};


    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &pos);
    printf("Enter the value to be inserted: ");
    scanf("%d", &value);


    for(int i = 9; i >= pos; i--) {
        arr[i] = arr[i-1];
    }


    arr[pos-1] = value;


    i++;


    printf("Array after insertion: ");
    for(int i = 0; i <=10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
