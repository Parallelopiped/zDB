//
// Created by NaturalVStudio on 2021/12/9.
//

#include <regex>
#include "Where.h"
#include "Select.h"
#include "core/Parser.hpp"
#include "DebugToolkit.hpp"

#define DEBUG_SWITCH


Where::Where(User* user, const std::string& account,
             const std::vector<std::string>& tablename,
             const std::vector<std::string>& attrbname){
    this->user = user;
    this->account = account;
    this->tableName = tablename;
    this->attrbName = attrbname;
}

Table* Where::parseWhere() {
    std::vector<Table*> usedTable;
    //usedTable.reserve(this->tableName.size());
    for (auto & i : tableName) {
        usedTable.push_back(user->userDataDictionary.findTable(i));
    }
    std::regex whereP(R"((in))");
    std::smatch m_where;
    bool found_in = regex_search(account, m_where, whereP);
#ifdef DEBUG_SWITCH
    std::cout << "in: " << found_in << std::endl;
    DebugToolkit::RegexSearchOutput(m_where);
#endif
    if (found_in){
        std::string innerAccount = m_where.suffix().str();
        innerAccount = Parser::deleteHTChar(innerAccount, ';');
        innerAccount = Parser::deleteHTChar(innerAccount, '(');
        innerAccount = Parser::deleteHTChar(innerAccount, ')');
        returnTable = *Select::parseSelect(user, * new Select(innerAccount)); //实现嵌套查询
        return &returnTable;
    }
    ;
    return nullptr;
}
