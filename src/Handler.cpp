//
// Created by NaturalVStudio on 2021/11/10.
//

#include <regex>
#include <iostream>
#include "Handler.h"
#include "core/Exception.h"
#include "Create.h"
#include "Insert.h"
#include "Select.h"
#include "Update.h"
#include "Delete.h"

//using namespace  std;

Handler::Handler(const std::string& account, User* user) {
    std::regex r("\\s");
    std::smatch m;
    bool found = regex_search(account, m, r);
    if(found){
        auto status = DataStatusHelper.toEnum(m.prefix().str());
        /*
         * 转为预定义的枚举类型Token，并分类创建句柄
         */
        switch (status){
            case TOKEN_CREATE:
                //puts("create!");
                this->operate = new Create(account);
                break;
            case TOKEN_INSERT:
                this->operate = new Insert(account);
                break;
            case TOKEN_SELECT:
                this->operate = new Select(account);
                break;
            case TOKEN_UPDATE:
                this->operate = new Update(account);
                break;
            case TOKEN_DELETE:
                this->operate = new Delete(account);
                break;
            default:
                Exception::RaiseException(0x00010002);
                return;
        }
        this->operate->BootLoader(user); //sql语句解析引导

    }
    else Exception::RaiseException(0x00010001);

}

