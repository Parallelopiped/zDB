//
// Created by NaturalVStudio on 2021/12/4.
//

#ifndef ZDB_DICTIONARY_H
#define ZDB_DICTIONARY_H

#include <vector>
#include <map>
#include <string>
#include "Table.h"
#include "Index.h"
//#include "User.hpp"

class Dictionary {
public:
    std::map<std::string, Table> tableDic;
    std::vector<std::string> viewDic;
    std::map<std::string, Index> indexDic;
    std::string owner;

public:
    bool addTable(const Table&);
    bool addView(const std::string&);
    bool addIndex(const Index&);
    Table* findTable(const std::string&);
    //static void addTableList();
public:

};


#endif //ZDB_DICTIONARY_H
