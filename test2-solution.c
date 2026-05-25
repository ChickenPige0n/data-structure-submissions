#include <stdio.h>

#define MAXN 1005

typedef struct {
    int id;
    int height;
} Student;

Student q[MAXN];
int roundSwap[MAXN];

void SwapStudent(Student* a, Student* b) {
    Student t = *a;
    *a = *b;
    *b = t;
}

void Solution(void) {
    int n;

    scanf("%d", &n);

    /*
     * TODO:
     * 1. 读入初始队列。
     * 2. 按轮次从队首到队尾检查相邻两人。
     * 3. 若左边身高小于右边身高，则交换，并统计本轮交换次数。
     * 4. 某一轮交换次数为 0 时结束，但这一轮的 0 不计入 roundSwap。
     * 5. 按题目要求输出最终队列、总交换次数、每轮交换次数。
     */

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &q[i].id, &q[i].height);
    }
    int r = 0;
    do {
        roundSwap[r] = 0;
        for (int i = 0; i < n - 1; i++) {
            if (q[i].height < q[i + 1].height) {
                SwapStudent(&q[i], &q[i + 1]);
                roundSwap[r]++;
            }
        }
    } while (roundSwap[r++] > 0);

    for (int i = 0; i < n; i++) {
        printf("%d", q[i].id);
        if (i < n - 1) printf(" ");
    }

    printf("\n");

    int totalSwap = 0;
    for (int i = 0; i < r - 1; i++) {
        totalSwap += roundSwap[i];
    }
    printf("%d", totalSwap);
    printf("\n");

    for (int i = 0; i < r - 1; i++) {
        printf("%d", roundSwap[i]);
        if (i < r - 2) printf(" ");
    }
    if (r == 1) printf("0");
}

/* === 请不要修改 main 函数 === */
int main() {
    Solution();
    return 0;
}