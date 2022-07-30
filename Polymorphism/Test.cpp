#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

////多态
////--静态的多态：函数重载，看起来调用同一个函数有不同的行为
////--动态的多态：一个父类的引用或指针去调用同一个函数，传递不同的对象，会调用不同的函数
////--->本质：不同的人去做同一件事情，结果不同
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << " main piao -- quanjiang " << endl;
//	}
//};
//class Student:public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << " main piao -- banjiang " << endl;
//	}
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//	return 0;
//}




////重写要求返回值相同有一种例外：协变---要求返回值是父子关系的指针或引用
//class A
//{
//	//...
//};
//class B :public A
//{
//	//...
//};
//class Person
//{
//public:
//	virtual A* BuyTicket()
//	{
//		cout << " main piao -- quanjiang " << endl;
//		return nullptr;
//	}
//};
//class Student :public Person
//{
//public:
//	virtual B* BuyTicket()
//	{
//		cout << " main piao -- banjiang " << endl;
//		return nullptr;
//	}
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//	return 0;
//}



////--析构函数无论是否是虚函数，都完成了重写
//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << " ~Person " << endl;
//	}
//};
//class Student:public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << " ~Student() " << endl;
//	}
//};
//int main()
//{
//	Person p;
//	Student s;
//}



////---->另一种场景
//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << " ~Person() " << endl;
//	}
//};
//class Student :public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << " ~Student() " << endl;
//	}
//};
//int main()
//{
//	//先operator new , 然后在构造函数
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	//先析构函数，在调 operator delete
//	delete p1;//p1->destructor();
//	delete p2;//p1->destructor();
//
//	//重要：--->>>>>>>>>
//	//动态申请的对象，如果给了父类指针管理，那么需要析构函数是虚函数.
//}



////final---C++11中，粗暴直接限制
//class A final
//{
//protected:
//	int _a;
//};
//class B :public A
//{
//protected:
//	//...
//};
//
////还可以限制重写
//class C
//{
//public:
//	virtual void f() final
//	{
//		cout << " void f() " << endl;
//	}
//};
//class D :public C
//{
//public:
//	virtual void f()
//	{
//		cout << " D::f() " << endl;
//	}
//};
//int main()
//{
//	return 0;
//}




////override---放在子类重写虚函数的后面，检查是否完成重写，没有完成重写就报错
//class Car
//{
//public:
//	virtual void Drive()
//	{
//
//	}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() override
//	{
//		cout << " shushi---benz " << endl;
//	}
//};



//class Car
//{
//public:
//	// 纯虚函数一般只声明，不实现
//	// 实现没有价值
//	//virtual void Drive() = 0;
//	virtual void Drive() = 0
//	{
//		cout << "virtual void Drive() = 0" << endl;
//	}
//
//	void f()
//	{
//		cout << "void f();" << endl;
//	}
//};
//
//int main()
//{
//	Car* p = nullptr;
//	p->Drive();
//	p->f();
//
//	return 0;
//}


// 抽象--在现实世界中没有对应的实物
// 一个类型，如果一般在现实世界中，没有具体的对应实物就定义成抽象类比较好
//class Car
//{
//public:
//	// 纯虚函数一般只声明，不实现
//	// 实现没有价值
//	virtual void Drive() = 0;
//	/*virtual void Drive() = 0
//	{
//		cout << "virtual void Drive() = 0" << endl;
//	}*/
//};

//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//int main()
//{
//	Car* p = new Benz;
//	p->Drive();
//
//	return 0;
//}



