#include <stdio.h>


void rotate(int mat[][3], int N) {
    int temp[N][N];


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[j][N - i - 1] = mat[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = temp[i][j];
        }
    }
}
void print(int mat[][3], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int N = 3;
    int mat[N][N];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int degrees;
    printf("Enter the degrees to rotate in the multiples of 90: ");
    scanf("%d", &degrees);
    int rotations = degrees / 90;
    for (int i = 0; i < rotations; i++) {
        rotate(mat, N);
    }
    printf("Rotated matrix is:\n");
    print(mat, N);


    return 0;
}
