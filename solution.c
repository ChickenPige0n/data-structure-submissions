#include <stdio.h>
#include <stdlib.h>

void Solution();

int main(int argc, char** argv) {
    Solution();
    return 0;
}

typedef struct LoopQueue {
    int* array;
    int capacity;
    int count;
    int front;  // inclusive index
    int back;   // inclusive index
} LoopQueue;

void queue_init(LoopQueue** q, int size) {
    *q = (LoopQueue*)malloc(sizeof(LoopQueue));
    (*q)->array = (int*)malloc(sizeof(int) * size);
    (*q)->capacity = size;
    (*q)->count = 0;
    (*q)->front = 0;
    (*q)->back = 0;
}

bool queue_full(LoopQueue* q) {
    return q->count == q->capacity;
}
bool queue_empty(LoopQueue* q) {
    return q->count == 0;
}

bool enqueue(LoopQueue* q, int val) {
    if (queue_full(q)) return false;
    (q->array)[q->back] = val;
    q->back = (q->back + 1) % q->capacity;
    q->count++;
    return true;
}

bool dequeue(LoopQueue* q, int* val) {
    if (queue_empty(q)) return false;
    *val = (q->array)[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->count--;
    return true;
}

bool queue_get_front(LoopQueue* q, int* val) {
    if (queue_empty(q))
        return false;
    else {
        *val = (q->array)[q->front];
        return true;
    }
}

void Solution() {
    int m, q;
    scanf("%d %d", &m, &q);

    LoopQueue* queue;
    queue_init(&queue, m);
    for (; q > 0; q--) {
        int op;
        scanf("%d", &op);
        int x;
        // enqueue an element
        if (op == 1) {
            scanf("%d", &x);
            if (!enqueue(queue, x)) printf("FULL\n");
        } else if (op == 2) {  // dequeue an element from queue
            if (dequeue(queue, &x))
                printf("%d\n", x);
            else
                printf("EMPTY\n");
        } else if (op == 3) {  // get queue front element
            if (queue_get_front(queue, &x))
                printf("%d\n", x);
            else
                printf("EMPTY\n");
        } else if (op == 4) {  // queue element count
            printf("%d\n", queue->count);
        }
    }
}
