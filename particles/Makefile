# Makefile for Charm++ program

# Variables
CHARMC = /Users/stevenqie/software/charm/netlrts-darwin-arm8/bin/charmc
OPTS = -O2
SUFFIX = 
DECL = 

all: particles 

particles: particles.o particles.decl.h
	$(CHARMC) $(OPTS) -module CommonLBs -language charm++ -o particles$(SUFFIX) particles.o 

particles.o: particles.C particles.decl.h
	$(CHARMC) $(OPTS) -o $@ -c $< 

particles.decl.h: particles.ci 
	$(CHARMC) -E particles.ci $(DECL)

clean:
	rm -f *.o $(TARGET) particles.decl.h particles.def.h charmrun 

.PHONY: all clean