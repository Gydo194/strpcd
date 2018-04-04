#include "Actions.h"

void Actions::testAction(rpccall request)
{
    cout << "Got test event!" << endl;
    cout << "FD=" << request.connector.source_fd << " NAME=" << request.actionName << " ACTIONPARAM=" << request.params.at("action") << endl;
}
