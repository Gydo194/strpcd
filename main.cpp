#include <stdio.h>
#include <iostream>
#include "Services/RPCInputHandlerService.h"
#include "ServerCore/Server.h"
#include "RPC/RPCCall.h"

using namespace std;


int main(int argc, char **argv)
{
    printf("[strpcd] starting...\n");
    
    
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
