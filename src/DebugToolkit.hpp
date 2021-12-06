//
// Created by NaturalVStudio on 2021/12/3.
//

#ifndef ZDB_DEBUGTOOLKIT_HPP
#define ZDB_DEBUGTOOLKIT_HPP

#include <regex>

class DebugToolkit {
public:
    static int RegexSearchOutput(const std::smatch& m){
        std::cout << "m.size() " << m.size() << std::endl;
        for(int i=0; i<m.size(); ++i){
            std::cout << "m.str(" << i << "): " << m.str(i) << std::endl;
        }
        std::cout << "m.prefix().str(): " << m.prefix().str() << std::endl;
        std::cout << "m.suffix().str(): " << m.suffix().str() << std::endl;
        return 0;
    }
};


#endif //ZDB_DEBUGTOOLKIT_HPP
