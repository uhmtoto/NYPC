//
//  main.cpp
//  nypc_block
//
//  Created by 엄서훈 on 2018. 8. 27..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>
const int LM = 1005;

int N, mat[LM][LM];
//mat : -1 -> unknown  -2 -> unable

int proc(int i, int j) {
    if (i == N-1 && mat[i][j] == -1) mat[i][j] = -2;
    if (mat[i][j] >= 0 || mat[i][j] == -2) return mat[i][j];
    int rev1 = proc(i+1, j), rev2 = proc(i+1, j+1);
    if (rev1 == -2 || rev2 == -2) mat[i][j] = -2;
    else mat[i][j] = (rev1 + rev2) % 100;
    return mat[i][j];
}

int main() {
    int i, j, rev;
    scanf("%d", &N);
    for (i=0; i<N; ++i) {
        for (j=0; j<=i; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (i=0; i<N; ++i) {
        for (j=0; j<=i; ++j) {
            rev = proc(i, j);
            printf("%d ", rev==-2 ? -1 : rev);
        }
        printf("\n");
    }
    return 0;
}
