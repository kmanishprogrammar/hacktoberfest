#include <stdio.h>
#include <stdlib.h>

int** transpose(int** mat1, int r, int c, int t);

int main() {
    int r, c, t;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("Enter the number of elements: ");
    scanf("%d", &t);

    int** mat1 = (int**)calloc(t + 1, sizeof(int*));

    for (int i = 0; i <= t; i++) {
        mat1[i] = (int*)calloc(3, sizeof(int));
    }

    mat1[0][0] = r;
    mat1[0][1] = c;
    mat1[0][2] = t;

    for (int i = 1; i <= t; i++) {
        printf("Enter the row, column, and element for element %d: ", i);
        scanf("%d %d %d", &mat1[i][0], &mat1[i][1], &mat1[i][2]);
    }

    int** mat2 = transpose(mat1, r, c, t);

    printf("Original matrix:\n");
    for (int i = 0; i <= t; i++) {
        printf("%d %d %d\n", mat1[i][0], mat1[i][1], mat1[i][2]);
    }

    printf("Transposed matrix:\n");
    for (int i = 0; i <= t; i++) {
        printf("%d %d %d\n", mat2[i][0], mat2[i][1], mat2[i][2]);
    }

    for (int i = 0; i <= t; i++) {
        free(mat1[i]);
        free(mat2[i]);
    }
    free(mat1);
    free(mat2);

    return 0;
}

int** transpose(int** mat1, int r, int c, int t) {
    int** mat2 = (int**)calloc(t + 1, sizeof(int*));

    for (int i = 0; i <= t; i++) {
        mat2[i] = (int*)calloc(3, sizeof(int));
    }

    mat2[0][0] = c;
    mat2[0][1] = r;
    mat2[0][2] = t;

    int k = 1;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < c; j++) {
            if (mat1[i][1] == j) {
                mat2[k][0] = mat1[i][1];
                mat2[k][1] = mat1[i][0];
                mat2[k][2] = mat1[i][2];
                k++;
            }
        }
    }
    return mat2;
}
