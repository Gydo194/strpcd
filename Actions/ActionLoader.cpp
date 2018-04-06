#include "ActionLoader.h"
#include "Actions.h"

void ActionLoader::loadActions()
{
    //build an event target (callback to be fired when event is called, wrapped in 'target' struct)
    EventHandler<string,rpccall>::target testEventTarget;
    testEventTarget.callback = &Actions::testAction; //bind action function

    evh.attachEventListener("test",testEventTarget); //attach the target listener to event handler
    
    
    EventHandler<string,rpccall>::target registerEventTarget;
    EventHandler<string,rpccall>::target sendEventTarget;
    
    registerEventTarget.callback = &Actions::register_client;
    sendEventTarget.callback = &Actions::handle_send;
    
    evh.attachEventListener("register",registerEventTarget);
    evh.attachEventListener("send",sendEventTarget);
    
}
