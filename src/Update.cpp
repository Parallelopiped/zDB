//
// Created by NaturalVStudio on 2021/12/10.
//

#include "Update.h"
#include "DebugToolkit.hpp"
#include "Where.h"

#define DEBUG_SWITCH

Update::Update(const std::string& account) : Operate(account){}

void Update::BootLoader(User* user) {
    parseUpdate(user, *this);
}

Table *Update::parseUpdate(User* user, Update& update) {
    std::regex updateP(R"(update\s(\w+)\sset\s(\w+)\s=\s\"(\w+)\"\swhere)");
    std::smatch m_update;
    bool found_in = regex_search(update.account, m_update, updateP);
#ifdef DEBUG_SWITCH
    DebugToolkit::RegexSearchOutput(m_update);
#endif
    std::string where_account = m_update.suffix().str();
    std::vector<std::string> tableName, attrbName;
    tableName = Parser::regexSplit(m_update.str(1), ",");
    attrbName = Parser::regexSplit(m_update.str(2), ",");
    auto* where = new Where(user, update.account, tableName, attrbName);
    where->parseWhere();
    return nullptr;
}
