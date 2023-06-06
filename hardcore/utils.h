//
// Created by C Archer on 6/6/23.
//

#ifndef PHP_CPP_UTILS_H
#define PHP_CPP_UTILS_H

#endif //PHP_CPP_UTILS_H
#pragma once

#include <phpcpp.h>

class Utils : public Php::Base {
public:
    /**
     *  Static method: pure
     */
    static Php::Value pure(Php::Parameters &params) {
        Php::Value v = params[0];

        if (!v.isScalar()) {
            return v;
        }

        bool isResource = Php::call("is_resource", v);
        if (v.isNumeric() || v.isBool() || isResource) {
            return v;
        }

        // is_array or is_object
        std::string str = v.stringValue();
        str.erase(std::remove_if(str.begin(), str.end(), [](char c) {
            return std::isspace(static_cast<unsigned char>(c)) || c == '\'' || c == '\"' || c == '\r' || c == '\t' ||
                   c == '\n';
        }), str.end());

        return str;
    }
};
