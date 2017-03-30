#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_t {
    unsigned char* buffer;
    int size;
    struct Node* next;
} Node;

typedef struct Queue {
    int size;
    Node* front;
    Node* rear;
} Queue;

extern void put(Queue*, const unsigned char*, const int);
extern Node* get(Queue*);
extern bool empty(Queue*);
void PrintsData (const u_char*, int);
