#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<array>

using namespace std;

////������ģ�����
//template<class T,size_t N>
//class MyStack
//{
//public:
//	void push(const T& x)
//	{
//	}
//private:
//	T _a[N];
//	size_t _top;
//};
//int main()
//{
//	MyStack<int, 100> st1;
//	MyStack<int, 200> st2;
//	return 0;
//}



////array
//int main()
//{
//	array<int, 10> aa1;
//	int aa2[10];
//	cout << sizeof(aa1) << endl;
//	cout << sizeof(aa2) << endl;
//
//	aa1[4] = 4;
//	aa2[4] = 4;
//
//	aa1[20] = 20;
//	//aa2[20] = 20;
//	return 0;
//}



//����ģ�壬����ƥ��
template<class T>
bool objless(const T& x, const T& y)
{
	return x < y;
}
//bool objless(const Date*& x, const Date*& y)
//{
//	return *x < *y;
//}
//ר�û���
//template<>
//bool objless<Date*>(Date* x,Date* y)
//{
//	return *x < *y;
//int main()
//{
//	cout << objless(1, 2) << endl;
//	Date* p1 = new Date(2022, 3, 2);
//	Date* p2 = new Date(2022, 3, 3);
//	return 0;
//}



////�ػ�-���⻯����Ҫ���ĳЩ�������⻯����
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<>
//class Data<int, char> {
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//void TestVector()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//}
//int main()
//{
//	TestVector();
//	return 0;
//}


//template<class T1,class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
////ȫ�ػ�:
//template<>
//class Data<int, char>
//{
//public:
//	Data()
//	{
//		cout << "Data<int,char>" << endl;
//	}
//private:
//	//...
//};
////ƫ�ػ���
//template<class T1>
//class Data<T1,char>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,char>" << endl;
//	}
//private:
//	//...
//};
//template<class T1,class T2>
//class Data<T1*,T2*>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1*,T2*>" << endl;
//	}
//private:
//	//...
//};
//template<class T1, class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1&,T2&>" << endl;
//	}
//private:
//	//...
//};
//
//int main()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//
//	Data<char, char> d3;
//	Data<double, char> d4;
//	Data<double*, char*> d5;
//	Data<char&, char&> d6;
//	return 0;
//}

//--->������Ҳ���ػ�



//------------------------------------------------------------------------------------------------------------>>
