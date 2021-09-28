#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	//char是0-255
	//存储到a和b中发生截断
	unsigned char a = 200;
	//二进制unsigned 
	//00000000000000000000000011001000  -- a
	//截断 11001000
	//整型提升 unsigned提升  00000000000000000000000011001000
	unsigned char b = 100;
	//00000000000000000000000001100100  -- b
	//截断 01100100
	//整型提升 unsigned提升  00000000000000000000000001100100
	unsigned char c = 0;
	c = a + b;
	//00000000000000000000000100101100
	//截断 00101100
	//整型提升 unsigned提升  00000000000000000000000000101100  --  44
	printf("%d %d", a + b, c);
	//所以a+b还没有进行存储--300，c是44
	return 0;
}





作业标题
猜名次
作业内容
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2) + (a == 3) == 1) &&
							((b == 2) + (e == 4) == 1) &&
							((c == 1) + (d == 2) == 1) &&
							((c == 5) + (d == 3) == 1) &&
							((e == 4) + (a == 1) == 1) )
						{
							if (a*b*c*d*e == 120)
							printf("a = %d b = %d c = %d d = %d e = %d\n ", a, b, c, d, e);
							
						}
					}
				}
			}
		}
	}
	return 0;
}




作业标题
字符串左旋
作业内容
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
#include<string.h>
#include<assert.h>

void left_move(char * arr, int k)
{
	assert(arr);//断言（防止有空指针传过来）
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		//左旋转一个字符
		//1.保存第一个字符
		char tmp = *arr;
		//2.把后续的字符依次往前移动
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		//3.把保存好的第一个字符放到最后
		*(arr + len - 1) = tmp;
	}
}
int main()
{
	//char * p = "abcd";err
	char arr[] = "abcd";
	left_move(arr, 2);
	printf("%s\n",arr);
	return 0;
}
再来一种方法
void reverse(char * l, char * r)
{
	assert(l && r);
	while (l < r)
	{
		char tmp = *l;
		*l = *r;
		*r = tmp;
		l++;
		r--;
	}
}
void left_move(char * arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	k %= len;
	reverse(arr,arr+k+1);//逆序左边
	reverse(arr+k,arr+len-1);//逆序右边
	reverse(arr,arr+len-1);//逆序整个字符串

}
int main()
{
	char arr[] = "abcde";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}





作业标题
字符串旋转结果
作业内容
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 = AABCD和s2 = BCDAA，返回1
给定s1 = abcd和s2 = ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
void reverse(char * l, char * r)
{
	assert(l && r);
	while (l < r)
	{
		char tmp = *l;
		*l = *r;
		*r = tmp;
		l++;
		r--;
	}
}
void left_move(char * arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	k %= len;
	reverse(arr,arr+k-1);//逆序左边
	reverse(arr+k,arr+len-1);//逆序右边
	reverse(arr,arr+len-1);//逆序整个字符串

}
int is_left_move(char arr1[], char arr2[])
{
	assert(arr1 && arr2);
	int len = strlen(arr1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(arr1,1);
		if (strcmp(arr1, arr2) == 0)
		{
			return 1;//是
		}
	}
	return 0;//不是

}
int main()
{
	char arr1[] = "AABCD";
	char arr2[] = "BCDAA";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
	{
		printf("YES\n");

	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
再来一种方法（进阶）
int is_left_move(char arr1[], char arr2[])
{
	assert(arr1, arr2);
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
	{
		return 0;
	}
	1.给arr1后面追加一个arr1中的字符串
	strncat(arr1, arr1, len1);//strncat是追加函数
	2.判断arr2是否是arr1的子串
	if (NULL == strstr(arr1, arr2))//strstr判断是不是arr1的子串
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	char arr1[20] = "aabcd";
	char arr2[20] = "bcdaa";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}