//
// Created by NaturalVStudio on 2021/12/3.
//

#ifndef ZDB_PARSER_HPP
#define ZDB_PARSER_HPP

#include <cstring>
#include <regex>
#include <string>
#include <iostream>
/**
 * 包含自定义有关语句解析的方法
 */
class Parser {
public:
    /**
     * 使用正则表达式分解
     * @param input
     * @param regex
     * @return 分割后的vector
     */
    static std::vector<std::string> regexSplit(const std::string& input,
                                   const std::string& regex){

        std::regex re(regex);
        std::sregex_token_iterator first {input.begin(), input.end(), re, -1}, last;
        return {first, last};
    }
    /**
     * 使用单字符串分解
     * @param s input
     * @param v vector
     * @param c split
     */
    static void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c){
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2){
            v.push_back(s.substr(pos1, pos2-pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }

    static std::vector<std::string> split(const std::string &s, const std::string &seperator){
        std::vector<std::string> result;
        typedef std::string::size_type string_size;
        string_size i = 0;

        while(i != s.size()){
            //找到字符串中首个不等于分隔符的字母；
            int flag = 0;
            while(i != s.size() && flag == 0){
                flag = 1;
                for(string_size x = 0; x < seperator.size(); ++x)
                    if(s[i] == seperator[x]){
                        ++i;
                        flag = 0;
                        break;
                    }
            }

            //找到又一个分隔符，将两个分隔符之间的字符串取出；
            flag = 0;
            string_size j = i;
            while(j != s.size() && flag == 0){
                for(string_size x = 0; x < seperator.size(); ++x)
                    if(s[j] == seperator[x]){
                        flag = 1;
                        break;
                    }
                if(flag == 0)
                    ++j;
            }
            if(i != j){
                result.push_back(s.substr(i, j-i));
                i = j;
            }
        }
        return result;
    }
    /**
     * 去掉首尾空格
     * @param s
     * @return
     */
    static std::string deleteHTSpace(const std::string& s){
        std::string tmp;
        for (int i = 0; i < s.size(); ++i) {
            if ((i == s.size() - 1 || i == 0) && s[i] == ' ') continue;
            tmp += s[i];
        }
        return tmp;
    }

    static std::string regexDelete(const std::string& s, const std::string& regex){
        std::regex P(regex);
        return std::regex_replace(s, P, "");
    }

    /*
     * 没用了
     */
//    static int parseCreate(Create& create){
//        puts("parseCreate");
//        std::regex tableP(R"(^(create)\s(table)\s(\w+)\s?;$)");
//        std::regex indexP(R"(^(create)\s(index)\s(\S+)\s(on)\s(\S+)\s(\S+)\s?;$)");
//
//        std::cout << regex_match("create table student(sno char(10), sname char(20), sage integer, ssex char(10));", tableP) << std::endl;//true
//
////        std::string tableP = "(?i)^(create)\\s(table)\\s(\\w+)\\s?\\(\\s?((\\S+\\sInteger)|(\\S+\\sVarchar\\(\\w+\\)))"
////                             "((\\sPrimary\\sKey)|(\\sNot\\sNull))?(\\s?,\\s?((\\S+\\sInteger)|(\\S+\\sVarchar\\(\\w+\\)))"
////                             "((\\sPrimary\\sKey)|(\\sNot\\sNull))?)*\\);$";
////        std::string indexP = "(?i)^(create)\\s(index)\\s(\\S+)\\s(on)\\s(\\S+)\\s(\\S+)\\s?;$";
//        return 0;
//    }
};


#endif //ZDB_PARSER_HPP
