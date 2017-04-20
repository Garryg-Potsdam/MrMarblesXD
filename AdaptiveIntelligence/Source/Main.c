#include <mpi.h>
#include <stdio.h>
#include "../Headers/Sniffer.h"
#include <pthread.h>

// This is a program that search packets data
// for malicious intent or unsecure data
int main(int argc, char** argv) {

    // initialize the MPI environment
    MPI_Init(NULL, NULL);

    // get the rank of current node    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // rank 0 will be leading rank.
    // it dumps packets into a queue
    // and delivers them to other ranks
    if (rank == 0) { 
        // dump packets into queue
        // send packets
        // repeat                       
        while (1) {
            Queue packets = (Queue){(int)0, NULL, NULL};
            storePackets(&packets, 10);
            sendPackets(&packets);
        }        
    } else { // TODO: get packet data from 
	    printf("My Rank: %d\n", rank);
    }
    
    // wrap up and end the program
    MPI_Finalize();
    return 0;
}
