#include<iostream>

using namespace std;

void test1()
{
	//����ȡ��ַ�ľ�����ֵ
	int a = 10;
	int& b = a;
	int* p = &a;
	int& r2 = *p;

	const int c = 10;
	const int& r3 = c;
}
void test2()
{
	//����ȡ��ַ�Ķ��󣬾�����ֵ
	double x = 1.1, y = 2.2;
	10;
	x + y;
	fmin(x, y);

	int&& rr1 = 10;
	double&& rr2 = x + y;
	double&& rr3 = fmin(x, y);
}
void test3()
{
	//��ֵ�����ܷ�������ֵ---����ֱ�����ã�����const��ֵ���ÿ���������ֵ
	//eg:void push_back(const T& x)
	const int& r1 = 10;
	double x = 1.1, y = 2.2;
	const double& r2 = x + y;
	const double& r3 = fmin(x, y);
}
void test4()
{
	//��ֵ�����ܷ�������ֵ---����ֱ�����ã����ǿ�����ֵ���ÿ�������move�Ժ����ֵ
	int a = 10;
	int& b = a;
	int* p = &a;
	int& r2 = *p;

	const int c = 10;
	const int& r3 = c;

	int*&& rr1 = move(p);
	int&& rr2 = move(*p);
	const int&& rr3 = move(c);

}
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	return 0;
//}

#include<string.h>
#include<assert.h>
#include"c++11.h"


// ����1
// ��ֵ���������������������Ľ����������
void func1(wsh::string s)
{}

void func2(const wsh::string& s)
{}

// ����2
// ��ֵ����������ֵ��ֻ�ܽ����������
// string& operator+=(char ch) �����
// string operator+(char ch)   û�н��

// ��ֵ���ã���ν��operator+��ֵ���ش��ڿ����������أ�
// C++11 ����ֵ��Ϊ������ֵ������ֵ
wsh::string func3()
{
	wsh::string str("hello world");
	//cin >> str;

	return str;
}

int main()
{
	wsh::string str("hello world");
	//func1(str);
	//func2(str);

	/*str += '!';
	str + '!';*/
	func3();

	return 0;
}