#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

////��̬
////--��̬�Ķ�̬���������أ�����������ͬһ�������в�ͬ����Ϊ
////--��̬�Ķ�̬��һ����������û�ָ��ȥ����ͬһ�����������ݲ�ͬ�Ķ��󣬻���ò�ͬ�ĺ���
////--->���ʣ���ͬ����ȥ��ͬһ�����飬�����ͬ
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




////��дҪ�󷵻�ֵ��ͬ��һ�����⣺Э��---Ҫ�󷵻�ֵ�Ǹ��ӹ�ϵ��ָ�������
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



////--�������������Ƿ����麯�������������д
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



////---->��һ�ֳ���
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
//	//��operator new , Ȼ���ڹ��캯��
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	//�������������ڵ� operator delete
//	delete p1;//p1->destructor();
//	delete p2;//p1->destructor();
//
//	//��Ҫ��--->>>>>>>>>
//	//��̬����Ķ���������˸���ָ�������ô��Ҫ�����������麯��.
//}



////final---C++11�У��ֱ�ֱ������
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
////������������д
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




////override---����������д�麯���ĺ��棬����Ƿ������д��û�������д�ͱ���
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
//	// ���麯��һ��ֻ��������ʵ��
//	// ʵ��û�м�ֵ
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


// ����--����ʵ������û�ж�Ӧ��ʵ��
// һ�����ͣ����һ������ʵ�����У�û�о���Ķ�Ӧʵ��Ͷ���ɳ�����ȽϺ�
//class Car
//{
//public:
//	// ���麯��һ��ֻ��������ʵ��
//	// ʵ��û�м�ֵ
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
//		cout << "Benz-����" << endl;
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



