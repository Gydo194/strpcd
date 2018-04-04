#include <iostream>
#include "../Parsers/ProtocolHandler.h"
#include "../RPC/RPCCall.h"
#include "../Misc/Commons.h"

#define RPC_ACTION_PARAM_NAME "action"

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
        //rpc param data is in ph.values
        
        rpccall request;
        request.connector.source_fd = fd;
        request.params = ph.values;
        
        
        try {
            request.actionName = ph.values.at(RPC_ACTION_PARAM_NAME);
            //cout << "setting action name =" << request.actionName;
        } catch(out_of_range oor) {
            cout << "HandleInputEvent(): caught out of range; no action parameter defined?" << endl;
        }
        
        //push event
        evh.pushEvent(request.actionName,request);
        ph.values.clear(); // IMPORTANT: clear the valuemap!!
        
    }

};
