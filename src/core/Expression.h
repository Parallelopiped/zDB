//
// Created by NaturalVStudio on 2021/11/6.
//

#ifndef ZDB_EXPRESSION_H
#define ZDB_EXPRESSION_H

#include <string>
#include <map>
#include <iostream>

template <typename T>
    class EnumHelper {
    private:
        std::map<T, std::string> _mapEnum2String;
        std::map<std::string, T> _mapString2Enum;
        T _defaultValue;

    private:
        static std::map<std::string, T> genString2EnumMap(std::map<T, std::string> enum2StringMap){
            std::map<std::string, T> result;
            for (const auto& item : enum2StringMap) {
                result.emplace(std::make_pair(item.second, item.first));
            }
            return result;
        };

    public:
        // constructor with initial enum-string map and a default enum value
        EnumHelper(const std::map<T, std::string>&& origin, const T defaultValue){
            _mapEnum2String = std::move(origin);
            _mapString2Enum = genString2EnumMap(_mapEnum2String);
            _defaultValue = defaultValue;
        }

        T toEnum(const std::string& str){
            if (str.empty()) {
                return _defaultValue;
            }

            auto find = _mapString2Enum.find(str);
            if (find == _mapString2Enum.end()) {
                std::cout << "无法解析 \"" << str << "\" 为已知的SQL语句类型，语句表：" << typeid(T).name() << std::endl;
                return _defaultValue;
            } else {
                return find->second;
            }
        }

        // get enum from string, if not matched, return specified value
        T toEnum(const std::string& str, const T defaultValue){
            auto find = _mapString2Enum.find(str);
            if (find == _mapString2Enum.end()) {
                std::cout << "Unrecognized string \"" << str << "\" for enum: " << typeid(T).name() << std::endl;
                return defaultValue;
            } else {
                return find->second;
            }
        }

        std::string toString(const T& enumValue){
            return _mapEnum2String.at(enumValue);
        }
    };

/**
 * Token表
 */
typedef enum Token_{
    TOKEN_CREATE = 0,
    TOKEN_INSERT,
    TOKEN_SELECT,

    TOKEN_TABLE,
    TOKEN_INDEX,
    TOKEN_VIEW,

    TOKEN_PRIMARY_KEY,
    TOKEN_FOREIGN_KEY,
    TOKEN_NOT_NULL,
    TOKEN_UNIQUE,

    TOKEN_L_PARENTHESIS,
    TOKEN_R_PARENTHESIS,

    TOKEN_INVALID
} Token;

/**
 * 建立字符串-枚举类型映射
 */
static EnumHelper<Token> DataStatusHelper(
        { {TOKEN_CREATE, "create"},
          {TOKEN_INSERT, "insert"},
          {TOKEN_SELECT, "select"},

          {TOKEN_TABLE, "table"},
          {TOKEN_INDEX, "index"},
          {TOKEN_VIEW, "view"},

          {TOKEN_PRIMARY_KEY, "primary key"},
          {TOKEN_FOREIGN_KEY, "foreign key"},
          {TOKEN_NOT_NULL, "not null"},
          {TOKEN_UNIQUE, "unique"},

          {TOKEN_L_PARENTHESIS, "("},
          {TOKEN_R_PARENTHESIS, ")"}
        },
        TOKEN_INVALID); //无效缺省

class Expression {
public:
    Token token;
    std::string alias{};
    std::string name{};
public:
    Expression();


};


#endif //ZDB_EXPRESSION_H
