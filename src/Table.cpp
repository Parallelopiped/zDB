//
// Created by NaturalVStudio on 2021/11/10.
//

#include <fstream>
#include "Table.h"

//bool Table::CreateTable(const std::string& raw_expression) {
//
//    return true;
//}


void Table::addHead(const std::string& headname, const std::string& type, Token integrity, const std::string& addition) {
    std::vector<Token> intg;
    intg.push_back(integrity);
    Attributes attributes = (Attributes){headname, type, intg, addition};
    head.push_back(attributes);
}

void Table::printTable() {
    for (int i = 0; i < this->head.size(); ++i) {
        std::cout << "Table: " << name << std::endl;
        std::cout << owner << std::endl;
        std::cout << "name:" << head[i].headname << " type:" << head[i].type
        << " integ:";
        for (auto & j : head[i].integrity) {
            std::cout << j << ",";
        }
        std::cout << " add:" << head[i].addition << std::endl;
    }
}

void Table::setKey(const std::vector<std::string>& key, Token integrity, const std::string& add) {
    for (int i = 0; i < this->head.size(); ++i) {
        for (const auto & j : key) {
            if (head[i].headname == j) {
                head[i].integrity.push_back(integrity);
                if (integrity == TOKEN_FOREIGN_KEY){
                    head[i].addition = add;
                }
            }
        }
    }
}

void Table::saveTableCSV() {
    std::ofstream ofile;
    std::string filepath = "../data/table_" + name + ".csv";
    std::cout << "table save to " << filepath << std::endl;
    ofile.open(filepath, std::ios::out | std::ios::trunc);//判断.csv文件是否存在，不存在则建立，每次都会删除之前文件，重新生成，不可复写
    ofile << this->name << std::endl;
    ofile << this->owner << std::endl;
    ofile << this->head.size() << std::endl;
    for (int i = 0; i < this->head.size(); ++i){
        ofile << head[i].headname << "," << head[i].type << ",";
        for (auto & j : head[i].integrity) {
            ofile << j << " ";
        }
        ofile << "," << head[i].addition << std::endl;
    }
    ofile << data.size() << std::endl;
    if (! data.empty()){
        for (auto & i : data) {
            std::vector<std::string> tmp = i.value;
            for (auto & j : tmp) {
                ofile << j << ",";
            }
            ofile << std::endl;
        }
    }
    ofile.close();
}

void Table::insertTuple(const std::vector<std::string>& headname,
                        const std::vector<std::string>& value      ) {
    std::vector<int> col_index; //插入列的顺序
    bool headname_hit = false;
    for (const auto & i : headname) {
        for (int j = 0; j < head.size(); ++j) {
            if (i == head[j].headname){
                col_index.push_back(j);
                headname_hit = true;
                break;
            }
        }
        if (! headname_hit){
            Exception::RaiseException(0x00020002);
            return;
        }
    }
    Tuple newTuple;
    for (int i = 0; i < head.size(); ++i) {
        newTuple.value.emplace_back(" ");
    }
    for (int i = 0; i < col_index.size(); ++i) {
        newTuple.value[col_index[i]] = value[i]; //按head顺序存储插入的数据
    }
    data.push_back(newTuple);
    this->saveTableCSV();
}

const std::string &Table::getOwner() const {
    return owner;
}

void Table::setOwner(const std::string &owner) {
    Table::owner = owner;
}

const std::string &Table::getName() const {
    return name;
}

void Table::setName(const std::string &name_) {
    Table::name = name_;
}
