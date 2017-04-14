#include <mpi.h>
#include <stdio.h>
#include "../Headers/Sniffer.h"
#include <pthread.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment

    MPI_Init(NULL, NULL);
    
    Queue packets;
    printf("Main Address: %x\n", (int)&packets);
    packets.size = malloc(sizeof(int));
    packets.size = 0;
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        while (1) {
            storePackets(&packets, 10);
            printf("Queue Size: %d\n", packets.size);
            sendPackets(&packets);
        }
        
    } else {
	    printf("My Rank: %d\n", rank);
	    while (true) {
	        if (!empty(&packets)) {
    		    printf("HELLO");
                Node* temp = get(&packets);
	            //PrintsData(temp->buffer, temp->size);
	        }
	    }
    }
    
    MPI_Finalize();
    return 0;
}
