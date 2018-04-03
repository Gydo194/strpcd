#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <map>

using namespace std;

template<class K, class E> //KeyType, EventType
class EventHandler
{
public:

    struct target  { //event target (function target)
        void (*callback)(E);
    };

    void attachEventListener(K key, target ev) {
        events.insert((pair<K,target>(key,ev)));
    }

    void detachEventListener(K key) {
        events.erase(key);
    }

    void pushEvent(K key, E argument) {
        try {
            events.at(key).callback(argument);
        } catch(out_of_range oor) {
            return;
        }
    }

private:
    map<K,target> events;
};


#endif //EVENTHANDLER_H
