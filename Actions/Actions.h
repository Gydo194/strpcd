#ifndef ACTIONS_H
#define ACTIONS_H

#include "../RPC/RPCCall.h"

namespace Actions {
    void testAction(rpccall request) {
        cout << "Got test event!" << endl;
    } 
}

#endif //ACTIONS_H