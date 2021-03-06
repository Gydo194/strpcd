#include <iostream>
#include "../Parsers/ProtocolHandler.h"
#include "../RPC/RPCCall.h"

using namespace std;
ProtocolHandler ph;

namespace rpcInputHandler
{
    void handleRpcConnectEvent(uint16_t fd)
    {
       cout << "Got rpc connect fd=" << fd << endl; 
    }
    
    void handleRpcDisconnecEvent(uint16_t fd) {
        cout << "Got rpc disconnect fd=" << fd << endl;
    }
    
    void handleRpcInputEvent(uint16_t fd, char *buffer) {
        cout << "Got input event from fd=" << fd << " with buffer '" << buffer << "'!" << endl;
        ph.processInput(buffer);
        //build rpc call here and process it further
        rpccall request;
        request.sourcefd = fd;
        request.params = ph.values;
        //here is your data to handle!!! ///////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\\\\\\\\\\\\\\
    }

};
