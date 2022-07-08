#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<assert.h>
using namespace std;
#include"vector.h"


void Testvector1()
{
	vector<int> v1;
	vector<int> v2(10, 8);
	vector<int> v3(++v2.begin(), --v2.end());
	vector<int> v4(v3);
	string s("hello world");
	vector<char> v5(s.begin(), s.end());

}
void Testvector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << ++*it << " ";
		++it;
	}
	cout << endl;
	for (auto& e : v)
	{
		cout << --e << " ";
	}
	cout << endl;
}
void Testvector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.max_size() << endl;
	v.reserve(100);//扩容，不影响数据个数
	v.resize(100, 5);//会把数据给到100，扩容+初始化
	v.resize(2);
	v.assign(10, 2);//会把原来的数据覆盖掉，增加新的
}
void Testvector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator ret = find(v.begin(), v.end(), 3);
	if (ret != v.end())
	{
		cout << "zhao dao l  " << endl;
		v.insert(ret, 30);

	}
	v.insert(v.begin(), -1);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//Testvector1();
	//Testvector2();
	//Testvector4();
	wsh::vector4();
	return 0;
}
