To run the server

./charmrun +p2 ./server ++server ++server-port 10000 ++local
ccs: 2
ccs: Server IP = 128.174.241.108, Server port = 10000 $
CCS Handlers registered.  Waiting for net requests...
CCS Handlers registered.  Waiting for net requests...

or just

./charmrun +p2 ./server ++server
ccs: 2
ccs: Server IP = 128.174.241.108, Server port = 1912 $
CCS Handlers registered.  Waiting for net requests...
CCS Handlers registered.  Waiting for net requests...

in which case a random port is bound to and printed out.

To run the client
./client <myserverhost> <myserverport>