/// <ID>C135</ID>
/// <date>2020/11</date>
/// <summary>
/// ����һ�����֣�������ǰ����������еġ�5�������ɿո�
/// ��ô�͵õ�һ���ÿո�ָ�����ɷǸ�����
///��������Щ�����ԡ�0����ͷ����Щͷ���ġ�0��Ӧ�ñ����Ե���
/// ��������������������ɸ���0����ɵģ���ʱ�����������0����
/// ��������ǣ�����Щ�ָ�õ�������������С�����˳�����������
/// </summary>
/// <input>һ�����֣�����֮��û�пո񣩣��������ֵĳ��Ȳ�����1000���ָ�õ��ķǸ������������100000000</input>
/// <output>�ָ�õ�����������Ľ�������ڵ���������֮����һ���ո�ֿ������û�пո�</output>
/// <sample>
/// 005123123205077555
/// 0 77 12312320
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

int SplitString(char str[], char ch, char r[][100]);
int Convert(char str[]);
void Bubble(int a[], int n);

int main()
{
	char inputStr[1000];
	(void)scanf("%s", inputStr);
	//�ָ�
	char splitStr[100][100];
	int n;
	n = SplitString(inputStr, '5', splitStr);
	//ת��
	int num[100];
	for (int i = 0; i < n; i++)
	{
		num[i] = Convert(splitStr[i]);
	}
	//����
	Bubble(num, n);
	//���
	printf("%d", num[0]);
	for (int i = 1; i < n; i++)
	{
		printf(" %d", num[i]);
	}
	return 0;
}

int SplitString(char str[], char ch, char r[][100])
{
	int i = 0;
	int m = 0;
	int n = 0;
	while (str[i] == ch && str[i] != 0)
	{
		i++;
	}
	while (str[i] != 0)
	{
		while (str[i] != ch && str[i] != 0)
		{
			r[m][n] = str[i];
			n++;
			i++;
		}
		r[m][n] = 0;
		m++;
		n = 0;
		while (str[i] == ch && str[i] != 0)
		{
			i++;
		}
	}
	return m;
}

int Convert(char str[])
{
	int n = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		n = n * 10 + (str[i] - '0');
	}
	return n;
}

void Bubble(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}
