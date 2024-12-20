from pyccs import Server
import sys
import os

def main():
    if len(sys.argv) != 3:
        print(f"USAGE: {sys.argv[0]} {server_ip} {server_port}")
        sys.exit(1)

    server = Server(sys.argv[1], int(sys.argv[2]))
    server.connect()

    num_pes = server.num_pes()
    num_nodes = server.num_pes()

    print(f"Connected to server with {num_pes} pes and {num_nodes} nodes")
    message = (os.getlogin() + '\0').encode('ascii')

    # add some room in the reply for the entire message
    reply_len = max(len(message)+20, 50)

    for pe in range(num_pes):
        server.send_request(b'ping', pe, message)
        response = server.receive_response(reply_len)
        print(str(response, 'utf-8'))


if __name__ == '__main__':
    main()