//
//  main.cpp
//  nypc_button
//
//  Created by 엄서훈 on 2018. 8. 23..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>
const int LM = 2005;
int A, B;
bool D[LM][LM];

int main() {
    scanf("%d %d", &A, &B);
    D[1][0]=1;
    int siz = A < B ? B : A;
    for (int i=1; i<=siz; ++i) {
        for (int j=0; j<=siz; ++j) {
            if (!D[i][j]) continue;
            D[i+j][j] = true, D[i][j+i] = true;
        }
    }
    puts(D[A][B] ? "POSSIBLE" : "IMPOSSIBLE");
    return 0;
}
