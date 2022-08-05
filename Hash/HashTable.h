#pragma once

//��ɢ��---���Ŷ�ַ��
namespace CloseHash
{
	enum Status
	{
		EXIST,
		EMPTY,
		DELETE
	};
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _status = EMPTY;//״̬���
	};

	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	//������Ŀ��Ը�һ���ػ�
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& s)
		{
			//BKDR
			size_t value = 0;
			for (auto ch : s)
			{
				value *= 31;
				value += ch;
			}
			return value;
		}
	};
	//struct HashFunc
	//{
	//	size_t operator()(const string& s)
	//	{
	//		//BKDR
	//		size_t value = 0;
	//		for (auto ch : s)
	//		{
	//			value *= 31;
	//			value += ch;
	//		}
	//		return value;
	//	}
	//};
	template<class K, class V, class HashFunc = Hash<K>>
	class HashTable
	{
	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;//��Ч���ݸ���
	public:
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret == nullptr)
			{
				return false;
			}
			else
			{
				--_n;
				ret->_status = DELETE;
				return true;
			}
		}
		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			HashFunc hf;
			size_t start = hf(key) % _tables.size();//ע�ⲻ����capacity----[]����һ������size����֮��
			size_t i = 0;
			size_t index = start + i;

			while (_tables[index]._status != EMPTY)
			{
				if (_tables[index]._kv.first == key && _tables[index]._status == EXIST)
				{
					return &_tables[index];
				}
				++i;
				index = start + i;//����̽��
				//index = start + i * i;//����̽��
				index %= _tables.size();
			}
			return nullptr;
		}
		bool Insert(const pair<K, V>& kv)
		{
			HashData<K, V>* ret = Find(kv.first);
			if (ret)
			{
				return false;
			}
			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
			{
				//����
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;

				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i]._status == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}
				//����
				_tables.swap(newHT._tables);
			}

			HashFunc hf;
			size_t start = hf(kv.first) % _tables.size();//ע�ⲻ����capacity----[]����һ������size����֮��
			size_t i = 0;
			size_t index = start + i;

			while (_tables[index]._status == EXIST)
			{
				++i;
				index = start + i;//����̽��
				//index = start + i*i;//����̽��
				index %= _tables.size();
			}
			_tables[index]._kv = kv;
			_tables[index]._status = EXIST;
			++_n;

			return true;
		}
	};

	void TestHashTable()
	{
		HashTable<int, int> ht;
		int a[] = { 2,12,22,32,42,52 };
		for (auto& e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(62, 62));
		ht.Insert(make_pair(72, 72));
		ht.Insert(make_pair(32, 32));
		cout << ht.Find(12) << endl;
		ht.Erase(12);
		cout << ht.Find(12) << endl;

	}
	void TestHashTable2()
	{
		HashTable<string, string> ht;
		ht.Insert(make_pair("sort", "����"));
		ht.Insert(make_pair("string", "�ַ���"));
	}
}




namespace LinkHash
{
	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	// �ػ�
	template<>
	struct Hash < string >
	{
		size_t operator()(const string& s)
		{
			// BKDR
			size_t value = 0;
			for (auto ch : s)
			{
				value *= 31;
				value += ch;
			}
			return value;
		}
	};
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{}
	};

	template<class K, class V, class HashFunc = Hash<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		bool Erase(const K& key)
		{
			if (_tables.empty())
			{
				return false;
			}

			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr) // ͷɾ
					{
						_tables[index] = cur->_next;
					}
					else // �м�ɾ��
					{
						prev->_next = cur->_next;
					}

					--_n;

					delete cur;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

		Node* Find(const K& key)
		{
			if (_tables.empty())
			{
				return nullptr;
			}

			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}

			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			Node* ret = Find(kv.first);
			if (ret)
				return false;

			HashFunc hf;
			// �������� == 1ʱ����
			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				newTables.resize(newSize);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t index = hf(cur->_kv.first) % newTables.size();
						// ͷ��
						cur->_next = newTables[index];
						newTables[index] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			size_t index = hf(kv.first) % _tables.size();
			Node* newnode = new Node(kv);
			// ͷ��
			newnode->_next = _tables[index];
			_tables[index] = newnode;

			++_n;
			return true;
		}

	private:
		/*struct Data
		{
			forward_list<T> _list;
			set<T> _rbtree;
			size_t _len;
		};
		vector<Data> _tables;*/
		vector<Node*> _tables;

		size_t _n = 0;  // ��Ч���ݵĸ���
	};

	void TestHashTable()
	{
		int a[] = { 4, 24, 14,7,37,27,57,67,34,14,54 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(84, 84));
	}
}