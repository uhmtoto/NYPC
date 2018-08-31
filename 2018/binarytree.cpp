//
//  main.cpp
//  nypc_binarytree
//
//  Created by 엄서훈 on 2018. 8. 24..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//  Only for TC 1 (N = K)
//

#include <stdio.h>

int main() {
    int N, K;
    long long ans = 1;
    scanf("%d %d", &N, &K);
    for (int i=0; i<K-1; ++i) {
        ans *= 2;
        ans %= 1000000007;
    }
    printf("%lld\n", ans);
    return 0;
}
