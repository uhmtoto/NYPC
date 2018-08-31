//
//  main.cpp
//  nypc_grid
//
//  Created by 엄서훈 on 2018. 8. 24..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>
const int LM = 300;
int N, mat[LM][LM], smat[LM][LM];

inline void swap(int &a, int &b) {
    int tmp = a;
    a = b, b = tmp;
}

void mat_swap() {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            mat[i][j] = smat[i][j];
        }
    }
}

void sort() {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N-1; ++j) {
            if(mat[i][j] > mat[i][j+1]) {
                swap(mat[i][j], mat[i][j+1]);
            }
        }
    }
}

void rotate() {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            smat[N-j-1][i] = mat[i][j];
        }
    }
    mat_swap();
}

int main() {
    int T, i, j;
    scanf("%d %d", &N, &T);
    for (i=0; i<N; ++i) {
        for (j=0; j<N; ++j) {
            scanf("%d", mat[i]+j);
        }
    }
    while (T--) {
        sort();
        rotate();
    }
    for (i=0; i<N; ++i) {
        for (j=0; j<N; ++j) {
            printf("%d ", mat[i][j]);
        }
        puts("");
    }
    return 0;
}
