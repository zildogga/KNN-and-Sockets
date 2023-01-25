#ifndef ADVANCED_PROGRAMMING_1_PROJECT_CLI_H
#define ADVANCED_PROGRAMMING_1_PROJECT_CLI_H
#include "DistanceClass.h"
#include <sstream>
#include "Command.h"
#include "SettingsCommandClient.h"
#include "UploadCommandClient.h"
#include "ExitCommandClient.h"
#include "ClassifyCommandClient.h"
#include "DisplayCommandClient.h"
#include "DownloadCommandClient.h"
#include "BeforeDownloadCommandClient.h"
#include "thread"
#include "queue"
#include "mutex"
using namespace std;

class CLI {
public:
    int sock;
    void start();
    void downloadCommand(int sock, string path);
    CLI(int sock2) {
        sock = sock2;
    }
private:
    CLI() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_CLI_H
