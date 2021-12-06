//
// Created by NaturalVStudio on 2021/12/5.
//

#ifndef ZDB_USER_HPP
#define ZDB_USER_HPP

#include "Dictionary.h"
#include <string>

class User {
public:
    std::string userName;
    Dictionary userDataDictionary;
public:
    User(const std::string& username){
        userName = username.empty() ? "ahh" : username;
    }
};


#endif //ZDB_USER_HPP
