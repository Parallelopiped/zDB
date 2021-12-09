//
// Created by NaturalVStudio on 2021/12/10.
//

#include "Delete.h"

Delete::Delete(const std::string& account) : Operate(account){}

void Delete::BootLoader(User *) {
    ;
}

Table *Delete::parseDelete(User *, Delete &aDelete) {
    return nullptr;
}
