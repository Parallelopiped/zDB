//
// Created by NaturalVStudio on 2021/12/7.
//

#include "Select.h"
#include "Where.h"
#include "DebugToolkit.hpp"
#include "core/Parser.hpp"
#define DEBUG_SWITCH

void Select::BootLoader(User* user) {
    parseSelect(user, *this);
}

Select::Select(const std::string& account) : Operate(account){}

Table* Select::parseSelect(User* user, Select &select) {
    std::regex selectP(R"(select\s(\w+)\sfrom\s(\w+)\s(\w+)?)");
    std::smatch m_select;
    bool found = regex_search(select.account, m_select, selectP);
#ifdef DEBUG_SWITCH
    DebugToolkit::RegexSearchOutput(m_select);
#endif
    if (m_select.str(3) == "where"){
        std::string where_account = m_select.suffix().str();
        std::vector<std::string> tableName, attrbName;
        tableName = Parser::regexSplit(m_select.str(1), ",");
        attrbName = Parser::regexSplit(m_select.str(2), ",");
        auto* where = new Where(user, select.account, tableName, attrbName);
        where->parseWhere();
    }
    return nullptr;
}
