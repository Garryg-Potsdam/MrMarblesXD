#include "../Headers/PacketQueue.h"

// Parameters: packets - a Queue of network packets
//              buffer - a buffer of packet data
//                size - the size of the buffer
// Post-Condition: adds a packet to the end of the packet queue
void put(Queue* packets, const unsigned char* buffer, const int size) {
    // increase the size of the queue
    packets->size++;

    // create a new node
    Node* temp = (Node*)malloc(sizeof(Node));
    
    // store the packet data and size in the temp node
    temp->buffer = buffer;
    temp->size = size;

    // if the queue is not started yet, add first packets
    if (packets->front == NULL && packets->rear == NULL) {
	    packets->front = temp;
        packets->rear = temp;
	    return;
    } else { // already started add packet to the end of queue
        packets->rear->next = temp;
        packets->rear = packets->rear->next;
    }
}

// Parameters: packets - the queue of packets to get item from
// Returns: the front packet of a queue
Node* get(Queue* packets) {
    // check if queue is empty
    if (packets->size == 0) {
        printf("Empty Queue Error.\n");
        return NULL;
    }

    // decrement size of queue
    packets->size--;

    // grab the front packet
    Node* temp = packets->front;

    // move front pointer to next node
    packets->front = packets->front->next;
    
    // return front packet
    return temp;
}

// Parameters: packets - a queue of packets
// Returns: true if queue is empty, false otherwise
bool empty(Queue* packets) {
    return packets->size == 0;
}


// Parameters: data - the packet data
// 	           size - the size of the buffer
// Post-Condition: prints packet data to the terminal
void PrintsData (const u_char * data , int size) {    
    int i;
    printf("PACKET:\n        ");
    for(i=0 ; i < size ; i++) {
	if (i % 60 == 0 && i > 0) printf("\n        " );
        if(data[i] > 32 && data[i] < 127)	    
            printf("%c",(unsigned char)data[i]); //if its a number or alphabet
        else printf("."); //otherwise print a dot
    }
    printf("\n\n");
}
