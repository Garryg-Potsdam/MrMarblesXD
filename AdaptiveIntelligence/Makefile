bld = build

obj = $(bld)/Parser.o

# INC_DIR = libraries/WpdPack/Include
CFLAGS = -c -Wall

# Source folder
SRC_DIR = Source
# Header folder
HDR_DIR = Headers

# Parser file
PARSER = $(SRC_DIR)/Parser/Parser.c

# Build EXE
Parser: $(obj)
	gcc -o Parser $(obj) -lpcap
	@echo "make complete."

# Build Parser object
build/Parser.o:$(PARSER)
	gcc $(CFLAGS) $(PARSER) -o $(obj) -lpcap

clean:
	rm $(bld)/*
