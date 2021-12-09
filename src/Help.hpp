//
// Created by NaturalVStudio on 2021/12/10.
//

#ifndef ZDB_HELP_HPP
#define ZDB_HELP_HPP

#include "Dictionary.h"
#include "User.hpp"
#include "View.h"

class Help {
public:
    //static void help
    static void helpDatabase(User* user){
        user->userDataDictionary.printDic();
    }
    static void helpTable(User* user, const std::string& tablename){
        Table* table = user->userDataDictionary.findTable(tablename);
        table->printTable();
    }
    static void helpView(User* user, const std::string& viewname){
        View* view = user->userDataDictionary.findView(viewname);
        view->printView();
    }
    static void helpIndex(User* user, const std::string& indexname){
        Index* index = user->userDataDictionary.findIndex(indexname);
        index->printIndex();
    }
};


#endif //ZDB_HELP_HPP
