#include "ClientManager.h"
#include <map>
using namespace std;

map<string,client> ClientManager::clients; //declare the static map

ClientManager::ClientManager()
{
}

ClientManager::~ClientManager()
{
}


void ClientManager::registerClient(string name, client c) {
    clients.insert(pair<string,client>(name,c));
}


void ClientManager::unregisterClient(string name) {
    clients.erase(name);
}