# recursive function
# to check all dirs deep down
# NOTE $1,$2 are vars 
rwildcard=$(wildcard $1$2) \
					$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CC:=g++
CFLAGS:=-std=c++11 -c -Wall -I/usr/local/include/SDL2 \
	-I/usr/local/lib \
	-Iinclude
LFLAGS:=-I/usr/local/include/SDL2 \
	-I/usr/local/lib \
	-lSDL2
EXECUTABLE:=main
SOURCES:=$(call rwildcard,src/,*.cpp)
OBJECTS:=$(SOURCES:.cpp=.o)

# Declare non files
.PHONY: all clean run

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(addprefix build/,$(notdir $(OBJECTS))) $(LFLAGS) -o bin/$@

.cpp.o:
	$(CC) $(CFLAGS) $< -o build/$(notdir $@)

clean:
	@echo "Clearing up..."
	@rm -rf build/*.o
	@rm -rf bin/$(EXECUTABLE)

run:
	@./bin/$(EXECUTABLE)
