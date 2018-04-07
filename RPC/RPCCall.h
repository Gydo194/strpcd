#ifndef RPCCALL_H
#define RPCCALL_H

#include <map>
#include <cstring>
#include <cstdint>

#include "../ServerCore/Server.h"

using namespace std;

struct rpccall {
    map<string,string> params;
    struct Server::Connector connector;
    string actionName; 
};

#endif // RPCCALL_H
