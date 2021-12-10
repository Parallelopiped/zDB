# zDB

`SDUST` `DBMS`

zDB是一个DBMS简单设想的部分实现

## 结构设计
默认选项编译，运行，程序由main.cpp开始执行；
程序开始运行时，首先新建用户（已存在则登录），链接该用户的数据字典，然后接收SQL语句输入，创建handler开始引导。

+ 核心类（src/core）包含zDB运行所需的基本依赖，如Expression、Exception；
+ 数据相关类，如table、index，实现了存取以及完整性约束的控制；
+ 语句解析类（Operate的派生类），如create、insert、select，实现了语句的解析和相关内存变量的传递，指导数据相关类的具体操作；
+ 工具类，如Help、DebugToolkit，为使用和调试提供方便的接口；

## 环境依赖
+ CMake 3.17
+ mingw gcc 9.2
