# Makefile for Charm++ program

# Variables
CHARMC = /Users/stevenqie/charm/netlrts-darwin-x86_64-smp/bin/charmc   
TARGET = data_balancing                       
SRCS = data_balancing.ci data_balancing.C             

CFLAGS = -O3

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CHARMC) data_balancing.ci              
	$(CHARMC) $(CFLAGS) -c data_balancing.C        
	$(CHARMC) -o $(TARGET) data_balancing.o 
clean:
	rm -f *.o $(TARGET) data_balancing.decl.h data_balancing.def.h charmrun 

.PHONY: all clean
