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
		//Ĭ�������ӡ+ȥ��
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::iterator pos = s.find(3);
	if (pos != s.end())
	{
		//pos������һ����Чλ�õĵ�����
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
		//Ĭ�������ӡ+��ȥ��
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
	//find��val�ж��ֵ�ǣ����������һ��valֵ���ڽڵ�ĵ�����

	/*pos = s.find(1);
	while (pos != s.end() && *pos == 1)
	{
		auto next = pos;
		++next;
		s.erase(pos);
		pos = next;
	}*/
	cout << s.erase(1) << endl;//�����м���1�����ؼ���

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_map1()
{
	map<string, string> dict;
	//����1��
	pair<string, string> kvl("sort", "����");//����һ��
	dict.insert(kvl);
	//����2��
	dict.insert(pair<string, string>("string", "�ַ���"));
	//����3��
	dict.insert(make_pair("test", "����"));//�������---�Զ��Ƶ�����

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		//cout << *it << " ";//��֧��
		//cout << (*it).first << " : " << (*it).second << endl;//����
		cout << it->first << " : " << it->second << endl;//��������
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
	//map�У�key��֧���޸ģ�val֧���޸�
	string arr[] = { "ƻ��", "ƻ��", "�㽶", "ƻ��", "�㽶", "ƻ��", "ӣ��" };
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
	////�Ż�->
	//for (auto& str : arr)
	//{
	//	auto kv = countMap.insert(make_pair(str, 1));
	//	if (kv.second == false)
	//	{
	//		kv.first->second++;
	//	}
	//}
	//�����Ż���
	for (auto& str : arr)
	{
		countMap[str]++;//����operator[]
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
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("left", "ʣ��"));//ֻҪkeyһ���Ͳ������ɹ���ֻ�ῴkey,�����ῴvalue

	dict["left"] = "ʣ��";//[]---�����޸�
	dict["test"];//���루value��ȱʡ��
	//cout << dict["sort"] << endl;//����
	dict["string"] = "�ַ���";//����+�޸�
	for (auto& str : dict)
	{
		cout << str.first << " : " << str.second << endl;
	}
	cout << endl;
}
void test_multimap()
{
	multimap<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("left", "ʣ��"));
	//key���˻����������
	cout << dict.count("left") << endl;//����
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