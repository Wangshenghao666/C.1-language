#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<assert.h>

作业标题
使用指针打印数组内容
作业内容
写一个函数打印arr数组的内容，不使用数组下标，使用指针。
arr是一个整形一维数组。

void print(const int* p, int sz)
{
	assert(p);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	return 0;
}





作业标题
计算求和
作业内容
求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
例如：2 + 22 + 222 + 2222 + 22222
int main()
{
	int a = 0;
	int n = 0;
	scanf("%d %d", &a, &n);
	int sum = 0;
	int k = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		k = k * 10 + a;
		sum += k;
	}
	printf("%d\n", sum);
	return 0;
}



作业标题
打印水仙花数（简称自幂数-- - 如果在一个固定的进制中，一个n位自然数等于自身各个数位上数字的n次幂之和，则称此数为自幂数。）
例如：在十进制中，153是一个三位数，各个数位的3次幂之和为1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 153，所以153是十进制中的自幂数。
在n进制中，所有小于n的正整数都为自幂数，比如2进制中1是自幂数，3进制中1和2都是自幂数，4进制中1，2和3都是自幂数......
作业内容
求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。

#include<math.h>
int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++)
	{
		//判断i是否是自幂数
		int tmp = i;//创建一个临时变量，；来赋值i
		int sum = 0;
		//1.计算i的位数--n
		int count = 1;
		while (tmp /= 10)
		{
			count++;
		}
		//2.在计算i的每一位n次方之后
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, count);//pow是计算次方的函数,引头文件math.h
			tmp /= 10;
		}
		//3.判断
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	return 0;
}






作业标题
字符串逆序
作业内容
写一个函数，可以逆序一个字符串的内容。
void exchange(char* str)
{
	int len = strlen(str);//将int改为unsigned int更为适合。
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int tmp =str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
}
int main()

{
	char arr[100] = { 0 };

	//输入
	gets(arr);//scanf读取\0就停止了，但是gets可以读取\0
	//逆序
	exchange(arr);
	//输出
	printf("%s\n", arr);
	return 0;
}
    用指针变量在解
void exchange(char* str)
{
	unsigned int len = strlen(str);
	char* left = str;
	char* right = str + len - 1;
	while (left <= right)
	{
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
int main()
{
	char arr[100] = { 0 };
	gets(arr);
	exchange(arr);
	printf(arr);//这样也可以，类似于 const char* str = "hehe\n";
	return 0;

}





作业标题
打印菱形
作业内容
用C语言在屏幕上输出以下图案：

int main()
{
	int line = 0;
	scanf("%d", &line);//假设输入7

	 上面----7行
	int i = 0;
	for (i = 0; i < line; i++)
	{
		打印一行
		打印空格
		int j = 0;
		for (j = 0; j <line-1-i ; j++)
		{
			printf(" ");
		}
		打印*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");	
	}
	下面---6行
	
	for (i = 0; i <line - 1; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)//先打印空格
		{
			printf(" ");
		}
		for (j = 0; j <(line - 1-i)*2-1 ; j++)//在打印*
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}




作业标题
喝汽水问题
作业内容
喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);//输入钱数
	//购买
	total += money;
	empty = money;
	//置换
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	//打印
	printf("%d\n", total);

	return 0;
}
另一种思路计算空瓶
int main()
{
	int money = 0;
    int total = 0;
	int empty = 0;
	scanf("%d", &money);
	if (money >= 1)
	{
		total = 2 * money - 1;
	}
	else
	{
		total = 0;
	}
	printf("%d\n", total);
	return 0;
}

