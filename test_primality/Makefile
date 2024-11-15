# Makefile for Charm++ program

# Variables
CHARMC = /Users/stevenqie/charm/netlrts-darwin-x86_64-smp/bin/charmc   
TARGET = test_primality                       
SRCS = prime.ci prime.C             

CFLAGS = -O3

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CHARMC) prime.ci              
	$(CHARMC) $(CFLAGS) -c prime.C        
	$(CHARMC) -o $(TARGET) prime.o 
clean:
	rm -f *.o $(TARGET) test_primality.decl.h test_primality.def.h charmrun 

.PHONY: all clean
