//
//  main.cpp
//  nypc_disease
//
//  Created by 엄서훈 on 2018. 8. 24..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
const int LM = 10e5 + 5;
int N, M;
bool D[LM];

struct data{
    int t, x, y;
    bool operator < (const data &r) const {
        return t == r.t ? x == r.x ? y < r.y : x < r.x : t < r.t;
    }
} R[2 * LM];

int main() {
    int i;
    bool k;
    D[1] = true;
    scanf("%d %d",&N, &M);
    for (i=0; i<M; ++i) {
        scanf("%d %d %d", &R[i].x, &R[i].y, &R[i].t);
        if(R[i].x > R[i].y) {
            std::swap(R[i].x, R[i].y);
        }
    }
    std::stable_sort(R, R+M);
    for (i=0; i<M; ++i) {
        k = D[R[i].x] or D[R[i].y];
        D[R[i].x] = D[R[i].y] = k;
    }
    for (i=1; i<=N; ++i) {
        if (!D[i]) continue;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
