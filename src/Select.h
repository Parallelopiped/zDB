//
// Created by NaturalVStudio on 2021/12/7.
//

#ifndef ZDB_SELECT_H
#define ZDB_SELECT_H

#include "Operate.hpp"
#include "User.hpp"

class Select: public Operate{
public:
    Table returnTable;
public:
    void BootLoader(User*) override;
    static Table* parseSelect(User*, Select& select);
public:
    explicit Select(const std::string&);
};


#endif //ZDB_SELECT_H
