#include <stdio.h>

#define MAX 10

/* takes the elements of one matrix from the user */
void readMatrix(char name, int m[MAX][MAX], int r, int c) 
{
    int i, j;

    printf("Enter elements of matrix %c:\n", name);

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

/* prints one matrix in row and column form */
void printMatrix(int m[MAX][MAX], int r, int c) {
    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

/* ask rows and columns */
void readSize(char name, int *r, int *c) {
    do {
        printf("Enter rows and columns of matrix %c (1-%d): ", name, MAX);
        scanf("%d %d", r, c);

    } while (*r < 1 || *r > MAX || *c < 1 || *c > MAX);
}

/* matrix addition */
void add(int a[MAX][MAX], int b[MAX][MAX],
         int res[MAX][MAX], int r, int c) {

    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

/* matrix subtraction */
void subtract(int a[MAX][MAX], int b[MAX][MAX],
              int res[MAX][MAX], int r, int c) {

    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}

/* matrix multiplication */
void multiply(int a[MAX][MAX], int b[MAX][MAX],
              int res[MAX][MAX], int r1, int c1, int c2) {

    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            res[i][j] = 0;

            for (k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

/* matrix transpose */
void transpose(int a[MAX][MAX], int res[MAX][MAX],
               int r, int c) {

    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            res[j][i] = a[i][j];
        }
    }
}

int main(void) {

    int a[MAX][MAX], b[MAX][MAX], res[MAX][MAX];

    int r1, c1;
    int r2, c2;
    int choice;

    do {
        printf("\n--- Matrix Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            break;
        }

        if (choice >= 1 && choice <= 3) {

            readSize('A', &r1, &c1);
            readSize('B', &r2, &c2);

            if (choice != 3 && (r1 != r2 || c1 != c2)) {
                printf("Both matrices must have the same size.\n");
                continue;
            }

            if (choice == 3 && c1 != r2) {
                printf("Columns of A must be equal to rows of B.\n");
                continue;
            }

            readMatrix('A', a, r1, c1);
            readMatrix('B', b, r2, c2);

            if (choice == 1) {

                add(a, b, res, r1, c1);

                printf("A + B =\n");
                printMatrix(res, r1, c1);

            } else if (choice == 2) {

                subtract(a, b, res, r1, c1);

                printf("A - B =\n");
                printMatrix(res, r1, c1);

            } else {

                multiply(a, b, res, r1, c1, c2);

                printf("A x B =\n");
                printMatrix(res, r1, c2);
            }

        } else if (choice == 4) {

            readSize('A', &r1, &c1);
            readMatrix('A', a, r1, c1);

            transpose(a, res, r1, c1);

            printf("Transpose =\n");
            printMatrix(res, c1, r1);

        } else if (choice != 5) {

            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}