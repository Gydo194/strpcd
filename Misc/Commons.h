#ifndef COMMONS_H
#define COMMONS_H

#include <cstring>

#include "../Event/EventHandler.h"
#include "../RPC/RPCCall.h"

using namespace std;

extern EventHandler<string,rpccall> evh;

#endif //COMMONS_H