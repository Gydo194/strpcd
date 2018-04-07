#ifndef ACTIONS_H
#define ACTIONS_H

#include "../RPC/RPCCall.h"


#define CLIENT_ADDR_PARAM_NAME "name"
#define CLIENT_MSG_PARAM_NAME "message"
#define CLIENT_MSG_DEST_PARAM_NAME "destination"

namespace Actions {
    void testAction(rpccall request);
    void register_client(rpccall request);
    void unregister_client(rpccall request);
    void handle_send(rpccall request);
}

#endif //ACTIONS_H