//
//  main.cpp
//  nypc_exp
//
//  Created by 엄서훈 on 2018. 8. 24..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>
#define max(a, b) a<b?b:a
const int Ls = 10000 + 5;
const int Lc = 1000 + 5;
int S, N;
int C[Lc][2], D[Lc][Ls], Path[Lc], Pc;
// C[x][0] : Stemina, C[x][1] : Exp

int path(int i, int j) { // i : content, j : used stemina
    if (i == 0) return 0;
    if (D[i][j] == D[i-1][j]) {
        return path(i-1, j);
    }
    else {
        Path[Pc++] = i;
        return path(i-1, j-C[i][0]) + 1;
    }
}

int main() {
    int i, j;
    // input
    scanf("%d %d", &S, &N);
    for (i=1; i<=N; ++i) {
        scanf("%d %d", &C[i][0], &C[i][1]);
    }
    
    // processing (dynamic programming)
    for (i=1; i<=N; ++i) { // content
        for (j=0; j<=S; ++j) { // stemina
            D[i][j]=D[i-1][j];
            if(j-C[i][0] >= 0) {
                D[i][j] = max(D[i][j], D[i-1][j-C[i][0]]+C[i][1]);
            }
        }
    }
    
    //output
    printf("%d\n", D[N][S]);
    printf("%d\n", path(N, S));
    for (i=Pc-1; i>=0; --i) {
        printf ("%d ", Path[i]);
    }
    printf("\n");
    return 0;
}
