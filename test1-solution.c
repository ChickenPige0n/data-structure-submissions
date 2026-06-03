#include <stdio.h>

#define MAXN 100005

int score[MAXN];
int partitionCount = 0;

int Partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low, j = high;
    while (i < j) {
        while (i < j && a[j] >= pivot) j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] <= pivot) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = pivot;
    return i;
}

void QuickSort(int a[], int low, int high) {
    if (low >= high) return;
    partitionCount++;
    int pivotIndex = Partition(a, low, high);
    QuickSort(a, low, pivotIndex - 1);
    QuickSort(a, pivotIndex + 1, high);
}

void Solution(void) {
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &score[i]);
    }

    QuickSort(score, 0, n - 1);

    for (i = 0; i < n; ++i) {
        if (i > 0) printf(" ");
        printf("%d", score[i]);
    }
    printf("\n");
    printf("%d\n", partitionCount);
}

/* === 请不要修改 main 函数 === */
int main() {
    Solution();
    return 0;
}