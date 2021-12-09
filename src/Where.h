//
// Created by NaturalVStudio on 2021/12/9.
//

#ifndef ZDB_WHERE_H
#define ZDB_WHERE_H

#include "Table.h"
#include "User.hpp"

class Where {
public:
    Table returnTable;
    std::string account;
    User* user;
    std::vector<std::string> tableName;
    std::vector<std::string> attrbName;
public:
     Table* parseWhere();
public:
    Where(User*, const std::string&, const std::vector<std::string>&, const std::vector<std::string>&);
};


#endif //ZDB_WHERE_H
