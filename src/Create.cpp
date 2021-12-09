//
// Created by NaturalVStudio on 2021/12/3.
//

#include "Create.h"
#include "core/Exception.h"
#include "core/Expression.h"
#include "core/Parser.hpp"
#include "DebugToolkit.hpp"

//#define DEBUG_SWITCH

 void Create::BootLoader(User* user) {
    int ope = Create::parseCreate(*this);
     switch (ope) {
         case TOKEN_TABLE:
             //puts("parseCreateTable");
             user->userDataDictionary.addTable(*parseCreateTable(user, *this));
             break;
         case TOKEN_VIEW:
             user->userDataDictionary.addView(this->account);
             break;
         case TOKEN_INDEX:
             user->userDataDictionary.addIndex(*parseCreateIndex(user, *this));
             break;
     }
}

Create::Create(std::string account) : Operate(std::move(account)) {}

/**
 * 解析create语句
 * @param create
 * @return
 */
int Create::parseCreate(Create &create) {
    puts("parseCreate");
    std::regex tableP(R"(^(create)\s(\w+)\s(\w+)\s?)");
//    std::regex tableP(R"((^(create)\s(table)\s(\w+)\s?\(\s?((\S+\sinteger)|(\S+\schar\(\w+\)))((\sprimary\skey)|(\snot\snull))?)(\s?,\s?((\S+\sinteger)|(\S+\\schar\(\w+\)))((\sprimary\skey)|(\snot\snull))?)*\);$)");
    //std::regex indexP(R"(^(create)\s(index)\s(\S+)\s(on)\s(\S+)\s(\S+)\s?;$)");
#ifdef DEBUG_SWITCH
    std::cout << regex_match(create.account, tableP) << std::endl;//true
#endif
    std::smatch m;
    bool found = regex_search(create.account, m, tableP);
    if(found){
#ifdef DEBUG_SWITCH
        DebugToolkit::RegexSearchOutput(m);
#endif
        if(m.size() < 2){
            Exception::RaiseException(0x00010003);
            return -1;
        }
        if (m.str(2) == "table"){
            create.name = m.str(3);
            //create.account = m.suffix().str();
            return TOKEN_TABLE;
        }
        else if (m.str(2) == "view"){
            return TOKEN_VIEW;
        }
        else if (m.str(2) == "unique" || m.str(2) == "cluster"){
            return TOKEN_INDEX;
        }
    }

    return 0;
}

/**
 * 解析create table
 * @param create
 * @return
 */
Table* Create::parseCreateTable(User* user, Create &create) {
    auto* table = new Table();
    table->setName(create.name);
    //std::regex tableP(R"(\(\s?(((\S+)\s(integer))|((\S+)\s(char\(\w+\)))))");
    std::regex tableP(R"(\((.+,?*)\))");
#ifdef DEBUG_SWITCH
    //std::cout << regex_match(create.account, tableP) << std::endl;//true
#endif
    std::smatch m;
    regex_search(create.account, m, tableP);
#ifdef DEBUG_SWITCH
    DebugToolkit::RegexSearchOutput(m);
#endif
    std::vector<std::string> subAccount;
    subAccount = Parser::regexSplit(m.str(1), ",\\s+");
    for (const auto& expression : subAccount) {
        //std::cout << subAccount[i] << std::endl;
        std::regex name_type(R"((\w+)\s(\S+))");
        std::smatch m_name_type;
        regex_search(expression, m_name_type, name_type);
#ifdef DEBUG_SWITCH
        DebugToolkit::RegexSearchOutput(m_name_type);
#endif
        Token tabLevelInte = DataStatusHelper.toEnum(m_name_type.str(0)); //是否为表级完整性约束
        if (tabLevelInte != TOKEN_INVALID){
            puts("表级完整性约束");
            std::string tmp = m_name_type.suffix().str(), intg;
            std::vector<std::string> key;
            std::string add;

            if (tabLevelInte == TOKEN_PRIMARY_KEY){
                for (char ch : tmp) {
                    if(ch != '(' && ch != ')' && ch != ' ') intg += ch;
                }
                Parser::SplitString(intg, key, ",");
                for(auto & j : key){
                    std::cout << j << " --- ";
                }
                puts("");
            } else{ // foreign key
                std::regex keyP(R"(\s\((\w+)\)\sreferences\s(\w+)\((\w+)\))");
                std::smatch m_key;
                regex_search(tmp, m_key, keyP);
#ifdef DEBUG_SWITCH
                DebugToolkit::RegexSearchOutput(m_key);
#endif
                key.push_back(m_key.str(1));
                add = m_key.str(2) + " " + m_key.str(3);
            }

            table->setKey(key, tabLevelInte, add);

            continue;
        }
        //不是表级，解析表头并加入
        std::string integrity = Parser::deleteHTSpace(m_name_type.suffix().str());
        Token status;
        if (!integrity.empty())
            status = DataStatusHelper.toEnum(integrity);
        else
            status = TOKEN_INVALID;
        table->addHead(m_name_type.str(1),
                       m_name_type.str(2),
                       status,
                       "");
    }
    //table->printHead();
    table->setOwner(user->userName);
    table->saveTableCSV();
    return table;
}

Index *Create::parseCreateIndex(User* user, Create& create) {
    auto* index = new Index();
    std::regex indexP(R"(^create\s(\w+)\sindex\s(\w+)\son\s(\w+)\((\w+)\))");
    std::smatch m_index;
    regex_search(create.account, m_index, indexP);
#ifdef DEBUG_SWITCH
    DebugToolkit::RegexSearchOutput(m_index);
#endif
    index->indexName = m_index.str(2);
    index->tableName = m_index.str(3);
    index->attrbName = m_index.str(4);
    //
    index->creatIndex(*user->userDataDictionary.findTable(index->tableName));
    index->printIndex();
    return index;
}

