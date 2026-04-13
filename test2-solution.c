#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Solution();

int main(int argc, char** argv) {
    Solution();
    return 0;
}
// l=>vallidate, r=>vallidate
int val_bst(int* arr, int n) {
    int* stack = malloc(sizeof(int) * (n));
    for(int i = 0; i < n; i++) stack[i] = INT_MIN;
    int sp = 0;
    int min_val = INT_MIN;
    for(int i = 1; i <= n; i++) {
        if (arr[i] < min_val) {
            free(stack);
            return -1;
        }
        while(stack[sp] < arr[i]) {
            min_val = stack[sp--];
        }
        stack[++sp] = arr[i];
    }
    free(stack);
    return 0;
}

void Solution() {
    int n;
    scanf("%d", &n);
    int* preorder_seq = malloc(sizeof(int) * (n + 1));
    preorder_seq[0] = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &preorder_seq[i]);
    }
    printf(val_bst(preorder_seq, n) == 0 ? "YES" : "NO");
    free(preorder_seq);
}
