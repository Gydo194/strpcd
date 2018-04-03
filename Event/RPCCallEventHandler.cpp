#include "RPCCallEventHandler.h"
#include "../RPC/RPCCall.h"
#include <cstring>
#include <iostream>


using namespace std;

RPCCallEventHandler::RPCCallEventHandler()
{
}

RPCCallEventHandler::~RPCCallEventHandler()
{
}

void RPCCallEventHandler::addEvent(string name, rpcEventCallBack eventcb) {
    events.insert(pair<string,rpcEventCallBack>(name,eventcb));
}

/*
void RPCCallEventHandler::addEvent(string name, void (*cb)(rpcEventCallBack)) {
    rpcEventCallBack r;
    r.callBack = cb;
    addEvent(name,r); 
}
*/

void RPCCallEventHandler::pushEvent(rpccall request) {
    cout << "got push event" << endl;
    try {
        events.at(request.actionName).callBack(request);
    } catch(out_of_range oor) {
        cout << "Event push got out of range; event does not exist" << endl;
    }
}