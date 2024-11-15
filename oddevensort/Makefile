# Variables
CHARMC = /Users/stevenqie/software/charm/netlrts-darwin-arm8/bin/charmc
TARGET = oddeven                       
SRCS = oddeven.ci oddeven.C          

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CHARMC) oddeven.ci             
	$(CHARMC) -c oddeven.C    
	$(CHARMC) -o $(TARGET) oddeven.o 

clean:
	rm -f *.o $(TARGET) oddeven.decl.h oddeven.def.h charmrun 

.PHONY: all clean