#include <stdio.h>

int main() {
    int a, i, j, k, m, n, mxn, mxm, x, y, M, N, max, c, s, veclen,tmpInp;
    printf("input the vect's lengs: ",&veclen);
    scanf("%d", &veclen);

    printf("Dims man: ");
    scanf("%d %d", &n, &m);

    printf("Coords man: ");
    scanf("%d %d", &x, &y);

    int t[n][m];

    mxm = (y > m - 1 - y) ? y : m - 1 - y;
    mxn = (x > n - 1 - x) ? x : n - 1 - x;
    max = (mxn > mxm) ? mxn : mxm;

    M = 2 * max + m;
    N = 2 * max + n;

    int u[N][M];

    // Initialize matrix with -2 and mark center region with 0
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (i >= max && i <= n + max - 1 && j >= max && j <= max + m - 1)
                u[i][j] = 0;
            else
                u[i][j] = -2;
        }
    }

    a = 0;
    s = 1;
    i = x + max;
    j = y + max;

    while (a <= n * m) {
        if (s % 2 != 0) {
            for (c = 0; c < s; c++) {
                if (u[i][j] == 0 && a<veclen ) {
                    scanf("%d",&tmpInp) ;
                    u[i][j] = tmpInp;
                    a++ ;
                }else if(u[i][j] == 0){
                    u[i][j] = -1 ;
                }
                j++;
            }
            for (c = 0; c < s; c++) {
                if (u[i][j] == 0 && a < veclen ) {
                    scanf("%d",&tmpInp) ;
                    u[i][j] = tmpInp;
                    a++ ;
                }else if(u[i][j] == 0){
                    u[i][j] = -1 ;
                }
                i++;
            }
        } else {
            for (c = 0; c < s; c++) {
                if (u[i][j] == 0 && a<veclen ) {
                    scanf("%d",&tmpInp) ;
                    u[i][j] = tmpInp;
                    a++ ;
                }else if(u[i][j] == 0){
                    u[i][j] = -1 ;
                }
                j--;
            }
            for (c = 0; c < s; c++) {
                if (u[i][j] == 0 && a<veclen ) {
                    scanf("%d",&tmpInp) ;
                    u[i][j] = tmpInp;
                    a++ ;
                }else if(u[i][j] == 0){
                    u[i][j] = -1 ;
                }
                i--;
            }
        }
        s++;
    }

    // Print the result matrix
    int arr[n][m] ;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {

            if (u[i][j] != -2){
                arr[i][j]= u[i][j] ;
                printf("%2d  ",arr[i][j]) ;
            }
            
        }
        printf("\n");
    }

    return 0;
}
