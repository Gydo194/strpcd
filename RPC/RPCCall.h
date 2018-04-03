#ifndef RPCCALL_H
#define RPCCALL_H

#include <map>
#include <cstring>
#include <cstdint>

using namespace std;

struct rpccall {
    map<string,string> params;
    uint16_t sourcefd;
    string actionName; 
};

#endif // RPCCALL_H
