#ifndef ACTIONS_H
#define ACTIONS_H

#include "../RPC/RPCCall.h"

namespace Actions {
    void testAction(rpccall request) {
        cout << "Got test event!" << endl;
        cout << "FD=" << request.sourcefd << " NAME=" << request.actionName << " ACTIONPARAM=" << request.params.at("action") << endl;
    } 
}

#endif //ACTIONS_H