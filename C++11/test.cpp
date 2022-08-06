#include<iostream>

using namespace std;

void test1()
{
	//可以取地址的就是左值
	int a = 10;
	int& b = a;
	int* p = &a;
	int& r2 = *p;

	const int c = 10;
	const int& r3 = c;
}
void test2()
{
	//不能取地址的对象，就是右值
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
	//左值引用能否引用右值---不能直接引用，但是const左值引用可以引用右值
	//eg:void push_back(const T& x)
	const int& r1 = 10;
	double x = 1.1, y = 2.2;
	const double& r2 = x + y;
	const double& r3 = fmin(x, y);
}
void test4()
{
	//右值引用能否引用左值---不能直接引用，但是可以右值引用可以引用move以后的左值
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


// 场景1
// 左值引用做参数，基本完美的解决所有问题
void func1(wsh::string s)
{}

void func2(const wsh::string& s)
{}

// 场景2
// 左值引用做返回值，只能解决部分问题
// string& operator+=(char ch) 解决了
// string operator+(char ch)   没有解决

// 右值引用，如何解决operator+传值返回存在拷贝的问题呢？
// C++11 将右值分为：纯右值，将亡值
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