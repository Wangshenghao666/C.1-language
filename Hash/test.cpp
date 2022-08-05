#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

#include"HashTable.h"

void test_unordered_set()
{
	//去重
	unordered_set<int> us;
	us.insert(5);
	us.insert(1);
	us.insert(5);
	us.insert(3);
	us.insert(7);
	us.insert(2);

	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto& e : us)
	{
		cout << e << " ";
	}
	cout << endl;

	//不去重
	unordered_multiset<int> ums;
	ums.insert(5);
	ums.insert(1);
	ums.insert(5);
	ums.insert(3);
	ums.insert(7);
	ums.insert(2);
	ums.insert(2);

	unordered_multiset<int>::iterator It = ums.begin();
	while (It != ums.end())
	{
		cout << *It << " ";
		++It;
	}
	cout << endl;
	for (auto& e : ums)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//test_unordered_set();
	//CloseHash::TestHashTable();
	//CloseHash::TestHashTable2();
	return 0;
}