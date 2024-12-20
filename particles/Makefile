# Variables
CHARMC = /Users/stevenqie/software/charm/netlrts-darwin-arm8/bin/charmc
TARGET = particles                       
SRCS = particles.ci particles.C          

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CHARMC) particles.ci             
	$(CHARMC) -c particles.C    
	$(CHARMC) -o $(TARGET) particles.o  

clean:
	rm -f *.o $(TARGET) particles.decl.h particles.def.h charmrun 

.PHONY: all clean