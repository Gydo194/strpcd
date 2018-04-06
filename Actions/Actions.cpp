#include <map>

#include "Actions.h"
//#include "Client/Client.h"
#include "Client/ClientManager.h"
#include "Client/Client.h"
#include "../ServerCore/Server.h"
#include "../Misc/Commons.h"

using namespace std;

void Actions::testAction(rpccall request)
{
    cout << "Got test event!" << endl;
    cout << "FD=" << request.connector.source_fd << " NAME=" << request.actionName << " ACTIONPARAM=" << request.params.at("action") << endl;
}

void Actions::register_client(rpccall request)
{
    string name = "";
    try {
        name = request.params.at(CLIENT_ADDR_PARAM_NAME);
    } catch(out_of_range oor) {
        cout << "Cannot get '" << CLIENT_ADDR_PARAM_NAME << "' parameter!" << endl;
    }

    client c;
    c.connector = request.connector;
    ClientManager::registerClient(name,c);
}

void Actions::unregister_client(rpccall request)
{
    
}


void Actions::handle_send(rpccall request) {
    string message;
    string dest;
    
    try {
        // use a function with pointer arguments to get the parameter, supplying default in case of failure (catch OOR)
        message = request.params.at(CLIENT_MSG_PARAM_NAME);
        dest = request.params.at(CLIENT_MSG_DEST_PARAM_NAME);
    } catch(out_of_range oor) {
        cout << "missing msg or dest param" << endl;
    }
    
    
    char *m = (char*) malloc(message.size());
    bzero(m,strlen(m)); //note to self: always zero malloc()'ed data!
    
    strncpy(m,message.c_str(),message.size());
    printf("send buffer value = '%s'\n",m);
    
    
    client destClient;
    try {
        destClient = ClientManager::clients.at(dest);
    } catch(out_of_range oor) {
        cout << "could not load client from manager map" << endl;
    }
    
    
    int sent = server.sendMessage(destClient.connector,m);
    free(m);
    
   
    
    printf("Sent '%d' bytes to client '%s' w/fd '%d'.\n",sent,dest.c_str(),destClient.connector.source_fd);
    
    //server.sendTo(request.connector.source_fd,message.c_str()); //build wrapper function using char* and string*, using server::connector instead of its contained fd
}
