#include "../Headers/PacketQueue.h"

unsigned char* getBuffer(Node*);

void put(Queue* packets, const unsigned char* buffer, const int size) {
    printf("put Address: %x\n", (int)packets);
    packets->size++;
    Node* temp = (Node*)malloc(sizeof(Node));
    
    //PrintsData(buffer, size);
    //printf("Size: %d\n", packets->size);
    
    temp->buffer = buffer;
    temp->size = size;
    
    if (packets->front == NULL && packets->rear == NULL) {
        printf("NULL LIST\n");
	    packets->front = temp;
        packets->rear = temp;
	    return;
    }

    packets->rear->next = temp;
    packets->rear = packets->rear->next;
    //PrintsData(packets->rear->buffer, packets->rear->size);
}

Node* get(Queue* packets) {
    packets->size--;    
    Node* temp = packets->front;
    packets->front = packets->front->next;
    
    //temp->next = NULL;
    PrintsData(temp->buffer, temp->size);
    return temp;
}

bool empty(Queue* packets) {
    //if (packets->size > 0)
	//printf("Size: %d\n", packets->size);
    return packets->size == 0;
}

// Parameters: data - the packet data
// 	       Size - the size of the buffer
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
