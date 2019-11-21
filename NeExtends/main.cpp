//
//  main.cpp
//  NeExtends
//
//  Created by 天涯路 on 2019/11/21.
//  Copyright © 2019年 天涯路. All rights reserved.
//

#include <iostream>
#include "Extends.hpp"

int main(int argc, const char * argv[]) {
    Child child;
    //继承
    child.test(); //Child
    child.iovokeParent(); //Parent
    
    //静态多态->编译时已确定类型(Parent)
    Parent* child1 = new Child();
    child1->test(); //Parent
    
    //动态多态：虚函数->运行时对虚函数会检查类型（Child）
    //构造方法永远不要设为虚函数 -> 无法实例化子类
    //析构方法声明为虚函数 -> 释放子类内存
    Parent1* child2 = new Child();
    child2->test(); //Child
    
    return 0;
}
