#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	//char��0-255
	//�洢��a��b�з����ض�
	unsigned char a = 200;
	//������unsigned 
	//00000000000000000000000011001000  -- a
	//�ض� 11001000
	//�������� unsigned����  00000000000000000000000011001000
	unsigned char b = 100;
	//00000000000000000000000001100100  -- b
	//�ض� 01100100
	//�������� unsigned����  00000000000000000000000001100100
	unsigned char c = 0;
	c = a + b;
	//00000000000000000000000100101100
	//�ض� 00101100
	//�������� unsigned����  00000000000000000000000000101100  --  44
	printf("%d %d", a + b, c);
	//����a+b��û�н��д洢--300��c��44
	return 0;
}





��ҵ����
������
��ҵ����
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ������������
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




��ҵ����
�ַ�������
��ҵ����
ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB
#include<string.h>
#include<assert.h>

void left_move(char * arr, int k)
{
	assert(arr);//���ԣ���ֹ�п�ָ�봫������
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		//����תһ���ַ�
		//1.�����һ���ַ�
		char tmp = *arr;
		//2.�Ѻ������ַ�������ǰ�ƶ�
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		//3.�ѱ���õĵ�һ���ַ��ŵ����
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
����һ�ַ���
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
	reverse(arr,arr+k+1);//�������
	reverse(arr+k,arr+len-1);//�����ұ�
	reverse(arr,arr+len-1);//���������ַ���

}
int main()
{
	char arr[] = "abcde";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}





��ҵ����
�ַ�����ת���
��ҵ����
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 = AABCD��s2 = BCDAA������1
����s1 = abcd��s2 = ACBD������0.
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
AABCD����һ���ַ��õ�DAABC
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
	reverse(arr,arr+k-1);//�������
	reverse(arr+k,arr+len-1);//�����ұ�
	reverse(arr,arr+len-1);//���������ַ���

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
			return 1;//��
		}
	}
	return 0;//����

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
����һ�ַ��������ף�
int is_left_move(char arr1[], char arr2[])
{
	assert(arr1, arr2);
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
	{
		return 0;
	}
	1.��arr1����׷��һ��arr1�е��ַ���
	strncat(arr1, arr1, len1);//strncat��׷�Ӻ���
	2.�ж�arr2�Ƿ���arr1���Ӵ�
	if (NULL == strstr(arr1, arr2))//strstr�ж��ǲ���arr1���Ӵ�
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