#include <stdio.h>
#include <iostream>
#include "Services/RPCInputHandlerService.h"
#include "ServerCore/Server.h"
#include "RPC/RPCCall.h"
#include "Actions/Actions.h"
#include "Event/RPCCallEventHandler.h"

using namespace std;


int main(int argc, char **argv)
{
    printf("[strpcd] starting...\n");
    
    
    RPCCallEventHandler evh;
    
    rpccall r;
    r.actionName = "test";
    r.sourcefd = 0;
    r.params = map<string,string>();
    //
    
    RPCCallEventHandler::rpcEventCallBack e;
    e.callBack = &Actions::testAction;
    

    evh.addEvent("test",e);
    evh.pushEvent(r);
    
    

    
    Server rpcCore = Server(9034);
    
    rpcCore.setNewConnectionCallback(&rpcInputHandler::handleRpcConnectEvent);
    rpcCore.setDisconnectCallback(&rpcInputHandler::handleRpcDisconnecEvent);
    rpcCore.setReceiveCallBack(&rpcInputHandler::handleRpcInputEvent);
    
    rpcCore.init();
    
    while(true) {
        rpcCore.loop();
    }
	
	return 0;
}
