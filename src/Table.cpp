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

void Table::printHead() {
    for (int i = 0; i < this->head.size(); ++i) {
        std::cout << "***Table " << name << std::endl;
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
    std::string filepath = "../data/" + name + ".csv";
    std::cout << "table save to " << filepath << std::endl;
    ofile.open(filepath, std::ios::out | std::ios::trunc);//判断.csv文件是否存在，不存在则建立，每次都会删除之前文件，重新生成，不可复写
    for (int i = 0; i < this->head.size(); ++i){
        ofile << head[i].headname << "," << head[i].type << ",";
        for (auto & j : head[i].integrity) {
            ofile << j << " ";
        }
        ofile << "," << head[i].addition << std::endl;
    }
    ofile.close();
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