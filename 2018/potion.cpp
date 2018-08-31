//
//  main.cpp
//  nypc_potion
//
//  Created by 엄서훈 on 2018. 8. 22..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i * N <= K; ++i){
        if((K - i * N) % M != 0) {
            continue;
        }
        printf("%d %d\n", i, (K - i * N) / M);
        break;
    }
    return 0;
}
