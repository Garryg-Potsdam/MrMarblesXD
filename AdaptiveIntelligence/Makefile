OUT_DIR = build

# Object files
MAIN_OBJ = $(OUT_DIR)/Main.o
SNIF_OBJ = $(OUT_DIR)/Sniffer.o
Q_OBJ = $(OUT_DIR)/PacketQueue.o

objs = $(MAIN_OBJ) $(SNIF_OBJ) $(Q_OBJ)

CFLAGS = -c -Wall

# Source folder
SRC_DIR = Source
# Header folder
HDR_DIR = Headers

# Souce Files
MAIN = $(SRC_DIR)/Main.c
SNIFFER = $(SRC_DIR)/Sniffer.c
QUEUE = $(SRC_DIR)/PacketQueue.c

# Header Files
SNIFFER_H = $(HDR_DIR)/Sniffer.h
QUEUE_H = $(HDR_DIR)/PacketQueue.h

# Build EXE
Parser: $(objs)
	mpicc -o Parser $(objs) -lpcap
	@echo "make complete."

# Build Queue object
$(Q_OBJ):$(QUEUE) $(QUEUE_H)
	mpicc $(CFLAGS) $(QUEUE) -o $(Q_OBJ) -lpcap

# Build Parser object
$(SNIF_OBJ):$(SNIFFER) $(SNIFFER_H)
	mpicc $(CFLAGS) $(SNIFFER) -o $(SNIF_OBJ) -lpcap

# Build Main object
$(MAIN_OBJ):$(MAIN)
	mkdir -p $(OUT_DIR)
	mpicc -c Source/Main.c -o $(MAIN_OBJ) -lpcap

clean:
	rm -rf $(OUT_DIR)
