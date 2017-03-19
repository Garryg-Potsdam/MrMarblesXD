#include <mpi.h>
#include <stdio.h>
#include "../Headers/Sniffer.h"

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    if (rank == 0)
        storePackets();    
    
    
    
    MPI_Finalize();
}