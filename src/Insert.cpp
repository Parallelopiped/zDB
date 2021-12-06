//
// Created by NaturalVStudio on 2021/12/6.
//

#define DEBUG_SWITCH

#include "Insert.h"
#include "DebugToolkit.hpp"
#include "core/Parser.hpp"
#include <utility>

void Insert::BootLoader(User *) {
    parseInsert(*this);
}

Insert::Insert(std::string account) : Operate(std::move(account)) {}

void Insert::parseInsert(User* user, Insert &insert) {
    std::regex insertP(R"(^insert\sinto\s(\w+)\((.+)\)\svalues\((.+)\))");
    std::smatch m_insert;
    bool found = regex_search(insert.account, m_insert, insertP);
    if (! found){
        Exception::RaiseException(0x00010004);
        return;
    }
#ifdef DEBUG_SWITCH
    DebugToolkit::RegexSearchOutput(m_insert);
#endif
    insert.name = m_insert.str(1);
    std::string headStr = m_insert.str(2), valueStr = Parser::regexDelete(m_insert.str(3), "\"");
    std::vector<std::string> headVec, valueVec;
    headVec = Parser::regexSplit(headStr, ",\\s?");
    valueVec = Parser::regexSplit(valueStr, ",");

    //if (user->userDataDictionary)
    Table* table = user->userDataDictionary.findTable(insert.name);

}
