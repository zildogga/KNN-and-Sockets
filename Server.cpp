#include "Server.h"

string file = "";
int sockNum = 0;
int size = 4096;
int numOfUsers = 3;
// This line creates a new Classification object
Classification classification;
ReadFile readFile;

int Server::startServer(string serverPort, string fileName) {
    // declare and initialize port number
    int port;
    // convert string serverPort to int and store in port
    istringstream iss(serverPort);
    if (iss >> port) {
    } else {
        // print error message if conversion fails
        cerr << "invalid input" << endl;
        return 0;
    }
    // store fileName in file
    file = fileName;
    // read CSV file and store contents in readFileTry
    vector<vector<string>> readFileTry = readFile.ReadCSVByPath(fileName);
    if (readFileTry.empty()) {
        // return -1 if reading file fails
        return -1;
    }
    // cast port to const int
    const int server_port = port;
    // check if port number is out of bounds
    if (server_port < 1024 || server_port > 65535) {
        // print error message if port number is out of bounds
        cerr << "number of port is out of bounds" << endl;
        return -1;
    }
    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        // print error message if socket creation fails
        perror("error creating socket");
        return -1;
    }
    // create sockaddr_in struct
    struct sockaddr_in sin;
    // clear memory of sin
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    // try to bind socket to address and port
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        // print error message if binding fails
        perror("error binding socket");
        return -1;
    }
    // try to listen on socket
    if (listen(sock, numOfUsers) < 0) {
        // print error message if listening fails
        perror("error listening to a socket");
        return -1;
    }
    // store sock in sockNum
    sockNum = sock;
    // accept client connections and perform actions until acceptClient returns false
    while (true) {
        int client_sock = getSockPerClient();
        Data *d = new Data(client_sock);
        thread t(menu, client_sock, d);
        t.detach();
    }
    close(sock);
    return 0;
}

int Server::getSockPerClient() {
    // create sockaddr_in struct to store client address
    struct sockaddr_in client_sin;
    // initialize address length variable
    unsigned int addr_len = sizeof(client_sin);
    // try to accept a client connection
    int client_sock = accept(sockNum, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) {
        // print error message if accepting client connection fails
        perror("error accepting client");
        return 1;
    }
    return client_sock;
}

int Server::menu(int client_sock, Data *data) {
    // infinite loop to classify data sent by client
    while (true) {
        char *menu = "Welcome to the KNN classifier Server. Please choose an option:\n"
                     "1. upload an unclassified csv data file\n"
                     "2. algorithm settings\n"
                     "3. classify data\n"
                     "4. display results\n"
                     "5. download results\n"
                     "8. exit";
        sendBuffer(menu, client_sock);
        char buffer[size];
        char *check = getBuffer(buffer, client_sock);
        if (!strcmp(check, "1")) {
            UploadCommandServer up(data);
            up.execute();
        } else if (!strcmp(check, "2")) {
            SettingsCommandServer st(data);
            st.execute();
        } else if (!strcmp(check, "3")) {
            ClassifyCommandServer ccs(data);
            ccs.execute();
        } else if (!strcmp(check, "4")) {
            DisplayCommandServer dcs(data);
            dcs.execute();
        } else if (!strcmp(check, "5")) {
            thread t(runDownloadCommand, data);
            t.detach();
        } else if (!strcmp(check, "8")) {
            ExitCommandServer ecs(data->socketNum);
            ecs.execute();
            return 0;
        } else {

        }
    }
    cout << "HOW DID IT HAPPENED" << endl;
}

void Server::runDownloadCommand(Data *data) {
    DownloadCommandServer dwcs(data);
    dwcs.execute();
}

void Server::sendBuffer(char buffer[], int clientSock) {
    // try to send data in buffer to client
    int sent_bytes = send(clientSock, buffer, size, 0);
    if (sent_bytes < 0) {
        // print error message if sending data to client fails
        perror("error sending to client");
    }
}

char *Server::getBuffer(char *buffer, int clientSock) {
    // expected length of received data
    int expected_data_len = size;
    // clear memory of buffer
    memset(buffer, 0, size);
    // print message indicating that server is waiting for data from client
    cout << "waiting for receive by client" << endl;
    // try to receive data from client
    int read_bytes = recv(clientSock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // return empty string if connection is closed by client
        return nullptr;
    } else if (read_bytes < 0) {
        // return empty string if there is an error receiving data from client
        return nullptr;
    }
    return buffer;
}

char *Server::checkIfClientCloseConnection(char *buffer, int clientSock) {
    if (buffer[0] == '8' && buffer[1] == '\0') {
        string result = "close";
        // copy result to buffer
        strcpy(buffer, result.c_str());
        // try to send data in buffer to client
        int sent_bytes = send(clientSock, buffer, result.size(), 0);
        if (sent_bytes < 0) {
            // print error message if sending data to client fails
            perror("error sending to client");
        }
        // return closeClient
        return (char *) "closeClient";
    }
    return (char *) "continue";
}

string Server::serverClassify(int clientSock) {
    // initialize result to empty string
    string result = "";
    // create buffer to store received data
    char buffer[size];
    // gets the input to the buffer from the socket

    if (getBuffer(buffer, clientSock) == nullptr) {
        return "";
    }
    // create vector to store received data
    vector<double> vec;
    // num of neighbors
    int k;
    string disType = "o";
    // create stringstream object to parse received data
    istringstream iss(buffer);
    // check if client want to end the connection to server
    if (strcmp(checkIfClientCloseConnection(buffer, clientSock), "closeClient") == 0) {
        return "closeClient";
    }
    double num;
    int count = 0;
    // parse received data and store in vec
    while (iss >> num) {
        count++;
        vec.push_back(num);
    }
    // reset stringstream object
    iss.clear();
    // set stringstream object to beginning
    iss.seekg(0);
    // parse received data and store in disType and k
    for (int i = 0; i < count + 2; i++) {
        if (i < count) {
            iss >> num;
        } else if (i == count) {
            iss >> disType;
        } else {
            iss >> k;
        }
    }
    // print received data
    cout << iss.str() << endl;
    if (iss.fail()) {
        // set result to "invalid input" if parsing fails
        result = "invalid input";
        // copy result to buffer
        strcpy(buffer, result.c_str());
    } else {
        // classify received data and store result in result
        result = classification.vectorToClass(file, k, disType, vec);
        // copy result to buffer
        strcpy(buffer, result.c_str());
    }
    sendBuffer(buffer, clientSock);
    // return "good"
    return "good";
}

