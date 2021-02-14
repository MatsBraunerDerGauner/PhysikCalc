CXX = gcc -g 
MAIN_BINARIES = $(basename $(wildcard *Main.c))
HEADERS = $(wildcard Include/*.h)
OBJECTS = $(addsuffix .o, $(basename $(filter-out %Main.c, $(wildcard *.c))))
LIBRARIES =

.PRECIOUS: %.o
.SUFFIXES:

all: compile

compile: $(MAIN_BINARIES)

%Main: %Main.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBRARIES) 

%.o: %.c $(HEADERS)
	$(CXX) -c $*.c

clean:
	rm *.o
	rm $(MAIN_BINARIES)

test:
	@echo $(HEADERS)
	@echo $(OBJECTS)

