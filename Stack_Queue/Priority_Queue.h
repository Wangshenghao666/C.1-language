#pragma once

namespace wsh
{
	template<class T,class Container = vector<int>>
	class priority_queue
	{
	public:
		priority_queue()
		{}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			//���ѣ����Ž���
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				adjust_down(i);
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}
		void pop()
		{
			assert(!_con.empty());
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		const T& top()
		{
			return _con[0];
		}
	private:
		Container _con;
	private:
		void adjust_up(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void adjust_down(size_t parent)
		{
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				{
					++child;
				}
				if (_con[child] > _con[parent])
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	};
	void test_priority_queue1()
	{
		priority_queue<int, vector<int>> pq;//Ĭ��С�����ȼ��ߣ���greater
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
}

//��ӷº���
namespace wsh1
{
	//����Ĭ��less�Ǵ�ѣ�����x > y
	template<class T>
	struct Less
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
	template<class T>
	struct Greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};
	template<class T, class Container = vector<int>,class Compare = Less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			//���ѣ����Ž���
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				adjust_down(i);
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}
		void pop()
		{
			assert(!_con.empty());
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		const T& top()
		{
			return _con[0];
		}
	private:
		Container _con;
	private:
		void adjust_up(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[child] , _con[parent]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void adjust_down(size_t parent)
		{
			Compare com;

			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child + 1] , _con[child]))
				{
					++child;
				}
				if (com(_con[child] , _con[parent]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	};
	void test_priority_queue1()
	{
		priority_queue<int> pq;//Ĭ��С�����ȼ��ߣ���greater
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
}