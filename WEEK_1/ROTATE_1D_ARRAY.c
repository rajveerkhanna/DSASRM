#include <stdio.h>


void revArr(int arr[], int low, int high) {
    while (low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}


void rotate(int arr[], int n, int d) {
    revArr(arr, 0, d - 1);
    revArr(arr, d, n - 1);
    revArr(arr, 0, n - 1);
}
void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int n;


    printf("Enter the size of the array: ");
    scanf("%d", &n);


    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int d;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &d);


    rotate(arr, n, d);


    printf("Rotated array is: ");
    print(arr, n);


    return 0;
}
