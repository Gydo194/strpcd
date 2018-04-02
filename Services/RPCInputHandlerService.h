#include <iostream>

using namespace std;
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
    }

};
