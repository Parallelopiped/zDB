//
// Created by NaturalVStudio on 2021/12/2.
//

#ifndef ZDB_EXCEPTION_H
#define ZDB_EXCEPTION_H

#include <unordered_map>
#include "string"


class Exception {
private:
    static std::unordered_map<int32_t , std::string> exceptionList; //异常列表
public:
    static void RaiseException(int32_t); //抛出异常
    static std::unordered_map<int32_t , std::string> CreateExcpList();
};


#endif //ZDB_EXCEPTION_H
