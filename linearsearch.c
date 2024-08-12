#include <stdio.h>

int main() {
    int i, mid, target, flag, h;
    target = 22;
    flag = 0;
    char arr[10] = {10, 15, 20, 22, 25, 30, 35, 40, 45, 50};  // Assuming array is sorted

    i = 0;
    h = 9;

    while (i <= h) {
        mid = (i + h) / 2;

        if (arr[mid] == target) {
            printf("Number found at index %d\n", mid);
            flag = 1;
            break;
        }

        if (arr[mid] < target) {
            i = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    if (flag == 0) {
        printf("Number not found\n");
    }

    return 0;
}
