//
// Created by NaturalVStudio on 2021/12/5.
//

#ifndef ZDB_USER_HPP
#define ZDB_USER_HPP

#include "Dictionary.h"
#include <string>
#include <fstream>

class User {
public:
    std::string userName;
    Dictionary userDataDictionary;
public:
    explicit User(const std::string& username){
        userName = username.empty() ? "ahh" : username;
        userDataDictionary.owner = username;
    }

    void saveUser() const{
        std::ifstream ifile;
        std::string filepath = "../data/userlist.csv";
        ifile.open(filepath, std::ios::in); //���������������ļ�ĩβ���ɸ�д
        std::string name;
        while (std::getline(ifile, name)){
            if (name == userName){
                std::cout << "��¼�ɹ�!" << std::endl;
                return;
            }
        }

        std::ofstream ofile;
        std::cout << "user save to " << filepath << std::endl;
        ofile.open(filepath, std::ios::out | std::ios::app); //���������������ļ�ĩβ���ɸ�д
        ofile << userName << std::endl;
        ofile.close();
    }
};


#endif //ZDB_USER_HPP
