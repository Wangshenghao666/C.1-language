#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//作业标题
//调整奇数偶数顺序
//作业内容
//调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分, 所有偶数位于数组的后半部分。
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		while ((left < right) && (arr[left] % 2 == 1))//从前向后找到一个偶数
//		{
//			left++;
//		}
//		while ((left < right) && (arr[right] % 2 == 0))//从后向前找到一个奇数
//		{
//			right--;
//		}
//		if (left < right)//交换
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);//过程
//	print(arr, sz);//打印函数
//	
//	return 0;
//}





//描述
//KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
//输入描述：
//多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
//输出描述：
//针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。
//int main()
//{
//	int y = 0;
//	int m = 0;
//	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (scanf("%d %d", &y, &m) != EOF)
//	{
//		int day = days[m - 1];
//		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//		{
//			if (m == 2)
//				day++;
//		}
//		printf("%d\n", day);
//	}
//	return 0;
//}






//作业标题
//杨辉三角
//作业内容
//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//……
//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			if (i == j)
//				arr[i][j] = 1;
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}




//
//作业标题
//猜凶手
//作业内容
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词 :
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			break;
//		}
//	}
//	printf("%c\n", killer);
//
//	return 0;
//}