#include <iostream>
#include <vector>
#include "src/core/Data.h"
#include "src/Table.h"
#include "src/Handler.h"
#include "src/User.hpp"

#define DEBUG_SWITCH 1

using namespace std;
int main(){
    std::cout << "*** Hello, World! This is zDB under ur command! ***" << std::endl;
    std::cout << "*** 呃！请输入用户名!（缺省为测试攻城狮 :） ***" << std::endl;
    string username;
    getline(cin, username);
    User* heyGuy = new User(username);
    std::cout << heyGuy->userName << ": 欢迎" << endl;

    string handler;
    vector<Handler*> HandlerList;
    while(getline(cin, handler) && handler != "exit"){
        HandlerList.push_back(new Handler(handler, heyGuy));
    }
    //cout << HandlerList[0]->operate->account;
    return 0;
}
