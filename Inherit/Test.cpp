#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//
////�̳�
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
//	p = s;//��ֵ����-> ��Ƭ���и�
//	Person* ptr = &s;
//	Person& ptr = s;
//	//���ﲻ��������ת�������﷨��Ȼ��֧����Ϊ
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
//		:Person(s)//��Ƭʹ��
//		, _num(s._num)
//	{}
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);//ע������
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		//Person::~Person();
//		delete[] _ptr;
//		//����������������ʱ�����Զ����ø������������
//		//���������Լ�ʵ���������ຯ��ʱ������Ҫ��ʾ���ø��ຯ�����������ܱ�֤�����������Ա��Ȼ�������������Ա
//	}
//protected:
//	int _num = 1;
//	int* _ptr = new int[10];
//};
//
//int main()
//{
//	Student s1;
//	//�����Լ��ĳ�Ա�����Ͱ�����ǰ�ķ�ʽ��������ͨ��һ������
//	//�̳еĳ�Ա�����ø��༸��Ĭ�ϳ�Ա��������.
//}





////��̳�
//class Person
//{
//public:
//	string _name; // ����
//	int _a[10000];//����������˷�
//};
//class Student : public Person
//{
//public:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//public:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//int main()
//{
//	Assistant a;
//	a._id = 1;
//	a._num = 2;
//	a.Student::_name = "С��";
//	a.Teacher::_name = "����ʦ";
//	//ָ����������Լ򵥽��
//	//eg:������ý��
//	cout << sizeof(a) << endl;//������˷�
//}
//------>�����
class Person
{
public:
	string _name; // ����
	int _a[10000];//����������˷�
};
class Student :virtual public Person
{
public:
	int _num; //ѧ��
};
class Teacher :virtual public Person
{
public:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};
int main()
{
	Assistant a;
	a._id = 1;
	a._num = 2;
	a.Student::_name = "С��";
	a.Teacher::_name = "����ʦ";
	
	//��virtual�����Խ����
	cout << sizeof(a) << endl;
}