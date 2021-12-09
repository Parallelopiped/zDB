//
// Created by NaturalVStudio on 2021/12/10.
//

#ifndef ZDB_DELETE_H
#define ZDB_DELETE_H

#include "Operate.hpp"

class Delete: public Operate{
public:
    void BootLoader(User*) override;
    static Table* parseDelete(User*, Delete& aDelete);
public:
    explicit Delete(const std::string&);
};


#endif //ZDB_DELETE_H
