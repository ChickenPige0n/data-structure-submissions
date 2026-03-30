#include <stdio.h>
#include <stdlib.h>

void Solution();

int main(int argc, char** argv) {
    Solution();
    return 0;
}

typedef struct BTree {
    int* values;
    int n;
} BTree;

int lchild(BTree t, int index) {
    int lc = 2 * index + 1;
    return lc < t.n ? lc : -1;
}

int rchild(BTree t, int index) {
    int rc = 2 * index + 2;
    return rc < t.n ? rc : -1;
}

void pre_order(BTree t, int index) {
    if (index == -1) return;
    
    printf("%d ", t.values[index]);

    int lc = lchild(t, index);
    pre_order(t, lc);
    int rc = rchild(t, index);
    pre_order(t, rc);
}

void in_order(BTree t, int index) {
    if (index == -1) return;

    int lc = lchild(t, index);
    in_order(t, lc);

    printf("%d ", t.values[index]);

    int rc = rchild(t, index);
    in_order(t, rc);
}

void post_order(BTree t, int index) {
    if (index == -1) return;

    int lc = lchild(t, index);
    post_order(t, lc);
    int rc = rchild(t, index);
    post_order(t, rc);

    printf("%d ", t.values[index]);
}

void Solution() {
    BTree t;
    scanf("%d", &t.n);
    t.values = (int*)malloc(sizeof(int) * t.n);
    int n = 0;
    for (; n < t.n; n++) {
        scanf("%d", &(t.values[n]));
    }
    pre_order(t, 0);
    printf("\n");
    in_order(t, 0);
    printf("\n");
    post_order(t, 0);
}
