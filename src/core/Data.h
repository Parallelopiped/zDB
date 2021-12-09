//
// Created by NaturalVStudio on 2021/11/10.
//

#ifndef ZDB_DATA_H
#define ZDB_DATA_H
#include <string>
#include <malloc.h>
#include <map>
typedef struct Node_{
    int row = 0, col = 0;
    Node_ *right{}, *down{};
    //int col_num;
    std::string data;
} Node;

class Data {
private:
    Node *head;
    Node *tail;
public:
    Data();
    void InsertRow(std::map<std::string, std::string>);
    void PrintData();
};


#endif //ZDB_DATA_H
