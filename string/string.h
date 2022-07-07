#pragma once

namespace wsh
{
	class string
	{
	public:
		string(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
	};
	void test_string1()
	{
		string s1("hello");
		string s2(s1);
		string s3("sort");
		s3 = s1;
	}
}




namespace zj
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			,_capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		size_t size()
		{
			return _size;
		}
		const char* c_str() const
		{
			return _str;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	void f(const string& s)
	{
		cout << s[0] << endl;
	}
	void test_string()
	{
		string s1("wangshenghao");
		cout << s1.c_str() << endl;
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

	}
	void test_string2()
	{
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			*it += 1;
			++it;
		}
		it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto& e : s1)
		{
			cout << e << "-";
		}
		cout << endl;
	}
}




namespace wsh1
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		size_t size()
		{
			return _size;
		}
		const char* c_str() const
		{
			return _str;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		//拷贝和赋值都用swap分装
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}
		//现代写法拷贝
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp = s._str;
			/*swap(_str, tmp._str);
			swap(_size, tmp._size);
			swap(_capacity, tmp._capacity);*/
			swap(tmp);
		}
		//现代的赋值
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);//把原来的数据拷贝过来
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] += ch;
			_size++;
			_str[_size] = '\0';
			//insert(_size,ch);
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len;
			//insert(_size,str);
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				memset(_str + _size, ch, n - _size);
				_size = n;
				_str[_size] = '\0';
			}
		}
		size_t find(char ch)
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* s, size_t pos = 0)
		{
			const char* ptr = strstr(_str + pos, s);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}
		string& insert(size_t pos, const char* s)
		{
			assert(pos <= _size);
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos,s, len);
			_size += len;
			return *this;
		}
		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
	
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
	};
	const size_t string::npos = -1;


	bool operator<(const string& s1, const string& s2)
	{
		/*size_t i1 = 0; size_t i2 = 0;
		while (i1 < s1.size() && i2 < s2.size())
		{
			if (s1[i1] < s2[i2])
			{
				return true;
			}
			else if (s1[i1] > s2[i2])
			{
				return false;
			}
			else
			{
				++i1; ++i2;
			}
		}
		return i2 < s2.size() ? true : false;*/
		//简化
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}
	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}



	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}




	void test_string1()
	{
		string s1("zhangji");
		string s2(s1);

		string s3("Sort");

	}
	void test_string2()
	{
		string s1("zhangji");
		cout << s1.c_str() << endl;

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		printf("\n");

		string s2("wangshenghao");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		printf("\n");

		for (auto e : s1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_string3()
	{
		string s1("zhangji");
		s1.push_back(' ');
		s1.push_back('@');
		s1.append("hello bit!!!!!!!!!!!!!!!!!!!!!");
		cout << s1.c_str() << endl;
		printf("------------------------------------\n");
		string s2;
		s2 += 'x';
		s2 += "yz 123";
		cout << s2.c_str() << endl;
	}
	void test_string4()
	{
		string s1("zhangji");
		s1.insert(0, "abc--");
		cout << s1.c_str() << endl;

	}
	void test_string5()
	{
		string s1("hello world");
		s1.erase(5, 2);
		s1.erase(5, 20);
	}
	void test_string6()
	{
		string s1("abcd");
		string s2("abcd");
		cout << (s1 < s2) << endl;
		string s3("abcd");
		string s4("abcde");
		cout << (s3 < s4) << endl;
		string s5("abcde");
		string s6("abcd");
		cout << (s5 < s6) << endl;
	}
	void test_string7()
	{
		string s1;
		cin >> s1;
		cout << s1;
	}
}
