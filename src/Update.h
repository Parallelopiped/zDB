//
// Created by NaturalVStudio on 2021/12/10.
//

#ifndef ZDB_UPDATE_H
#define ZDB_UPDATE_H

#include "Operate.hpp"

class Update: public Operate{
public:
    void BootLoader(User*) override;
    static Table* parseUpdate(User*, Update& update);
public:
    explicit Update(const std::string&);
};


#endif //ZDB_UPDATE_H
