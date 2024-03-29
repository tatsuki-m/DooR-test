#ifndef DOOR_WORKER_H_
#define DOOR_WORKER_H_

#include <iostream>
#include <string>
#include <thread>

#include "door_ipc/shared_memory.h"
#include "door_ipc/shared_key.h"
#include "door_ipc/shared_packet_information.h"
#include "door_ipc/dpi.h"
#include "door_ipc/sync_semaphore.h"
#include "door_ipc/socket_server.h"
#include "door_api/door_socket.h"

class DoorWorker
{
public:
    DoorWorker(std::string, DoorSocketType);
    ~DoorWorker();
private:
    void run(std::string, DoorSocketType);
    std::thread th_;
    DoorSocketType type_;
    std::string sharedDataKey_;
    void writeDataToShm();
    void sendUds();
    void sendTcp();
};

#endif

