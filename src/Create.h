//
// Created by NaturalVStudio on 2021/12/3.
//

#ifndef ZDB_CREATE_H
#define ZDB_CREATE_H

#include "Operate.hpp"
#include "Table.h"
#include <regex>
#include <iostream>


class Create: public Operate{
public:
    void BootLoader(User*) override;
    static int parseCreate(Create& create);
    static Table* parseCreateTable(Create& create);

public:
    explicit Create(std::string account);
};


#endif //ZDB_CREATE_H
