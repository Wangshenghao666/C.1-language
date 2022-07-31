#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(8);
	s.insert(1);
	s.insert(8);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//默认中序打印+去重
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::iterator pos = s.find(3);
	if (pos != s.end())
	{
		//pos必须是一个有效位置的迭代器
		s.erase(pos);
	}
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

}
void test_multiset()
{
	multiset<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(8);
	s.insert(1);
	s.insert(8);

	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//默认中序打印+不去重
		cout << *it << " ";
		++it;
	}
	cout << endl;

	multiset<int>::iterator pos = s.find(1);
	while (pos != s.end())
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl;
	//find的val有多个值是，返回中序第一个val值所在节点的迭代器

	/*pos = s.find(1);
	while (pos != s.end() && *pos == 1)
	{
		auto next = pos;
		++next;
		s.erase(pos);
		pos = next;
	}*/
	cout << s.erase(1) << endl;//这里有几个1，返回计数

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_map1()
{
	map<string, string> dict;
	//插入1：
	pair<string, string> kvl("sort", "排序");//构造一个
	dict.insert(kvl);
	//插入2：
	dict.insert(pair<string, string>("string", "字符串"));
	//插入3：
	dict.insert(make_pair("test", "测试"));//这个常用---自动推到类型

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		//cout << *it << " ";//不支持
		//cout << (*it).first << " : " << (*it).second << endl;//可以
		cout << it->first << " : " << it->second << endl;//这样更好
		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << " : " << kv.second << endl;
	}
	cout << endl;
}
void test_map2()
{
	//map中，key不支持修改，val支持修改
	string arr[] = { "苹果", "苹果", "香蕉", "苹果", "香蕉", "苹果", "樱桃" };
	map<string, int> countMap;
	/*for (auto& str : arr)
	{
		auto ret = countMap.find(str);
		if (ret == countMap.end())
		{
			countMap.insert(make_pair(str,1));
		}
		else
		{
			ret->second++;
		}
	}*/
	////优化->
	//for (auto& str : arr)
	//{
	//	auto kv = countMap.insert(make_pair(str, 1));
	//	if (kv.second == false)
	//	{
	//		kv.first->second++;
	//	}
	//}
	//继续优化：
	for (auto& str : arr)
	{
		countMap[str]++;//调用operator[]
	}
	for (auto& kv : countMap)
	{
		cout << kv.first << " : " << kv.second << endl;
	}
	cout << endl;
}
void test_map3()
{
	map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("left", "剩余"));//只要key一样就不会插入成功，只会看key,而不会看value

	dict["left"] = "剩余";//[]---可以修改
	dict["test"];//插入（value是缺省）
	//cout << dict["sort"] << endl;//查找
	dict["string"] = "字符串";//插入+修改
	for (auto& str : dict)
	{
		cout << str.first << " : " << str.second << endl;
	}
	cout << endl;
}
void test_multimap()
{
	multimap<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("left", "剩余"));
	//key有了还会继续插入
	cout << dict.count("left") << endl;//计数
}
int main()
{
	//test_set1();
	//test_multiset();
	//test_map1();
	//test_map2();
	//test_map3();
	test_multimap();
	return 0;
}