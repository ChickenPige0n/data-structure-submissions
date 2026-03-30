#include <stdio.h>
#include <stdlib.h>

void Solution();

int main(int argc, char** argv) {
    Solution();
    return 0;
}

void visit_preorder(int elem_count, int index) {
    if (index > elem_count) return;
    printf("%d ", index);
    visit_preorder(elem_count, index * 2);
    visit_preorder(elem_count, index * 2 + 1);
}

void visit_inorder(int elem_count, int index) {
    if (index > elem_count) return;
    visit_inorder(elem_count, index * 2);
    printf("%d ", index);
    visit_inorder(elem_count, index * 2 + 1);
}

void visit_postorder(int elem_count, int index) {
    if (index > elem_count) return;
    visit_postorder(elem_count, index * 2);
    printf("%d ", index);
    visit_postorder(elem_count, index * 2 + 1);
}

void Solution() {
    int layer_count;
    scanf("%d", &layer_count);
    visit_inorder(layer_count, 1);
}
