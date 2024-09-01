#include <stdio.h>

int main() {
    int arr[] = {10, 12, 18, 22, 26, 39, 36, 41, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 19;
    int left = 0;
    int right = size - 1;
    int found = 0;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            found = 1;
            break;
        } else if (arr[mid] > target) {
            right = mid - 1;
            continue; // Simulate the recursion going into the left subarray
        } else {
            left = mid + 1;
            continue; // Simulate the recursion going into the right subarray
        }
    }

    if (found) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in the array\n");
    }

    return 0;
}
