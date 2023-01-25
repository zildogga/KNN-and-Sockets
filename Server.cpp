#include "Server.h"

#define size 4096
#define numOfUsers 3
// This line creates a new Classification object
Classification classification;
ReadFile readFile;

int Server::startServer(string serverPort) {
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
    // accept client connections and perform actions until acceptClient returns false
    while (true) {
        int client_sock = getSockPerClient(sock);
        Data *d = new Data(client_sock);
        thread t(menu, client_sock, d);
        t.detach();
    }
    close(sock);
    return 0;
}

int Server::getSockPerClient(int sockNum) {
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
        char menu[size];
        string temp = "Welcome to the KNN classifier Server. Please choose an option:\n"
                      "1. upload an unclassified csv data file\n"
                      "2. algorithm settings\n"
                      "3. classify data\n"
                      "4. display results\n"
                      "5. download results\n"
                      "8. exit";
        strcpy(menu, temp.c_str());
        SocketIO sc(client_sock);
        sc.write(menu);
        string check = sc.read();
        if (check == "1") {
            UploadCommandServer up(data);
            up.execute();
        } else if (check == "2") {
            SettingsCommandServer st(data);
            st.execute();
        } else if (check == "3") {
            ClassifyCommandServer ccs(data);
            ccs.execute();
        } else if (check == "4") {
            DisplayCommandServer dcs(data);
            dcs.execute();
        } else if (check == "5") {
            DownloadCommandServer dwcs(data);
            dwcs.execute();
        } else if (check == "8") {
            ExitCommandServer ecs(data->socketNum);
            ecs.execute();
            return 0;
        } else {
            // add code in here!!!
            sc.write("wrong option");
        }
    }
    cout << "HOW DID IT HAPPENED" << endl;
}


