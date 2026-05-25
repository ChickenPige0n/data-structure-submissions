#include <stdio.h>
#include <stdlib.h>

#define MAXM 10005
#define EMPTY -1

/*
 * 本题要求完整编写代码，但头文件和 main 函数已给定。
 * 建议使用 table[i] 表示哈希表下标 i 中存放的关键字。
 * 若 table[i] == EMPTY，表示该位置为空。
 */

void Solution(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    int* table = (int*)malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        int pos = key % m;
        while (table[pos] != EMPTY) {
            pos = (pos + 1) % m;
        }
        table[pos] = key;
    }

    for (int i = 0; i < m; i++) {
        if (i > 0) {
            printf(" ");
        }
        if (table[i] == EMPTY) {
            printf("#");
        } else {
            printf("%d", table[i]);
        }
    }
    printf("\n");

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int key;
        scanf("%d", &key);
        int pos = key % m;
        int start = pos;
        int ans = -1;

        while (table[pos] != EMPTY) {
            if (table[pos] == key) {
                ans = pos;
                break;
            }
            pos = (pos + 1) % m;
            if (pos == start) {
                break;
            }
        }

        printf("%d\n", ans);
    }

    free(table);

}

/* === 请不要修改 main 函数 === */
int main() {
    Solution();
    return 0;
}