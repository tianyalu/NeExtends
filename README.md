## NeExtends 继承多态，虚函数，纯虚函数
### 一、概念
#### 1.1 继承
C++中是多继承，包含公有继承、保护继承、私有继承，区别如下：
* 公有继承时基类中各成员属性保持不变，基类中private成员被隐藏。派生类的成员只能访问基类中的public/protected成员，而不能访问private成员；派生类的对象只能访问基类中的public成员。
* 保护继承时基类中各成员属性均变为protected，并且基类中private成员被隐藏。派生类的成员只能访问基类中的public/protected成员，而不能访问private成员；派生类的对象不能访问基类中的任何的成员。
* 私有继承时各成员属性均变为private，并且基类中的private成员被隐藏。派生类的成员也只能访问基类中的public/protected成员，而不能访问private成员；派生类的对象不能访问基类中的任何成员。  

公有继承 | 对象访问 | 成员访问 
-- | -- | --
public --> public | Y | Y
protected --> protected | N | Y
private --> private | N | N
  
公有继承 | 对象访问 | 成员访问 
-- | -- | --
public --> protected | N | Y
protected --> protected | N | Y
private --> protected | N | N  

公有继承 | 对象访问 | 成员访问 
-- | -- | --
public --> private | N | Y
protected --> private | N | Y
private --> private | N | N

#### 1.2 静态多态
编译时已确定类型（Parent）
```c
	Parent* child1 = new Child();
	child1->test(); //Parent
```
#### 1.3 动态多态 <-- 虚函数
运行时对虚函数会检查类型（Child）
```c
    Parent1* child2 = new Child();
    child2->test(); //Child
```

#### 1.4 虚函数：virtual
* 构造方法永远不要设为虚函数 -> 无法实例化子类
* 析构方法声明为虚函数 -> 释放子类内存

#### 1.5 纯虚函数
类似于Java中的抽象方法
```c
	virtual void test1() = 0;
```

### 二、代码
Extends.hpp
```c
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
```
main.cpp
```c
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

```