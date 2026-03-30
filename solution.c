#include <stdio.h>
#include <stdlib.h>

void Solution();

int main(int argc, char** argv) {
    Solution();
    return 0;
}

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void println_linked_list(Node* head) {
    Node* current = head;
    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void free_linked_list(Node* head) {
    Node* current = head;
    Node* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head && current != NULL);
}

void Solution() {
    int n;
    scanf("%d", &n);
    Node* head = (Node*)malloc(sizeof(Node));
    Node* current = head;
    for (int i = 0; i < n; i++) {
        scanf("%d", &current->value);
        if (i < n - 1) {
            current->next = (Node*)malloc(sizeof(Node));
            current = current->next;
        }
    }
    current->next = head;          // constructing looped linked list

    // Start spliting.
    Node* even_head = NULL;
    Node* even_tail = NULL;
    Node* odd_head = NULL;
    Node* odd_tail = NULL;
    int index = 0, odd_len = 0, even_len = 0;
    current = head;
    do {
        if (index % 2 == 0) {
            if (even_tail == NULL) {
                even_head = current;
                even_tail = current;
            } else {
                even_tail->next = current;
                even_tail = current;
            }
            even_len++;
        } else {
            if (odd_tail == NULL) {
                odd_tail = current;
                odd_head = current;
            } else {
                odd_tail->next = current;
                odd_tail = current;
            }
            odd_len++;
        }
        current = current->next;
        index++;
    } while (current != head);

    odd_tail->next = odd_head;
    even_tail->next = even_head;

    printf("%d ", even_len);
    println_linked_list(even_head);

    printf("%d ", odd_len);
    println_linked_list(odd_head);


    free_linked_list(odd_head);
    free_linked_list(even_head);
}
