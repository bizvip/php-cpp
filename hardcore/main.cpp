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
    static Php::Extension extension("Hardcore", "1.0");
    extension.setAuthor("Danny Archer")
    extension.setDescription("worksvip@pm.me")

    // define the functions

    // define classes
    Php::Class <Utils> utils("Utils");
    utils.method("pure", &Utils::pure, {Php::ByVal("v", Php::Type::Null)});
    //myCustomClass.method<&MyCustomClass::__construct>("__construct");

    // add to extension
    extension.add(std::move(utils));

    // return the module entry
    return extension.module();
}
}

