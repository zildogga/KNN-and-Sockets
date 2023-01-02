//
// Created by ofir on 12/31/22.
//

#include "Client.h"
using namespace std;
const int SIZE_OF_BUFFER = 4096;
int Client::createClient(char *ipAddress, int portNum) {
    const char *ip_address = ipAddress;
    const int port_no = portNum;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    while(true) {
        char data_addr[SIZE_OF_BUFFER];
        cin.getline(data_addr, SIZE_OF_BUFFER);
        int data_len = strlen(data_addr);
        int sent_bytes = send(sock, data_addr, data_len, 0);
        if (sent_bytes < 0) {
            // error
        }
        char buffer[SIZE_OF_BUFFER];
        int expected_data_len = sizeof(buffer);
        memset(buffer, 0, sizeof(buffer));
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            break;
        } else if (read_bytes < 0) {
            break;
        } else {
            cout << buffer << endl;
        }
    }
    close(sock);
    return 0;
}

int Client::vectorToCharArray(const std::vector<double>& vec, char* charArray) {
    std::stringstream ss;
    int count = 0;
    for (double d : vec) {
        ss << d << ' ';
        count++;
    }
    std::string s = ss.str();
    strcpy(charArray, s.c_str());
    return count;

}