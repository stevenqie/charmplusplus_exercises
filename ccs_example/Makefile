CHARMDIR= /Users/stevenqie/software/charm
CHARMC = /Users/stevenqie/software/charm/netlrts-darwin-arm8/bin/charmc 

all: server client

server: server.o
	$(CHARMC) -o $@ server.o -language converse++

client: client.o
	g++ -o $@ client.o -I$(CHARMDIR)/include -L$(CHARMDIR)/lib -lccs-client

server.o: server.C
	$(CHARMC) -c server.C -language converse++

client.o: client.C
	g++ -c client.C -I$(CHARMDIR)/include

clean:
	rm -f client server *.o conv-host charmrun