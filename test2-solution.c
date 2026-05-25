#include <stdio.h>

#define MAXN 10005

long long w[MAXN * 2];
int used[MAXN * 2];

/* === 请在下方补全代码 === */

void Solution(void) {
    int n;
    long long ans = 0;

    scanf("%d", &n);

    /*
     * 1. 读入 n 个权值
     * 2. 每次找出两个未使用的最小权值
     * 3. 合并后放回数组，并累加 WPL
     */
    for (int i = 0; i < n; i++) {
        scanf("%lld", &(w[i]));
        used[i] = 0;
    }

    if (n <= 1) {
        printf("0\n");
        return;
    }

    for (int i = n; i < 2 * n; i++) {
        used[i] = 0;
    }

    int total = n;

    for (int i = 0; i < n - 1; i++) {
        // 两个未使用的最小权值index
        int x = -1, y = -1;

        for (int j = 0; j < total; j++) {
            if (used[j]) {
                continue;
            }

            if (x == -1 || w[j] < w[x]) {
                y = x;
                x = j;
            } else if (y == -1 || w[j] < w[y]) {
                y = j;
            }
        }

        used[x] = 1;
        used[y] = 1;
        w[total] = w[x] + w[y];
        ans += w[total];
        total++;
    }

    printf("%lld\n", ans);
}

/* === 请不要修改 main 函数 === */
int main() {
    Solution();
    return 0;
}