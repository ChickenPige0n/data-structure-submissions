#include <stdio.h>

#define MAXN 105
#define MAXM 12

/*
 * BTNode 表示一个 B 树结点。
 * keynum：当前结点中的关键字个数。
 * key[1..keynum]：当前结点中的关键字，按升序存放，使用 1 下标。
 * child[0..keynum]：孩子结点编号。0 表示该孩子不存在。
 */
typedef struct {
    int keynum;
    int key[MAXM];
    int child[MAXM];
} BTNode;

BTNode tree[MAXN];
int m, n, rootId;

int SearchNode(BTNode *node, int target) {
    int i = 1;

    /*
     * node：当前正在查找的 B 树结点。
     * target：待查找的关键字。
     * i：在 key[] 中从左到右扫描的位置。
     * 返回值：第一个 key[i] >= target 的位置；若 target 大于所有关键字，返回 keynum + 1。
     */

    while (i <= node->keynum && node->key[i] < target) {
        ++i;
    }

    return i;
}

void SearchBTree(int target) {
    int nodeId = rootId;
    int pos;

    /*
     * nodeId：当前访问的结点编号，0 表示空结点。
     * pos：target 在当前结点内应比较的位置，由 SearchNode 返回。
     * 若 key[pos] 等于 target，则输出 Found nodeId pos。
     * 否则进入 child[pos - 1] 继续查找。
     */
    while (nodeId != 0) {
        pos = SearchNode(&tree[nodeId], target);
        if (pos <= tree[nodeId].keynum && tree[nodeId].key[pos] == target) {
            printf("Found %d %d\n", nodeId, pos);
            return;
        }
        nodeId = tree[nodeId].child[pos - 1];
    }

    printf("Not found\n");
}

void Solution(void) {
    int i, j, id, q, target;

    scanf("%d %d %d", &m, &n, &rootId);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &id);
        scanf("%d", &tree[id].keynum);
        for (j = 1; j <= tree[id].keynum; ++j) {
            scanf("%d", &tree[id].key[j]);
        }
        for (j = 0; j <= tree[id].keynum; ++j) {
            scanf("%d", &tree[id].child[j]);
        }
    }

    scanf("%d", &q);
    while (q-- > 0) {
        scanf("%d", &target);
        SearchBTree(target);
    }
}

/* === 请不要修改 main 函数 === */
int main() {
    Solution();
    return 0;
}