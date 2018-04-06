#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <cstring>
#include <map>

#include "Client.h"

using namespace std;

class ClientManager
{
public:
    ClientManager();
    ~ClientManager();
    
    static map<string,client> clients;
    
    static void registerClient(string name, client c);
    static void unregisterClient(string name);
    

};

#endif // CLIENTMANAGER_H
