#include <stdio.h>

#define MAXN 10005

/* ltag / rtag: 0 表示孩子，1 表示线索 */
typedef struct Node {
    char ch;
    struct Node* lchild;
    struct Node* rchild;
    int ltag;
    int rtag;
} Node;

// evil global variables...
Node tree[MAXN];
Node* root;
Node* order[MAXN];
Node* pre;
int n, ordCnt;

/// 按前序保存到 `order[]`
void Preorder(Node* p) {
    if (!p) return;
    order[ordCnt] = p;
    ordCnt++;
    Preorder(p->lchild);
    Preorder(p->rchild);
}

void PreThread(Node* p) {
    Node* lchild;
    Node* rchild;

    if (!p) return;
    lchild = p->lchild;
    rchild = p->rchild;

    if (!p->lchild) {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != NULL && !pre->rchild) {
        pre->rchild = p;
        pre->rtag = 1;
    }

    pre = p;

    if (lchild != NULL) {
        PreThread(lchild);
    }
    if (rchild != NULL) {
        PreThread(rchild);
    }
}

void PrintPreorderByThread(void) {
    Node* p = root;
    int first = 1;

    while (p != NULL) {
        if (!first) printf(" ");
        printf("%c", p->ch);
        first = 0;

        if (p->ltag == 0 && p->lchild != NULL) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    printf("\n");
}

void Solution(void) {
    int i, q, k;
    int rootId, leftId, rightId;
    int pos[256];
    char c;

    for (i = 0; i < 256; ++i) {
        pos[i] = -1;
    }

    scanf("%d %d", &n, &rootId);
    for (i = 1; i <= n; ++i) {
        scanf(" %c %d %d", &tree[i].ch, &leftId, &rightId);
        tree[i].lchild = leftId ? &tree[leftId] : NULL;
        tree[i].rchild = rightId ? &tree[rightId] : NULL;
        tree[i].ltag = 0;
        tree[i].rtag = 0;
    }

    root = &tree[rootId];

    ordCnt = 0;
    Preorder(root);

    pre = NULL;
    PreThread(root);
    if (pre != NULL && pre->rchild == NULL) {
        pre->rtag = 1;
    }

    PrintPreorderByThread();

    for (i = 0; i < ordCnt; ++i) {
        pos[(unsigned char)order[i]->ch] = i;
    }

    scanf("%d", &q);
    while (q-- > 0) {
        scanf(" %c", &c);
        k = pos[(unsigned char)c];

        if (k <= 0)
            printf("#");
        else
            printf("%c", order[k - 1]->ch);
        printf(" ");
        if (k >= ordCnt - 1)
            printf("#");
        else
            printf("%c", order[k + 1]->ch);
        printf("\n");
    }
}

int main() {
    Solution();
    return 0;
}