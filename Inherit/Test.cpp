#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//
////继承
//class Person
//{
//protected:
//	string _name;
//	string _sex;
//	int _age;
//};
//class Student :public Person
//{
//public:
//	int _No;
//};
//void Inherit1()
//{
//	Person p;
//	Student s;
//	p = s;//赋值兼容-> 切片、切割
//	Person* ptr = &s;
//	Person& ptr = s;
//	//这里不存在类型转换，是语法天然的支持行为
//}
//int main()
//{
//	Inherit1();
//	return 0;
//}



//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//	{}
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << " Person(const Person& p) " << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << " Person& operator=(const Person&p )" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		cout << " ~Person() " << endl;
//		delete[] _ptr;
//	}
//protected:
//	string _name;
//	int* _ptr = new int[10];
//};
//class Student :public Person
//{
//public:
//	Student(const char* name = "zhangsan", int num = 1)
//		:Person(name)
//		, _num(num)
//	{}
//	Student(const Student& s)
//		:Person(s)//切片使用
//		, _num(s._num)
//	{}
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);//注意隐藏
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		//Person::~Person();
//		delete[] _ptr;
//		//子类析构函数结束时，会自动调用父类的析构函数
//		//所以我们自己实现析构子类函数时，不需要显示调用父类函数，这样才能保证先析构子类成员，然后在析构父类成员
//	}
//protected:
//	int _num = 1;
//	int* _ptr = new int[10];
//};
//
//int main()
//{
//	Student s1;
//	//子类自己的成员函数就按照以前的方式处理（和普通类一样），
//	//继承的成员，调用父类几个默认成员函数处理.
//}





////多继承
//class Person
//{
//public:
//	string _name; // 姓名
//	int _a[10000];//这种情况会浪费
//};
//class Student : public Person
//{
//public:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//public:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	Assistant a;
//	a._id = 1;
//	a._num = 2;
//	a.Student::_name = "小张";
//	a.Teacher::_name = "张老师";
//	//指定作用域可以简单解决
//	//eg:这个不好解决
//	cout << sizeof(a) << endl;//会造成浪费
//}
//------>解决：
class Person
{
public:
	string _name; // 姓名
	int _a[10000];//这种情况会浪费
};
class Student :virtual public Person
{
public:
	int _num; //学号
};
class Teacher :virtual public Person
{
public:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
int main()
{
	Assistant a;
	a._id = 1;
	a._num = 2;
	a.Student::_name = "小张";
	a.Teacher::_name = "张老师";
	
	//加virtual，可以解决：
	cout << sizeof(a) << endl;
}