#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<assert.h>

��ҵ����
ʹ��ָ���ӡ��������
��ҵ����
дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
arr��һ������һά���顣

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





��ҵ����
�������
��ҵ����
��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
���磺2 + 22 + 222 + 2222 + 22222
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



��ҵ����
��ӡˮ�ɻ��������������-- - �����һ���̶��Ľ����У�һ��nλ��Ȼ���������������λ�����ֵ�n����֮�ͣ���ƴ���Ϊ����������
���磺��ʮ�����У�153��һ����λ����������λ��3����֮��Ϊ1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 153������153��ʮ�����е���������
��n�����У�����С��n����������Ϊ������������2������1����������3������1��2������������4������1��2��3����������......
��ҵ����
���0��100000֮������С�ˮ�ɻ������������
��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������

#include<math.h>
int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++)
	{
		//�ж�i�Ƿ���������
		int tmp = i;//����һ����ʱ������������ֵi
		int sum = 0;
		//1.����i��λ��--n
		int count = 1;
		while (tmp /= 10)
		{
			count++;
		}
		//2.�ڼ���i��ÿһλn�η�֮��
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, count);//pow�Ǽ���η��ĺ���,��ͷ�ļ�math.h
			tmp /= 10;
		}
		//3.�ж�
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	return 0;
}






��ҵ����
�ַ�������
��ҵ����
дһ����������������һ���ַ��������ݡ�
void exchange(char* str)
{
	int len = strlen(str);//��int��Ϊunsigned int��Ϊ�ʺϡ�
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

	//����
	gets(arr);//scanf��ȡ\0��ֹͣ�ˣ�����gets���Զ�ȡ\0
	//����
	exchange(arr);
	//���
	printf("%s\n", arr);
	return 0;
}
    ��ָ������ڽ�
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
	printf(arr);//����Ҳ���ԣ������� const char* str = "hehe\n";
	return 0;

}





��ҵ����
��ӡ����
��ҵ����
��C��������Ļ���������ͼ����

int main()
{
	int line = 0;
	scanf("%d", &line);//��������7

	 ����----7��
	int i = 0;
	for (i = 0; i < line; i++)
	{
		��ӡһ��
		��ӡ�ո�
		int j = 0;
		for (j = 0; j <line-1-i ; j++)
		{
			printf(" ");
		}
		��ӡ*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");	
	}
	����---6��
	
	for (i = 0; i <line - 1; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)//�ȴ�ӡ�ո�
		{
			printf(" ");
		}
		for (j = 0; j <(line - 1-i)*2-1 ; j++)//�ڴ�ӡ*
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}




��ҵ����
����ˮ����
��ҵ����
����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);//����Ǯ��
	//����
	total += money;
	empty = money;
	//�û�
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	//��ӡ
	printf("%d\n", total);

	return 0;
}
��һ��˼·�����ƿ
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

