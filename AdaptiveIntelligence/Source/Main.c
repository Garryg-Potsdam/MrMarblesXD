#include "../Headers/Sniffer.h"


// This is a program that search packets data
// for malicious intent or unsecure data
int main(int argc, char** argv) {
    
    // initialize the MPI environment
    MPI_Init(NULL, NULL);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // get the rank of current node    
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    // rank 0 will be leading rank.
    // it dumps packets into a queue
    // and delivers them to other ranks
    if (rank == 0) {
        // make array of threads size of world - 1
        pthread_t sendThreads[world_size];
        int rc;
        long t;
        // initialize shared packet queue
        Queue packets = (Queue){(int)0, NULL, NULL};
        
        pthread_mutex_lock(&mutex);
        // loop through and make a thread to send packets to each rank
        for(t = 1; t < world_size; t++) {
            printf("In main: creating thread %ld\n", t);

            // build params list with rank responsibility and queue pointer            
            Params* args = malloc(sizeof(Params));
            args->mutex = &mutex;
            args->rank = t;
            args->packets = &packets;
            // create thread
            rc = pthread_create(&sendThreads[t], NULL, sendPackets, args);
            
            // if failed, exit
            if (rc){
                printf("PTHREAD ERROR: %d\n", rc);
                exit(-1);
            }
        }
        pthread_mutex_unlock(&mutex);
        // dump packets into queue
        // send packets
        // repeat
        while (1) {
            Params params = (Params){&mutex, 0, &packets};
            storePackets(&packets, &params);
        }
    } else {
	    while(1){
            int size;            
            MPI_Recv(&size, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            
            int * buffer = malloc((size + 1) * sizeof(int));
            MPI_Recv(buffer, size, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            
            if (size == (int)buffer[0]) {
                printf("Rank %d\n", rank);
               PrintsData(buffer, size);
            }

            free(buffer);
        }
    }
    
    // wrap up and end the program
    MPI_Finalize();
    return 0;
}
