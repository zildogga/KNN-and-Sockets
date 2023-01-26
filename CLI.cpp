
#include "CLI.h"

void CLI::start() {
    while (true) {
        // create buffer to store received data
        char buffer[SIZE_OF_BUFFER];
        // gets the input to the buffer from the socket
        // if nullptr was returned
        SocketIO scio(sock);
        strcpy(buffer, scio.read().c_str());
        if (buffer == nullptr) {
            break;
        } else if (buffer == "") {
            close(sock);
            return;
        } else if (strcmp(buffer, "close") == 0) {
            // close socket and return 0 if "close" is received from server
            close(sock);
            return;
        } else {
            cout << buffer << endl;
            string choice;
            cin >> choice;
            if (choice == "1") {
                UploadCommandClient ucc(sock);
                ucc.execute();
            } else if (choice == "2") {
                SettingsCommandClient scc(sock);
                scc.execute();
            } else if (choice == "3") {
                ClassifyCommandClient scc(sock);
                scc.execute();
            } else if (choice == "4") {
                DisplayCommandClient dcc(sock);
                dcc.execute();
            } else if (choice == "5") {
                string path;
                BeforeDownloadCommandClient bdcc(sock, &path);
                bdcc.execute();
                downloadCommand(sock, path);
            } else if (choice == "8") {
                ExitCommandClient ecc(sock);
                ecc.execute();
                break;
            } else{
                scio.write("wrong option");
                cout << "wrong option" << endl;
                scio.read();
            }
        }
    }
    // close socket
    close(sock);
    return;
}
void CLI::downloadCommand(int sock, string path) {
    DownloadCommandClient dwcc(sock, path);
    dwcc.execute();
}