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
    temp->buffer = malloc((size + 1) * sizeof(int));
    temp->buffer[0] = size;
    temp->size = size;

    // TODO: change this to make a new array and append the size on the front if it
    int i = 1;
    //printf("Packet Added\n");
    //printf("Passed Size: %d\n", size);
    for (; i <= size; i++) {
        temp->buffer[i] = buffer[i - 1];
    }

    //if (temp->buffer[0] > 0) {
    //    PrintsData(temp->buffer, temp->buffer[0]);
    //}
        
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
    if (packets->front == NULL)
        return NULL;

    // decrement size of queue
    packets->size--;
    
    Node* temp;
        
    // grab the front packet
    temp = packets->front;

    // move front pointer to next node
    packets->front = packets->front->next;
    if (packets->size == 0) {
        packets->front = NULL;
        packets->rear = NULL;
    }        

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
void PrintsData (int * data , int size) {    
    int i;
    printf("PACKET:\n        ");
    for(i = 1 ; i < size ; i++) {
	    if (i % 60 == 0 && i > 0) printf("\n        " );
            if(data[i] > 32 && data[i] < 127)
                //if its a number or alphabet	    
                printf("%c", data[i]);
        else printf("."); //otherwise print a dot
    }
    printf("\n\n");
}
