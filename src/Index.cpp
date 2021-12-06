//
// Created by NaturalVStudio on 2021/12/6.
//

#include "Index.h"
#include "iostream"

void Index::printIndex() const {
    std::cout << "***index:\n";
    std::cout << "tableName:" << this->tableName << std::endl;
    std::cout << "indexName:" << this->indexName << std::endl;
    std::cout << "attrbName:" << this->attrbName << std::endl;
    auto it = map_index.begin();
    for (it = map_index.begin(); it != map_index.end(); it++){
        std::cout << it->first << " -> " << it->second << std::endl;
    }
}

void Index::creatIndex(const Table& table) {
    int col_index = -1;
    for (int i = 0; i < table.head.size(); ++i) {
        if (table.head[i].headname == this->attrbName) col_index = i;
    }
    if (col_index == -1){
        Exception::RaiseException(0x00040001);
        return;
    }
    for (int i = 0; i < table.data.size(); ++i) {
        Table::Tuple tuple = table.data[i];
        this->map_index[tuple.value[col_index]] = i;
    }
}
