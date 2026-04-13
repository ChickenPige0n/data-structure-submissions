#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void Solution();

int main(int argc, char** argv) {
    Solution();
    return 0;
}

/// index starts from 1. tree[0] == tree.count
void mid_order(int* tree, int index) {
    if (index > tree[0]) return;
    mid_order(tree, index * 2);
    printf("%d ", tree[index]);
    mid_order(tree, index * 2 + 1);
}

void Solution() {
    int n;
    scanf("%d", &n);
    int* tree = malloc(sizeof(int) * (n + 1));
    tree[0] = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tree[i]);
    }
    mid_order(tree, 1);
    free(tree);

    int depth = ceil(log2(n));
    printf("\n%d", depth);
}
