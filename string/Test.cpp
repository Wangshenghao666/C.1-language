#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

void StringTest1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
}
void StringTest2()
{
	//string s1("hello world");
	//cout << s1 << endl;
	//for (size_t i = 0; i < s1.size(); i++)
	//{
	//	cout << s1[i] << " ";
	//	s1[i] += 1;
	//}
	//printf("\n");
	//for (size_t j = 0; j < s1.size(); j++)
	//{
	//	cout << s1.operator[](j) << " ";
	//}
	//cout << endl;
	string s1("wangshenghao");
	s1.push_back('a');
	s1.append("abc");
	cout << s1 << endl;

}
void StringTest3()
{
	string s1("wang sheng hao shi zui nb");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto& e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	printf("\n");
}
void StringTest4()
{
	string s;
	s.reserve(1000);
	size_t sz = s.capacity();
	cout << "capacity changed:" << sz << '\n';
	cout << "making s grav:\n";
	for (int i = 0; i < 1000; i++)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}
void StringTest5()
{
	//string file("test.txt");
	//cout << file << endl;
	//cout << file.c_str() << endl;
	//FILE* fout = fopen(file.c_str(), "w");
	////需要你取出文件的后缀名
	//size_t pos = file.find('.');
	//if (pos != string::npos)
	//{
	//	string suffix = file.substr(pos, file.size() - pos);
	//	cout << suffix << endl;
	//}
	string file("test.txt.zip");
	FILE* fout = fopen(file.c_str(), "w");
	size_t pos = file.rfind('.');
	if (pos != string::npos)
	{
		string suffix = file.substr(pos, file.size() - pos);
		cout << suffix << endl;
	}

}
void StringTest6()
{
	string s("hello world");
	s += ' ';
	s += "!!!!!!!!!!!!";
	cout << endl;
	//头插，效率，o(n),尽量少用
	s.insert(0, 1, 'x');
	s.insert(s.begin(),'y');
	s.insert(0, "wangshenghao");
	//中间插入
	s.insert(4, "!!!!!");
	cout << s << endl;
}
void StringTest7()
{
	int val = stoi("1234");
	string str = to_string(3.14);
}
//int main()
//{
//	//StringTest1();
//	//StringTest2();
//	//StringTest3();
//	//StringTest4();
//	//StringTest5();
//	//StringTest6();
//	StringTest7();
//	return 0;
//}
#include<assert.h>
#include"string.h"


int main()
{
	//wsh::test_string1();
	//zj::test_string2();
	wsh1::test_string3();
	return 0;
}

