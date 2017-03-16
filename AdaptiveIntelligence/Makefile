OUT_DIR = build

SNIF_OBJ = $(OUT_DIR)/Sniffer.o

# INC_DIR = libraries/WpdPack/Include
CFLAGS = -c -Wall

# Source folder
SRC_DIR = Source
# Header folder
HDR_DIR = Headers

# Parser file
SNIFFER = $(SRC_DIR)/Sniffer/Sniffer.c

# Build EXE
Sniffer: $(SNIF_OBJ)
	gcc -o Parser $(SNIF_OBJ) -lpcap
	@echo "make complete."

# Build Parser object
$(OUT_DIR)/Sniffer.o:$(SNIFFER)
	mkdir -p $(OUT_DIR)
	gcc $(CFLAGS) $(SNIFFER) -o $(SNIF_OBJ) -lpcap

clean:
	rm -rf $(OUT_DIR)
