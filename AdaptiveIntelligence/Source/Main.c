#include "../Headers/Sniffer.h"


// This is a program that search packets data
// for malicious intent or unsecure data
int main(int argc, char** argv) {
    
    // initialize the MPI environment
    MPI_Init(NULL, NULL);

    // get the rank of current node    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    const int nitems = 2;
    int blocklengths[] = {1, 1};
    MPI_Datatype types[] = {MPI_UNSIGNED_CHAR, MPI_INT};
    MPI_Datatype MPI_NODE;
    MPI_Aint offsets[] = {offsetof(Node, buffer), offsetof(Node, size)};

    MPI_Type_create_struct(nitems, blocklengths, offsets, types, &MPI_NODE);
    MPI_Type_commit(&MPI_NODE);

        

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
        for(t = 0; t < NUM_THREADS; t++){
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
    } else { // TODO: get packet data from 
        printf("My Rank: %d\n", rank);
	    while(1){
            Node* temp = malloc(sizeof(Node*));
            MPI_Recv(temp, 1, MPI_NODE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            PrintsData(temp->buffer, temp->size, "RANK1");
            free(temp);
        }
    }
    
    // wrap up and end the program
    MPI_Finalize();
    return 0;
}
