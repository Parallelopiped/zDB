//
// Created by NaturalVStudio on 2021/12/6.
//

#ifndef ZDB_INDEX_H
#define ZDB_INDEX_H

#include "Table.h"
#include <string>
#include <map>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

class Index {
public:
    std::string indexName;
    std::string tableName;
    std::string attrbName;
    std::map<std::string, int> map_index; //允许不同表同名索引

public:
    void printIndex() const;
    void creatIndex(const Table&);
};


#endif //ZDB_INDEX_H
