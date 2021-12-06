//
// Created by NaturalVStudio on 2021/12/4.
//

#include "Dictionary.h"
#include "core/Exception.h"

bool Dictionary::addTable(const Table& table) {
    if (tableDic.find(table.name) == tableDic.end()){
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

Table *Dictionary::findTable(const std::string& name) {
    if (tableDic.find(name) == tableDic.end()){
        Exception::RaiseException(0x11110001);
        //
        if (0){
            Exception::RaiseException(0x00030001);
            return nullptr;
        }
    }
    return &tableDic[name];
}
