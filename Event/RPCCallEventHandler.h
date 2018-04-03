#ifndef RPCCALLEVENTHANDLER_H
#define RPCCALLEVENTHANDLER_H

#include <map>
#include <cstring>

#include "../RPC/RPCCall.h"

using namespace std;

class RPCCallEventHandler
{
public:
    RPCCallEventHandler();
    ~RPCCallEventHandler();
    struct rpcEventCallBack {
        void (*callBack)(rpccall);
    };
    void addEvent(string name, rpcEventCallBack event);
    //void addEvent(string name, void (*callback)(rpcEventCallBack)); //handle the struct creation inside
    void pushEvent(rpccall request);
private:
    map<string,rpcEventCallBack> events;
};

#endif // RPCCALLEVENTHANDLER_H //



/*
struct rpccall {
    map<string,string> params;
    uint16_t sourcefd;
};

*/