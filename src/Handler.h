//
// Created by NaturalVStudio on 2021/11/10.
//

#include <string>
#include "core/Expression.h"
#include "User.hpp"
#include "Operate.hpp"

#ifndef ZDB_HANDLER_H
#define ZDB_HANDLER_H

#endif //ZDB_HANDLER_H

class Handler{
public:
    Operate* operate;
public:
    Handler(const std::string&, User*);
};