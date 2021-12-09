//
// Created by NaturalVStudio on 2021/12/4.
//

#include <fstream>
#include "Dictionary.h"
#include "core/Exception.h"

bool Dictionary::addTable(const Table& table) {
    if (tableDic.find(table.name) != tableDic.end()){
        Exception::RaiseException(0x00020001);
        return false;
    }
    tableDic[table.name] = table;
    return true;
}

bool Dictionary::addView(const std::string& view) {
    this->viewDic.push_back(view);
    return true;
}

bool Dictionary::addIndex(const Index& index) {
    if (indexDic.find(index.indexName) != indexDic.end()){
        Exception::RaiseException(0x00030002);
        return false;
    }
    indexDic[index.indexName] = index;
    return true;
}

Table *Dictionary::findTable(const std::string& name) {
    if (tableDic.find(name) == tableDic.end()){
        Exception::RaiseException(0x11110001);
        //
        if (0){
            Exception::RaiseException(0x00030001);
            return nullptr;
        }
        return nullptr;
    }
    return &tableDic[name];
}

void Dictionary::saveAuthority() {
    std::ofstream ofile;
    std::string filepath = "../data/authority_" + owner + ".csv";
    std::cout << "authority save to " << filepath << std::endl;
    ofile.open(filepath, std::ios::out | std::ios::trunc);
    ofile << owner << std::endl;
    auto it = tableDic.begin();
    for (it = tableDic.begin(); it != tableDic.end(); it++){
        ofile << (it->first) << "," << "777" << std::endl;
    }
    ofile.close();
}

void Dictionary::printDic() {
    puts("database:\n-------");
    puts("table:");
    auto it = tableDic.begin();
    for (it = tableDic.begin(); it != tableDic.end(); it++){
        std::cout << (it->first) << std::endl;
    }
    puts("view:");
    for (auto & i : viewDic) {
        std::cout << i << std::endl;
    }
    puts("index:");
    it = tableDic.begin();
    for (it = tableDic.begin(); it != tableDic.end(); it++){
        std::cout << (it->first) << std::endl;
    }
}

View *Dictionary::findView(const string &) {
    return nullptr;
}

Index *Dictionary::findIndex(const string &) {
    return nullptr;
}
