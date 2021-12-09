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

//using namespace  std;

Handler::Handler(const std::string& account, User* user) {
    std::regex r("\\s");
    //std::cout << account << std::endl;
    std::smatch m;
    bool found = regex_search(account, m, r);
    if(found){
        auto status = DataStatusHelper.toEnum(m.prefix().str());
        /*
         * תΪԤ�����ö������Token�������ഴ�����
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
            case TOKEN_L_PARENTHESIS:
                break;
            case TOKEN_R_PARENTHESIS:
                break;
            default:
                Exception::RaiseException(0x00010002);
                return;
        }
        this->operate->BootLoader(user); //sql����������

//        cout << "m.size() " << m.size() << endl;
//        for(int i=0; i<m.size(); ++i){
//            cout << "m.str(" << i << "): " << m.str(i) << endl;
//        }
//        cout << "m.prefix().str(): " << m.prefix().str() << endl;
//        cout << "m.suffix().str(): " << m.suffix().str() << endl;
    }
    else Exception::RaiseException(0x00010001);


}

