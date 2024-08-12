int main() {
    int arr[] = {10,12,18,22,26,39,36,41,45};
    int i;
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 19;
    int left = 0;
    int right = size - 1;
    int found = 0;
    int result = -1;

    for(i=0;left <= right;i++) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            found = 1;
            break;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in the array\n");
    }

    return 0;
}
