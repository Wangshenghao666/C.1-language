#pragma once
#include<vector>
#include<list>
//  ≈‰∆˜ƒ£ Ω
namespace wsh
{
	template<class T, class Container = deque<T>>
	class queue
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
		const T& front() const
		{
			return _con.front();
		}
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
	private:
		Container _con;
	};
	void test_queue1()
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
}
