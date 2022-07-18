#pragma once

namespace wsh
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& data = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{}
	};


	//迭代器
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T, Ref,Ptr> self;
		Node* _node;

		__list_iterator(Node* x)//用节点的指针构造一个迭代器
			:_node(x)
		{}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		//节点的指针不一样就不一样
		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}
		bool operator==(const self& it) const
		{
			return _node == it._node;
		}
	};


	////const 迭代器
	////代码冗余，没有体现出泛型编程的特点
	//template<class T>
	//struct __const_list_iterator
	//{
	//	typedef ListNode<T> Node;
	//	Node* _node;

	//	__const_list_iterator(Node* x)//用节点的指针构造一个迭代器
	//		:_node(x)
	//	{}

	//	__const_list_iterator<T>& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}
	//	__const_list_iterator<T> operator++(int)
	//	{
	//		__const_list_iterator<T> tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//	__const_list_iterator<T>& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}
	//	__const_list_iterator<T> operator--(int)
	//	{
	//		__const_list_iterator<T> tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}
	//	//节点的指针不一样就不一样
	//	bool operator!=(const __const_list_iterator<T>& it) const
	//	{
	//		return _node != it._node;
	//	}
	//	bool operator==(const __const_list_iterator<T>& it) const
	//	{
	//		return _node == it._node;
	//	}
	//};




	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;
		//typedef __const_list_iterator<T> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				iterator del = it++;
				delete del._node;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		////深拷贝：传统写法
		//list(const list<T>& lt)
		//{
		//	_head = new Node();
		//	_head->_prev = _head;
		//	_head->_next = _head;
		//	for (auto& e : lt)
		//	{
		//		push_back(e);
		//	}
		//}
		////赋值：传统写法
		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (this != &lt)
		//	{
		//		clear();
		//		for (auto& e : lt)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this; 
		//}




		//现代写法：
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			_head = new Node();
			_head->_prev = _head;
			_head->_next = _head;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& lt)
		{
			_head = new Node();
			_head->_prev = _head;
			_head->_next = _head;

			list<T> tmp(lt.begin(), lt.end());
			std::swap(_head, tmp._head);
		}
		list<T>& operator=(list<T> lt)
		{
			std::swap(_head, lt._head);
			return *this;
		}




		void push_back(const T& x)
		{
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			tail->_next = newnode;
			newnode->_prev = tail;

			_head->_prev = newnode;
			newnode->_next = _head;*/
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			delete pos._node;

			prev->_next = next;
			next->_prev = prev;
			
			return iterator(next);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
	private:
		Node* _head;
	};
	//const迭代器：
	void print_list(const list<int>& It)
	{
		list<int>::const_iterator it = It.begin();
		while (it != It.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test_list1()
	{
		list<int> It;
		It.push_back(1);
		It.push_back(2);
		It.push_back(3);
		It.push_back(4);

		print_list(It);
	}
	void test_list2()//迭代器测试
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
	}
	

	//迭代器像指针一样
	//使用场景:
	struct Date
	{
		int _year;
		int _month;
		int _day;

		Date(int year = 1, int month = 1, int day = 1)
			:_year(year)
			, _month(month)
			, _day(day)
		{}
	};
	void test_list3()
	{
		list<Date> It;
		It.push_back(Date(2022, 3, 12));
		It.push_back(Date(2022, 3, 13));
		It.push_back(Date(2022, 3, 14));

		list<Date>::iterator it = It.begin();
		while (it != It.end())
		{
			//cout << *it << " ";//现在自定义类型不支持<<
			//1.可以：
			cout << (*it)._year << "/" << (*it)._month << "/" << (*it)._day << endl;
			//2.实现operator->
			cout << it->_year << "/" << it->_month << "/" << it->_day << endl;
			++it;
		}
		cout << endl;
	}

	void test_list4()
	{
		//现在程序会崩，因为浅拷贝
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		list<int> lt2(lt1);
		for (auto& e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;
		list<int> lt3;
		lt3.push_back(9);
		lt3.push_back(8);
		lt3.push_back(7);
		lt3.push_back(6);
		lt1 = lt3;
		for (auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
