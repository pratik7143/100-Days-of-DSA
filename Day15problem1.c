#include <stdio.h>
int main() {
    int n, i, j;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    int sum = 0;
    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        sum += matrix[i][i];
        if(i != n - i - 1)   
            sum += matrix[i][n - i - 1];
    }
    printf("Sum of diagonals = %d\n", sum);
    return 0;
}








