# Makefile for Charm++ program

# Variables
CHARMC = /Users/stevenqie/software/charm/netlrts-darwin-arm8/bin/charmc   
TARGET = testbroadcast                       
SRCS = broadcastEx.ci broadcastEx.C             

CFLAGS = -O3

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CHARMC) broadcastEx.ci              
	$(CHARMC) $(CFLAGS) -c broadcastEx.C        
	$(CHARMC) -o $(TARGET) broadcastEx.o 
clean:
	rm -f *.o $(TARGET) broadcast_example.decl.h broadcast_example.def.h charmrun 

.PHONY: all clean
