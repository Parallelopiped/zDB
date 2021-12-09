//
// Created by NaturalVStudio on 2021/12/10.
//

#ifndef ZDB_VIEW_H
#define ZDB_VIEW_H

#include "core/Data.h"
#include "core/Expression.h"
#include "core/Exception.h"

#include <vector>
#include <set>
#include <string>


class View {
public:
    std::string name;
    std::string account;
public:
    void saveView() const;
    void printView() const;
};


#endif //ZDB_VIEW_H
