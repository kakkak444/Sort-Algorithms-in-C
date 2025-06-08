#pragma once

#include <stdlib.h>


typedef struct UtilQueueNode {
    struct UtilQueueNode* next;
    int content;
} QueueNode;

typedef struct {
    QueueNode* head;
    QueueNode* last;
    size_t length;
} Queue;


static inline void init_queue(Queue*);
static inline void deinit_queue(Queue*);
static inline int enqueue(Queue*, int);
static inline int dequeue(Queue*, int*);

static inline void init_node(QueueNode*, int);
static inline void deinit_node(QueueNode*);
static inline QueueNode* new_node(int);


static inline void init_queue(Queue* queue) {
    queue->head = NULL;
    queue->last = NULL;
    queue->length = 0;
}
static inline void deinit_queue(Queue* queue) {
    if (queue->length == 0) {
        return;
    }

    deinit_node(queue->head);
    free(queue->head);

    queue->head = NULL;
    queue->last = NULL;
    queue->length = 0;
}

static inline void init_node(QueueNode* node, int content) {
    node->next = NULL;
    node->content = content;
}
static inline void deinit_node(QueueNode* node) {
    if (node->next != NULL) {
        deinit_node(node->next);
        free(node->next);
        node->next = NULL;
    }
}
static inline QueueNode* new_node(int content) {
    QueueNode* new = (QueueNode*)malloc(sizeof(QueueNode));

    if (new != NULL) {
        init_node(new, content);
        return new;
    } else {
        return NULL;
    }
}

static inline int enqueue(Queue* queue, int elem) {
    QueueNode* new = new_node(elem);
    if (new == NULL) {
        return 1;
    } else {
        if (queue->length == 0) {
            queue->head = new;
            queue->last = new;
        } else {
            queue->last->next = new;
            queue->last = new;
        }
        ++(queue->length);

        return 0;
    }
}
static inline int dequeue(Queue* queue, int* dist) {
    if (queue->length == 0) {
        return 1;
    }

    QueueNode* old = queue->head;
    queue->head = old->next;
    --(queue->length);

    if (dist != NULL) {
        *dist = old->content;
    }

    free(old);

    return 0;
}
