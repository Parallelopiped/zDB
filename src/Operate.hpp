//
// Created by NaturalVStudio on 2021/12/3.
//

#ifndef ZDB_OPERATE_HPP
#define ZDB_OPERATE_HPP


#include <string>
#include <utility>
#include <regex>
#include "core/Exception.h"
#include "core/Parser.hpp"
#include "User.hpp"

class Operate {
public:
    std::string account; // 语句
    std::string name; //操作对象名称
public:
    Operate(std::string account){
        this->account = std::move(account);
    }
public:
    virtual void BootLoader(User*){}
};



//void Operate::BootLoader() {
////not so important here...
//}

#endif //ZDB_OPERATE_HPP
