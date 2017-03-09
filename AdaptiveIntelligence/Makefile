obj = build/Parser.o

INC_DIR = libraries/WpdPack/Include
CFLAGS = -c -Wall -I$(INC_DIR)

# Source folder
SRC_DIR = Source
# Header folder
HDR_DIR = Headers

# Parser file
PARSER = $(SRC_DIR)/Parser/Parser.c

# Build EXE
Parser: $(obj)
	cc -o Parser $(obj)
	@echo "make complete."

# Build Parser object
build/Parser.o:$(PARSER)
	cc $(CFLAGS) $(PARSER) -o $(obj)

clean:
	rm $(obj)
