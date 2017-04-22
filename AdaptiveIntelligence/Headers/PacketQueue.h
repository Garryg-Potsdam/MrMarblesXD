#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for queue linked list
// stores packet data
typedef struct Node_t {
    unsigned char* buffer;
    int size;
    struct Node* next;
} Node;

// Linked list type queue for
// storing packet data nodes
typedef struct Queue {
    int size;
    Node* front;
    Node* rear;
} Queue;

// Parameters: Queue* - a Queue of network packets
//              char* - a buffer of packet data
//                int - the size of the buffer
// Post-Condition: adds a packet to the end of the packet queue
extern void put(Queue*, const unsigned char*, const int);

// Parameters: Queue* - the queue of packets to get item from
// Returns: the front packet of a queue
extern Node* get(Queue*);

// Parameters: Queue* - a queue of packets
// Returns: true if queue is empty, false otherwis
extern bool empty(Queue*);

// Parameters: u_char* - the packet data
// 	           int - the size of the buffer
// Post-Condition: prints packet data to the terminal
void PrintsData (const u_char*, int, char*);
