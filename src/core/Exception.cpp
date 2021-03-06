//
// Created by NaturalVStudio on 2021/12/2.
//

#include "Exception.h"
#include <iostream>

/**
 * 建立异常表，异常编码格式：
 * 使用int32类型作为异常编号，其前四位定义异常类型号，后四位为异常编号
 * * * * * * *  *  *  *  * * * * * *
 * 类型0000：保留字段，系统基本异常
 * 类型0001：基本语法输入错误
 * 类型0002：table约束相关
 * 类型0003：数据字典异常
 * 类型0004：index约束相关
 * 类型0005：
 *
 * 类型1111：非异常操作
 *
 * @return ExcpList
 */
std::unordered_map<int32_t, std::string> Exception::CreateExcpList() {
    std::unordered_map<int32_t , std::string> temp;

    temp[0x00010001] = "zDB异常[0x00010001]: 请用空白字符分隔SQL语句";
    temp[0x00010002] = "zDB异常[0x00010002]: 非法SQL语句，请检查";
    temp[0x00010003] = "zDB异常[0x00010003]: 不完整create操作，可选项：table, index, view";
    temp[0x00010004] = "zDB异常[0x00010004]: insert语句有误，请检查";

    temp[0x00020002] = "zDB异常[0x00020002]: 包含表中缺失的属性，请检查";

    temp[0x00020001] = "zDB异常[0x00020001]: 已存在该表";
    temp[0x00030001] = "zDB异常[0x00030001]: 数据库中无此表单";
    temp[0x00030002] = "zDB异常[0x00030002]: 已存在该索引";

    temp[0x00040001] = "zDB异常[0x00040001]: 目标数据表无此属性，请检查";

    temp[0x11110001] = "zDB操作[0x11110001]: （miss）内存中缺失此表，正在读取外存文件";
    return temp;
}

void Exception::RaiseException(int32_t ExcpCode) {
    std::cout << exceptionList[ExcpCode] << std::endl;
}
std::unordered_map<int32_t , std::string> Exception::exceptionList = Exception::CreateExcpList();
