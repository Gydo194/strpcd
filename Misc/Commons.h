#ifndef COMMONS_H
#define COMMONS_H

#include <cstring>

#include "../Event/EventHandler.h"
#include "../RPC/RPCCall.h"
#include "../ServerCore/Server.h"

using namespace std;

extern EventHandler<string,rpccall> evh;
extern Server server;
#endif //COMMONS_H