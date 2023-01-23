
#include "CLI.h"

void CLI::start() {
    while (true) {
        // create buffer to store received data
        char buffer[SIZE_OF_BUFFER];
        // gets the input to the buffer from the socket
        // if nullptr was returned
        strcpy(buffer, scio.read2().c_str());
        if (buffer == nullptr) {
            break;
        } else if (strcmp(buffer, "close") == 0) {
            // close socket and return 0 if "close" is received from server
            close(sock);
            return;
        } else {
            cout << buffer << endl;
            string choice;
            cin >> choice;
            if (choice == "1") {
                UploadCommandClient ucc(sock, scio);
                ucc.execute();
            }
            if (choice == "2") {
                SettingsCommandClient scc(sock, scio);
                scc.execute();
            }
            if (choice == "3") {
                ClassifyCommandClient scc(sock, scio);
                scc.execute();
            }
            if (choice == "4") {
                DisplayCommandClient dcc(sock, scio);
                dcc.execute();
            }
            if (choice == "5") {
                string path;
                BeforeDownloadCommandClient bdcc(sock, &path, scio);
                bdcc.execute();
                thread downloadThread(&CLI::downloadCommand, this, sock, path, scio);
                downloadThread.detach();
            }
            if (choice == "8") {
                ExitCommandClient ecc(sock, scio);
                ecc.execute();
                break;
            }
        }
    }
    // close socket
    close(sock);
    return;
}
void CLI::downloadCommand(int sock, string path, SocketIO scio) {
    DownloadCommandClient dwcc(sock, path, scio);
    dwcc.execute();
}