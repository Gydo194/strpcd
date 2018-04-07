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
Server server;
int main(int argc, char **argv)
{
    printf("[strpcd] starting...\n");
    
    //call action loader
    ActionLoader::loadActions();
    
    server.setNewConnectionCallback(&rpcInputHandler::handleRpcConnectEvent);
    server.setDisconnectCallback(&rpcInputHandler::handleRpcDisconnecEvent);
    server.setReceiveCallBack(&rpcInputHandler::handleRpcInputEvent);
    
    server.init();
    
    while(true) {
        server.loop();
    }
	
	return 0;
}
