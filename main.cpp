#include <stdio.h>
#include <iostream>

#include "Services/RPCInputHandlerService.h"
#include "ServerCore/Server.h"
#include "RPC/RPCCall.h"
#include "Event/EventHandler.h"
#include "Misc/Commons.h"
#include "Actions/ActionLoader.h"

using namespace std;

//define the extern
EventHandler<string,rpccall> evh;
int main(int argc, char **argv)
{
    printf("[strpcd] starting...\n");
    
    //call action loader
    ActionLoader::loadActions();
    
    

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
