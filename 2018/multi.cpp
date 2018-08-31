//
//  main.cpp
//  nypc_multi
//
//  Created by 엄서훈 on 2018. 8. 23..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>
const int LM = 300005;
int N, M[2000] = {0};

struct data {
    int s, e;
} user[LM];

int main() {
    int i, sh, sm, eh, em, k=0, ans=0, anss=0, anse=0;
    scanf("%d", &N);
    for (i=0; i<N; ++i) {
        scanf("%d:%d %d:%d", &sh, &sm, &eh, &em);
        user[i].s = sh * 60 + sm;
        user[i].e = eh * 60 + em;
    }
    for (i=0; i<N; ++i) {
        M[user[i].s]++;
        M[user[i].e]--;
    }
    for (i=0; i<2000; ++i) {
        k += M[i];
        if (ans < k) {
            ans = k, anss = i, anse = 0;
        }
        if (M[i] < 0 && anse == 0) {
            anse = i;
        }
    }
    printf("%d\n", ans);
    printf("%02d:%02d %02d:%02d\n", anss / 60, anss % 60, anse / 60, anse % 60);
    return 0;
}
