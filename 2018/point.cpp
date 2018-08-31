//
//  main.cpp
//  nypc_point
//
//  Created by 엄서훈 on 2018. 8. 24..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>

int main() {
    int N, x, y, xsum = 0, ysum = 0;
    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d %d", &x, &y);
        xsum += x, ysum += y;
    }
    printf("%03lf %03lf\n", xsum / (double)N, ysum / (double)N);
    return 0;
}
