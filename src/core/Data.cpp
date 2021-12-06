//
// Created by NaturalVStudio on 2021/11/10.
//

#include <iostream>
#include "Data.h"


Data::Data() {

    head = new Node;

    head->col = head->row = 0;
    //std::cout << "ahjh" << std::endl;
    std::string s = "HEAD";
    head->data = s;
    //strcpy(, head->data);
    //std::cout << "ahjh" << std::endl;
    head->right = head->down = nullptr;
    tail = head;
}

void Data::InsertRow(std::map <std::string, std::string> line) {
    std::map<std::string, std::string>::iterator it;

    for(it = line.begin(); it != line.end(); it++) {
        Node *cur;
        cur = new Node;
        tail->right = cur;

        cur->data = it->second;

        tail = cur;
    }
    tail->right = nullptr;
}

/**
 * TEST ONLY
 */
void Data::PrintData() {
    Node *cur = head->right;
    while(cur != nullptr){
        std::cout << cur->data << " ";
        cur = cur->right;
    }
}
