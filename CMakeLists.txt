cmake_minimum_required(VERSION 3.17)
project(zDB)

set(CMAKE_CXX_STANDARD 20)

add_executable(zDB main.cpp src/core/Data.cpp src/core/Data.h
        src/core/Expression.cpp src/core/Expression.h
        src/Table.cpp src/Table.h src/Handler.cpp src/Handler.h src/core/Exception.cpp src/core/Exception.h src/Operate.hpp src/Create.cpp src/Create.h src/core/Parser.hpp src/DebugToolkit.hpp src/Dictionary.cpp src/Dictionary.h src/User.hpp src/Insert.cpp src/Insert.h)