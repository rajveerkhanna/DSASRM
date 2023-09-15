#include <stdio.h>
void merge(int arr[], int l, int m, int r) {
int int int
int for for
i, j, k;
n1 = m - l + 1; n2 = r - m;
L[n1], R[n2];
(i = 0; i < n1; i++) L[i] = arr[l + i];
(j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
i =
j =
k =
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
0; 0; l;
arr[k] =
i++; } else {
arr[k] =
j++; }
k++; }
L[i]; R[j];
while (i < n1) { arr[k] = L[i];
i++;
k++; }
while (j < n2) { arr[k] = R[j];
j++;
k++; }
}
void mergeSort(int arr[], int l, int r) { if (l < r) {
int m = l + (r - l) / 2;
mergeSort(arr, l, m); mergeSort(arr, m + 1, r);

  merge(arr, l, m, r); }
}
int main() {
//taking an example array
int arr[] = {12, 11, 13, 5, 6, 7};
int arr_size = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < arr_size; i++) printf("%d ", arr[i]);
mergeSort(arr, 0, arr_size - 1);
printf("\n");
for (int i = 0; i < arr_size; i++)
printf("%d ", arr[i]); return 0;
}
