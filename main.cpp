#include <stdio.h>
#include "Services/RPCInputHandlerService.h"
#include "StTCPServer/Server.h"

int main(int argc, char **argv)
{
   
    printf("starting...\n");
    
    
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
