#include <stdio.h>
int main() {
    int a[10][10], b[10][10], sum[10][10];
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements of Matrix A:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements of Matrix B:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Resultant Matrix (A + B):\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}



