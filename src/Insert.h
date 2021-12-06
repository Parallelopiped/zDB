//
// Created by NaturalVStudio on 2021/12/6.
//

#ifndef ZDB_INSERT_H
#define ZDB_INSERT_H

#include "Operate.hpp"

class Insert: public Operate{
public:
    void BootLoader(User*) override;
    static void parseInsert(Insert& insert);
public:
    explicit Insert(std::string account);

};


#endif //ZDB_INSERT_H
