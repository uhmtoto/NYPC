#include <stdio.h>
#include <string.h>

int main() {
    int n, m, ans=0;
    char str[10];
    scanf("%d %d", &n, &m);
    for (int i=0; i<n*m; ++i) {
        scanf("%s", str);
        if(!strcmp(str, "NEXON")) ans++;
    }
    printf("%d\n", ans);
}
