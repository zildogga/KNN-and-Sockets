#ifndef ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDSERVER_H
#define ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDSERVER_H
#include "Command.h"
#include "Data.h"
#include "SocketIO.h"
#include "StandardIO.h"
#include "thread"
class DownloadCommandServer: public Command{
public:
    Data *data;
    void execute() override;
    DownloadCommandServer(Data *d){
        data = d;
    };
private:
    DownloadCommandServer() = default;
};


#endif //ADVANCED_PROGRAMMING_1_PROJECT_DOWNLOADCOMMANDSERVER_H
