#ifndef PHP_CPP_UTILS_H
#define PHP_CPP_UTILS_H

#endif //PHP_CPP_UTILS_H
#pragma once

#include <phpcpp.h>

namespace Hardcore {
    class Utils : public Php::Base {
    public:
        Php::Value pure(Php::Parameters &parameters) {
            Php::Value v = parameters[0];

            // handle non-scalar values
            if (!v.isScalar()) {
                return v;
            }

            // handle integer, boolean and resource values
            bool isResource = Php::call("is_resource", v).boolValue();
            if (v.isNumeric() || v.isBool() || isResource) {
                return v;
            }

            // handle string values
            if (v.isString()) {
                std::string str = v.stringValue();
                str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
                str.erase(std::remove(str.begin(), str.end(), '\''), str.end());
                str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
                str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
                str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
                str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
                return str;
            }

            return nullptr;
        }
    };
}
