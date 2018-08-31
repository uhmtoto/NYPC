#include <stdio.h>

int N, M;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d", &M);
        printf("%c ", M);
    }
    printf("\n");
}
