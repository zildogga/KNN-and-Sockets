#include "Client.h"
using namespace std;
const int SIZE_OF_BUFFER = 4096;
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
    // infinite loop to send and receive data from server
    while(true) {
        // create char array to store input from user
        char data_addr[SIZE_OF_BUFFER];
        // get input from user
        cin.getline(data_addr, SIZE_OF_BUFFER);
        // get length of data
        sendBuffer(data_addr, sock);
        // create buffer to store received data
        char buffer[SIZE_OF_BUFFER];
        // gets the input to the buffer from the socket
        // if nullptr was returned
        if(getBuffer(buffer,sock) == nullptr) {
            break;
        } else if (strcmp(buffer, "close") == 0){
            // close socket and return 0 if "close" is received from server
            close(sock);
            return 0;
        } else {
            // print received data
            cout << buffer << endl;
        }
    }
    // close socket
    close(sock);
    return 0;
}
void Client::sendBuffer(char data_addr[], int sock) {
    // get length of data
    int data_len = strlen(data_addr);
    // try to send data to server
    int sent_bytes = send(sock, data_addr, data_len, 0);
    if (sent_bytes < 0) {
        // error
    }
}
char *Client::getBuffer(char* buffer,int sock) {
    // expected length of received data
    int expected_data_len = SIZE_OF_BUFFER;
    // clear memory of buffer
    memset(buffer, 0, SIZE_OF_BUFFER);
    // try to receive data from server
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // break loop if connection is closed by server
        return nullptr;
    } else if (read_bytes < 0) {
        // break loop if there is an error receiving data from server
        return nullptr;
    }
    return buffer;
}

void Client::selectCommand() {

}

/*
int Client::vectorToCharArray(const std::vector<double>& vec, char* charArray) {
    // create stringstream object
    std::stringstream ss;
    // initialize count variable
    int count = 0;
    // iterate through elements in vec
    for (double d : vec) {
        // add element to stringstream object
        ss << d << ' ';
        // increment count
        count++;
    }
    // convert stringstream object to string
    std::string s = ss.str();
    // copy string to charArray
    strcpy(charArray, s.c_str());
    // return count
    return count;
}
*/