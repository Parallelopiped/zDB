//
// Created by NaturalVStudio on 2021/12/10.
//

#include <fstream>
#include "View.h"

void View::saveView() const {
    std::ofstream ofile;
    std::string filepath = "../data/view_" + name + ".csv";
    std::cout << "table save to " << filepath << std::endl;
    ofile.open(filepath, std::ios::out | std::ios::trunc);//判断.csv文件是否存在，不存在则建立，每次都会删除之前文件，重新生成，不可复写
    ofile << this->account << std::endl;
    ofile.close();
}

void View::printView() const {
    puts("view:");
    std::cout << account << std::endl;
}
