#pragma once

//vector的基本框架
namespace wsh
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator  end() const
		{
			return _finish;
		}
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}


		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		//一个类模板的成员函数，又可以是一个函数模板
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}



		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//扩容
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * size());//这里是值拷贝，浅拷贝
					for (size_t i = 0; i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}



		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				//扩容
				//size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				//size_t sz = size();//将原来的数据先保留
				//T* tmp = new T[newcapacity];
				////拷贝数据
				//if (_start)
				//{
				//	memcpy(tmp, _start, sizeof(T) * size());
				//	delete[] _start;
				//}
				////重新赋值
				//_start = tmp;
				//_finish = _start + sz;
				//_endofstorage = _start + newcapacity;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			//kan 是否扩容
			if (_finish == _endofstorage)
			{
				//扩容会导致pos失效，需要提前一下更新
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;

			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}
	
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}



	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	//测试



	void vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		v.push_back(7);
		v.push_back(8);
		v.push_back(9);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		vector<int> v2(v);
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int> v3;
		v3.push_back(10);
		v3.push_back(20);
		v3.push_back(30);
		for (size_t i = 0; i < v3.size(); ++i)
		{
			cout << v3[i] << " ";
		}
		cout << endl;
		v = v3;
		/*v3.pop_back();
		v3.pop_back();
		v3.pop_back();
		v3.pop_back();*/
		for (size_t i = 0; i < v3.size(); ++i)
		{
			cout << v3[i] << " ";
		}
		cout << endl;
	}
	void vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		//vector<int>::iterator it = find(v.begin(), v.end(),2);
		//if (it != v.end())
		//{
		//	//这里it找返回值，否则会使迭代器失效
		//	v.insert(it, 20);
		//}
		//for (auto& e : v)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;

	    //删除n所有的偶数
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;

	}
	void vector4()
	{
		vector<string> v;
		v.push_back("1111111111");
		v.push_back("1111111111");
		v.push_back("1111111111");
		v.push_back("1111111111");
		v.push_back("1111111111");
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}