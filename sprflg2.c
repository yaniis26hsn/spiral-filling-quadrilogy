#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int n, m;
    printf("Input the number of lines (rows) and then the number of columns: ");
    scanf("%d %d", &n, &m);

    int t[n][m];
    int a = 1;
    int min = (m < n) ? m : n;
    int b = (min % 2 == 0) ? (min / 2) : ((min + 1) / 2);

    for (int i = 0; i < b; i++) {
        // Top row
        for (int j = i; j <= m - i - 1; j++) {
            t[i][j] = a++;
        }
        // Right column
        for (int j = i + 1; j <= n - 1 - i; j++) {
            t[j][m - 1 - i] = a++;
        }
        // Bottom row
        for (int j = m - 2 - i; j >= i; j--) {
            t[n - 1 - i][j] = a++;
        }
        // Left column
        for (int j = n - i - 2; j > i; j--) {
            t[j][i] = a++;
        }
    }

    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
