
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// Function to produce the rounded matrix
void produceRoundedMatrix(int n, float matrix[n][n]) {
    int i, j;
    int matrix1[n][n];

    // Iterate through each element in the matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          matrix1[i][j] = (int)round(matrix[i][j]);
        }
    }

    
    printf("Rounded Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n for the n x n matrix: ");
    scanf("%d", &n);

    float matrix[n][n];
    printf("Enter the elements of the matrix row-wise:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // scanf("%f", &matrix[i][j]);
            matrix[i][j] = ((float)(rand()) / (float)(rand()))*3.0;
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    
    clock_t starttime = clock();
    produceRoundedMatrix(n, matrix);
    clock_t endtime = clock();
    float timetaken = (int)(endtime - starttime) * 1000000 / CLOCKS_PER_SEC;
    
    printf("\nTime taken: %.02f micro-second",timetaken);

    return 0;
}
