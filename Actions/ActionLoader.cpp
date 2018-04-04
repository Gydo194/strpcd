#include "ActionLoader.h"
#include "Actions.h"

void ActionLoader::loadActions()
{
    //build an event target (callback to be fired when event is called, wrapped in 'target' struct)
    EventHandler<string,rpccall>::target testEventTarget;
    testEventTarget.callback = &Actions::testAction; //bind action function

    evh.attachEventListener("test",testEventTarget); //attach the target listener to event handler
}
