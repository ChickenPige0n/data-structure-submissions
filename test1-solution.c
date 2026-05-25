#include <stdio.h>

#define MAXN 100005

int a[MAXN];

void Swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void SiftDown(int a[], int start, int end) {
    int root = start;
    while (1) {
        int left = root * 2 + 1;
        if (left > end) break;
        int child = left;
        if (left + 1 <= end && a[left + 1] > a[left])
            child = left + 1;
        if (a[child] > a[root]) {
            Swap(&a[child], &a[root]);
            root = child;
        } else {
            break;
        }
    }
}

void HeapSort(int a[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; --i)
        SiftDown(a, i, n - 1);
    for (i = n - 1; i > 0; --i) {
        Swap(&a[0], &a[i]);
        SiftDown(a, 0, i - 1);
    }
}

void Solution(void) {
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    HeapSort(a, n);

    for (i = 0; i < n; ++i) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

/* === 请不要修改 main 函数 === */
int main() {
    Solution();
    return 0;
}