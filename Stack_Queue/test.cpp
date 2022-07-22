#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<queue>
#include<functional>
#include<assert.h>
using namespace std;

#include"queue.h"
#include"stack.h"
#include"Priority_Queue.h"

void test_stack()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
void test_queue()
{
	queue<int> q;
	q.push(9);
	q.push(8);
	q.push(7);
	q.push(6);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
void test_priority_queue()
{
	//priority_queue<int> pq;
	//priority_queue<int,vector<int>,less<int>> pq;//默认大的优先级高，是less
	priority_queue<int, vector<int>, greater<int>> pq;//默认小的优先级高，是greater
	pq.push(3);
	pq.push(3);
	pq.push(9);
	pq.push(1);
	pq.push(7);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

//简单仿函数
template<class T>
struct Less
{
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};
template<class T>
struct Greater
{
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};
void test_functor()
{
	Less<int> lessi;
	cout << lessi(1, 2) << endl;
	Greater<int> greateri;
	cout << greateri(1, 2) << endl;

	cout << Less<int>()(1, 2) << endl;
	cout << Greater<int>()(1, 2) << endl;
}


//有些地方自己控制实现仿函数
class Date
{
public:
	friend struct LessPDate;
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	//1.重载  2.自己写仿函数
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d);//类中声明，类外实现
	
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}


//void test_priority_queue2()
//{
//	priority_queue<Date, vector<Date>> pq;
//	pq.push(Date(2022, 3, 26));
//	pq.push(Date(2021, 10, 26));
//	pq.push(Date(2023, 3, 26));
//
//	while (!pq.empty())
//	{
//		cout << pq.top();
//		pq.pop();
//	}
//	cout << endl;
//}
//存指针：
struct LessPDate
{
	bool operator()(const Date* d1, const Date* d2)
	{
		return (d1->_year < d2->_year) ||
			(d1->_year == d2->_year && d1->_month < d2->_month) ||
			(d1->_year == d2->_year && d1->_month == d2->_month && d1->_day < d2->_day);
	}
};
void test_priority_queue2()
{
	//现在就不能排了
	priority_queue<Date*, vector<Date*>,LessPDate> pq;
	pq.push(new Date(2022, 3, 26));
	pq.push(new Date(2021, 10, 26));
	pq.push(new Date(2023, 3, 26));

	while (!pq.empty())
	{
		cout << *pq.top();
		pq.pop();
	}
	cout << endl;
}
int main()
{
	//test_stack();
	//test_queue();
	//wsh::test_stack1();
	//wsh::test_queue1();
	//test_priority_queue();
	wsh1::test_priority_queue1();
	//test_functor();测试仿函数

	test_priority_queue2();
	return 0;
}