# Makefile for Charm++ program

# Variables
CHARMC = /Users/stevenqie/charm/netlrts-darwin-x86_64-smp/bin/charmc   
TARGET = kmeans                       
SRCS = kmeans.ci kmeans.C             

CFLAGS = -O3

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CHARMC) kmeans.ci              
	$(CHARMC) $(CFLAGS) -c kmeans.C        
	$(CHARMC) -o $(TARGET) kmeans.o 
clean:
	rm -f *.o $(TARGET) KMeans.decl.h KMeans.def.h charmrun 

.PHONY: all clean
