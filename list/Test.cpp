#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include<assert.h>


using namespace std;
#include"List.h"

void test_list1()
{
	list<int> It;
	It.push_back(1);
	It.push_back(2);
	It.push_back(3);
	It.push_back(4);
	list<int>::iterator it = It.begin();
	while (it != It.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator rit = It.rbegin();
	while (rit != It.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void test_list2()
{
	list<int> It;
	It.push_back(1);
	It.push_back(2);
	It.push_back(3);
	It.push_back(4);

	for (auto& e : It)
	{
		cout << e << " ";
	}
	cout << endl;

	It.reverse();
	for (auto& e : It)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//test_list1();
	//test_list2();
	//wsh::test_list1();
	//wsh::test_list1();
	//wsh::test_list3();
	wsh::test_list4();
	return 0;
}