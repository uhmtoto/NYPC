//
//  main.cpp
//  nypc_winner
//
//  Created by 엄서훈 on 2018. 8. 22..
//  Copyright © 2018년 uhmtoto. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
const int LM = 8;
const int Vscore[] = {10, 8, 6, 5, 4, 3, 2, 1};

struct data{
    int team;
    double time;
    bool operator < (const data &r) const {
        return time < r.time;
    }
} res[LM + 10];

int main() {
    double s;
    int TC, m, score[2], i, rank;
    char mode[10], team[10];
    scanf("%d", &TC);
    while (TC--) {
        scanf("%s", mode);
        for (i=0; i<LM; ++i) {
            scanf("%s %d:%lf", team, &m, &s);
            res[i].team = team[0] == 'b' ? 0 : 1;
            res[i].time = m * 60 + s;
        }
        std::stable_sort(res, res + LM);
        if (mode[0] == 'i'){ //item
            if(res[0].team == 0) {
                puts("blue");
            }
            else {
                puts("red");
            }
        }
        else { //speed
            score[0] = score[1] = 0;
            for (i=0, rank=0; i<LM; ++i) {
                if(res[i].time - res[0].time > 10) continue;
                score[res[i].team] += Vscore[rank++];
            }
            if(score[0] > score[1]){
                puts("blue");
            }
            else if(score[0] == score[1]) {
                puts(res[0].team == 0 ? "blue" : "red");
            }
            else {
                puts("red");
            }
        }
    }
    return 0;
}
