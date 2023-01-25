#include "Client.h"

using namespace std;

int Client::createClient(char *ipAddress, string portNum) {
    // declare and initialize port number
    int port;
    // convert string portNum to int and store in port
    istringstream iss(portNum);
    if (iss >> port) {
    } else {
        // print error message if conversion fails
        cerr << "invalid input" << endl;
        return 0;
    }
    // cast ipAddress to const char*
    const char *ip_address = ipAddress;
    // cast port to const int
    const int port_no = port;
    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        // print error message if socket creation fails
        perror("error creating socket");
        return 0;
    }
    // create sockaddr_in struct
    struct sockaddr_in sin;
    // clear memory of sin
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    // try to connect to server
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        // print error message if connection fails
        perror("error connecting to server");
        return 0;
    }
    CLI cli(sock);
    cli.start();
    return 1;
}


