//
//  Extends.hpp
//  NeExtends
//
//  Created by 天涯路 on 2019/11/21.
//  Copyright © 2019年 天涯路. All rights reserved.
//

#ifndef Extends_hpp
#define Extends_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Parent {
public:
    void test(){
        cout << "Parent" << endl;
    }
    
    //纯虚函数 -> 类似于Java中的抽象方法
//    virtual void test1() = 0;
};

class Parent1 {
public:
    //虚函数
    //构造方法永远不要设为虚函数 -> 无法实例化子类
    //析构方法声明为虚函数 -> 释放子类内存
    virtual void test() {
        cout << "Parent1" << endl;
    }
};

//公有继承
class Child : public Parent, public Parent1{
public:
    void test() {
        cout << "Child" << endl;
    }
    
    void iovokeParent() {
        Parent::test();
    }
};

#endif /* Extends_hpp */
