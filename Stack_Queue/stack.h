#pragma once
#include<vector>
#include<list>
#include<forward_list>
//  ≈‰∆˜ƒ£ Ω
namespace wsh
{
	template<class T,class Container = deque<T>>
	class stack
	{
	public:
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}
		const T& top() const
		{
			return _con.back();
		}
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
	private:
		Container _con;
	};
	void test_stack1()
	{
		//stack<int, list<int>> s;
		//stack<int, vector<int>> s;
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
}
