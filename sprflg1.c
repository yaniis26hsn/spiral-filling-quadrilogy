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
    int arr[n*m] ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("input the elem situated in line %d and colmn %d : ",i+1,j+1) ;
            scanf("%d",&t[i][j]);
            printf("\n") ;
        }
    }
    int a = 0;
    int min = (m < n) ? m : n;
    int b = (min % 2 == 0) ? (min / 2) : ((min + 1) / 2);

    for (int i = 0; i < b; i++) {
        // Top row
        for (int j = i; j <= m - i - 1; j++) {
            arr[a] = t[i][j] ;
            a++ ;
        }
        // Right column
        for (int j = i + 1; j <= n - 1 - i; j++) {
            arr[a] = t[j][m - 1 - i] ;
            a++ ;
        }
        // Bottom row
        for (int j = m - 2 - i; j >= i; j--) {
            arr[a] = t[n - 1 - i][j] ;
            a++ ;
        }
        // Left column
        for (int j = n - i - 2; j > i; j--) {
            arr[a] = t[j][i] ;
            a++ ;
        }
    }

    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // and now printing the vector
    for (int i = 0; i < n; i++) {
        printf("%d  ",arr[i]) ;
    }

    return 0;
}
