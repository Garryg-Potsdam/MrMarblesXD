#include "../Headers/PacketQueue.h"

unsigned char* getBuffer(Node*);

void put(Queue* packets, const unsigned char* buffer, const int size) {
    packets->size++;
    Node* temp = (Node*)malloc(sizeof(Node));
    //PrintsData(buffer, size);
    //printf("Size: %d\n", packets->size);
    temp->buffer = (unsigned char*)malloc(65536);
    temp->buffer = buffer;
    temp->size = size;
    if (packets->front == NULL && packets->rear == NULL) {
	packets->front = packets->rear = temp;
	return;
    }

    packets->rear->next = temp;
    packets->rear = packets->rear->next;
}

Node* get(Queue* packets) {
    packets->size--;    
    Node* temp = packets->front;
    packets->front = packets->front->next;
    
    temp->next = NULL;
    PrintsData(temp->buffer, temp->size);
    return temp;
}

bool empty(Queue* packets) {
    if (packets->size > 0)
	printf("Size: %d\n", packets->size);
    return packets->size == 0;
}

// Parameters: data - the packet data
// 	       Size - the size of the buffer
void PrintsData (const u_char * data , int Size) {
    int i; // , j;
    printf("PACKET:\n        ");
    for(i=0 ; i < Size ; i++) {
	if (i % 60 == 0 && i > 0) printf("\n        " );
        if(data[i] > 32 && data[i] < 127)	    
            printf("%c",(unsigned char)data[i]); //if its a number or alphabet
        else printf("."); //otherwise print a dot
    }
    printf("\n\n");
}
