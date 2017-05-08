#include "../Headers/Sniffer.h"


// This is a program that search packets data
// for malicious intent or unsecure data
int main(int argc, char** argv) {
    
    // initialize the MPI environment
    MPI_Init(NULL, NULL);

    // get the rank of current node    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // total amount of packets to get in each cycle
    // before sending packets to other ranks
    const int totalPacketsToGet = 1000;    
    const int NUM_THREADS = 1;
    // rank 0 will be leading rank.
    // it dumps packets into a queue
    // and delivers them to other ranks
    if (rank == 0) { 
        pthread_t sendThreads[NUM_THREADS];
        int rc;
        long t;
        Queue packets = (Queue){(int)0, NULL, NULL};
        for(t = 0; t < NUM_THREADS; t++) {
            printf("In main: creating thread %ld\n", t);
            rc = pthread_create(&sendThreads[t], NULL, sendPackets, &packets);
            if (rc){
                printf("PTHREAD ERROR: %d\n", rc);
                exit(-1);
            }
        }

        // dump packets into queue
        // send packets
        // repeat                       
        while (1) {
            storePackets(&packets);
        }
    } else {
	    while(1){
            int size;            
            MPI_Recv(&size, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            
            int * buffer = malloc((size + 1) * sizeof(int));
            MPI_Recv(buffer, size, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            
            //if (size == (int)buffer[0]) {
              //  printf("Rank %d\n", rank);
               // PrintsData(buffer, size);
            //}

            free(buffer);
        }
    }
    
    // wrap up and end the program
    MPI_Finalize();
    return 0;
}
