#include <string>
#include <iostream>
#include <phpcpp.h>

#include "utils.h"
/**
 *  Namespace to use
 */
using namespace std;

// symbols are exported according to the "C" language
extern "C"
{
// export the "get_module" function that will be called by the Zend engine
PHPCPP_EXPORT void *get_module() {
    // create extension
    static Php::Extension extension("Hardcore", "0.0.1");

    // define the functions

    // define classes
    Php::Class <Hardcore::Utils> utils("Utils");
    // utils.method("pure", &Utils::pure, {Php::ByVal("v", Php::Type::Null)});
    //myCustomClass.method<&MyCustomClass::__construct>("__construct");

    extension.add(std::move(utils));

    return extension.module();
}
}