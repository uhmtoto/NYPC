//
//  main.cpp
//  nypc_floodit
//
//  Created by 엄서훈 on 2018. 8. 27..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>
const int LM = 1005;
bool chk[LM][LM];
int N, K, L[LM], mat[LM][LM];
int ii[] = {-1, 0, 1, 0}, jj[] = {0, 1, 0, -1};

void init() {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            chk[i][j] = false;
        }
    }
}

void proc(int i, int j, int k, int v) {
    if (i >= N || j >= N || i < 0 || j < 0) return;
    if (chk[i][j] || mat[i][j] != k) return;
    mat[i][j] = v, chk[i][j] = true;
    for (int p=0; p<4; ++p) {
        proc(i+ii[p], j+jj[p], k, v);
    }
}

int count(int i, int j) {
    if (i >= N || j >= N || i < 0 || j < 0) return 0;
    if (mat[i][j] != mat[0][0] || chk[i][j]) return 0;
    int ret=1;
    chk[i][j] = true;
    for (int k=0; k<4; ++k) {
        ret += count(i+ii[k], j+jj[k]);
    }
    return ret;
}

int main() {
    int i, j;
    scanf("%d %d", &N, &K);
    for (i=0; i<K; ++i) {
        scanf("%d", &L[i]);
    }
    for (i=0; i<N; ++i) {
        for (j=0; j<N; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (i=0; i<K; ++i) {
        proc(0, 0, mat[0][0], L[i]);
        init();
    }
    printf("%d\n", count(0, 0));
    return 0;
}
