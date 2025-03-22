#include <stdio.h>

char g[50][50];

int check(int x, int y, int z) {
    int cnt = 0;

    if (z == 1) {  
        for (int i = 0; i < 8; i++) {
            for (int p = 0; p < 8; p++) {
                if ((i + p) % 2 == 0) {
                    if (g[x + i][y + p] != 'W')
                        cnt++;
                } else {
                    if (g[x + i][y + p] != 'B')
                        cnt++;
                }
            }
        }
    } else {  
        for (int i = 0; i < 8; i++) {
            for (int p = 0; p < 8; p++) {
                if ((i + p) % 2 == 0) {
                    if (g[x + i][y + p] != 'B')
                        cnt++;
                } else {
                    if (g[x + i][y + p] != 'W')
                        cnt++;
                }
            }
        }
    }
    return cnt;
}

int main() {
    int N = 0, M = 0;
    int cnt = 64;  

    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", g[i]);  
    }

    for (int i = 0; i + 7 < N; i++) {
        for (int p = 0; p + 7 < M; p++) {
            int temp1 = check(i, p, 1);
            int temp2 = check(i, p, 0);
            cnt = (temp1 < cnt ? temp1 : cnt);
            cnt = (temp2 < cnt ? temp2 : cnt);
        }
    }

    printf("%d", cnt);
    return 0;
}

 