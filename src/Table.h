//
// Created by NaturalVStudio on 2021/11/10.
//

#ifndef ZDB_TABLE_H
#define ZDB_TABLE_H

#include "core/Data.h"
#include "core/Expression.h"
#include <vector>
#include <set>
#include <string>

class Table {
public:
    typedef struct Attr{
        std::string headname{};
        std::string type{};
        std::vector<Token> integrity; //完整性约束
        std::string addition{}; //附加字段，如存放外码
    }Attributes;

    std::string name; //table name
    std::vector<Attributes> head; //表头
    std::string owner;


    /**
     * 定义元组结构
     */
    struct Tuple{
        std::vector<std::string> value;
        //union
    };

    std::vector<Tuple> data; //表单结构

public:
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getOwner() const;
    void setOwner(const std::string &owner);

    void addHead(const std::string& headname, const std::string& type, Token integrity, const std::string& addition);
    void setKey(const std::vector<std::string>& key, Token, const std::string& addition);
    void insertTuple(const std::vector<std::string>&, const std::vector<std::string>&);
    void printHead();
    void saveTableCSV();
};


#endif //ZDB_TABLE_H
