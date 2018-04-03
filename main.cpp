#include <stdio.h>
#include <iostream>

#include "Services/RPCInputHandlerService.h"
#include "ServerCore/Server.h"
#include "RPC/RPCCall.h"
#include "Actions/Actions.h"
#include "Event/EventHandler.h"
#include "Misc/Commons.h"

using namespace std;

//define the extern
EventHandler<string,rpccall> evh;
int main(int argc, char **argv)
{
    printf("[strpcd] starting...\n");
    
    //build an event target (callback to be fired when event is called, wrapped in 'target' struct)
    EventHandler<string,rpccall>::target testEventTarget;
    testEventTarget.callback = &Actions::testAction; //bind action function
    
    evh.attachEventListener("test",testEventTarget); //attach the target listener to event handler
    
    
    

    //return 0;
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
