#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include "FunctionList.h"
#include<stdio.h>
#include<string.h>

int main()
{
	return 0;
}



/// <summary>
/// ��x��ת����123��תλ321
/// </summary>
/// <param name="x">����ת����</param>
/// <returns>��ת��Ľ��</returns>
int Resverse(int x)
{
	int resx = 0;
	while (x)
	{
		resx = resx * 10 + x % 10;
		x /= 10;
	}
	return resx;
}

/// <summary>
/// �ж�һ�����Ƿ�������
/// </summary>
/// <param name="x">�ж�x�Ƿ�������</param>
/// <returns>���򷵻�1�����򷵻�0</returns>
int IsPrime(int x)
{
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

/// <summary>
/// ð������
/// </summary>
/// <param name="a">�����������</param>
/// <param name="n">����ĸ���</param>
void Bubble(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int t = a[j];
				a[j] = a[j - 1];
				a[j - 1] = t;
			}
		}
	}
}

/// <summary>
/// ɾ���ַ�����ָ�����ַ�
/// </summary>
/// <param name="str">������ַ���</param>
/// <param name="ch">ɾ�����ַ�</param>
/// <returns>ɾ������ַ���</returns>

char* DelChar(char* str, char ch)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			int j = 0;
			while (str[i + j + 1])
			{
				str[i + j] = str[i + j + 1];
				j++;
			}
			str[i + j] = 0;
		}
		else
		{
			i++;
		}
	}
	return str;
}


/// <summary>
/// ����һ���ַ��Ƿ���һ������
/// </summary>
/// <param name="str">���ҵ��ַ���</param>
/// <param name="ch">���ҵ��ַ�</param>
/// <returns>���ҵ������±꣨��0��ʼ�����ص�һ���ҵ����±꣩û�У�����-1</returns>
int Search(char* str, char ch)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			return i;
		}
		i++;
	}
	return -1;
}

///<summary>
/// ����ĸx������ĸ�������ĵ�n����ĸ���棬
/// ����n��ʱ�ٴ���ĸaѭ������
/// </summary>
/// <param name="x">�滻����ĸ</param>
/// <param name="n">�滻ֵ</param>
/// <returns>�滻�����ĸ,���x������ĸ���򷵻�x</returns>
char ShiftChar(char x, int n)
{
	if ('A' <= x && x <= 'Z')
	{
		x = (x - 'A' + n) % 26 + 'A';
	}
	if ('a' <= x && x <= 'z')
	{
		x = (x - 'a' + n) % 26 + 'a';
	}
	return x;
}

/// <summary>
/// �ж��Ƿ�Ϊ����
/// </summary>
/// <param name="year">���</param>
/// <returns>�ǣ�����1����0</returns>
int IsLeapyear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/// <summary>
/// �ж�����x�ĸ���λ�Ƿ�����ͬ��
/// </summary>
/// <param name="x">����x</param>
/// <returns>û����ͬ��λ����1�����򷵻�0</returns>
int IsDifferent(int x)
{
	int num = 0;
	int a[100];
	while (x)
	{
		a[num++] = x % 10;
		x /= 10;
	}

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (a[i] == a[j])
			{
				return 0;
			}
		}
	}
	return 1;
}

/// <summary>
/// ���ַ�����ͷ��ָ�����ַ�ɾ��
/// for example, "sss123ss" after removed 's' is "123ss"
/// </summary>
/// <param name="str">the original character string</param>
/// <param name="ch">the character will be removed</param>
/// <returns>the pointer of string after removed</returns>
char* RemoveCharAtBegin(char* str, char ch)
{
	int i = 0;
	//find the first character that do not equal ch
	while (str[i] == ch && str[i] != 0)
	{
		i++;
	}
	int j = 0;
	//remove the character
	while ((str[j++] = str[i++]) != 0);
	/*while(str[i]!=0)
	{
		str[j++] = str[i++];
	}*/
	return str;
}

/// <summary>
/// ���ַ�����β��ָ�����ַ�ɾ��
/// for example, "sss123ss" after removed 's' is "sss123"
/// </summary>
/// <param name="str">the original character string</param>
/// <param name="ch">the character will be removed</param>
/// <returns>the pointer of string after removed</returns>
char* RemoveCharAtEnd(char* str, char ch)
{
	int i = strlen(str);
	i--;
	//find the last character equal ch form the end of string
	while (str[i] == ch && i >= 0)
	{
		i--;
	}
	//put the zero end of string
	str[++i] = 0;
	return str;
}

/// <summary>
/// �ж�һ����n�Ƿ��ǻ�����
/// </summary>
/// <param name="n">�����n</param>
/// <returns>���򷵻�1���񷵻�0</returns>
int IsPalindrome(int n)
{
	int resN = 0;
	int m = n;
	while (n)
	{
		resN = resN * 10 + n % 10;
		n /= 10;
	}
	return m == resN;
}

/// <summary>
/// ��ת�ַ�����strrev��c99��׼�в��Ǳ�׼�⺯����һЩ��������û�ṩ
///����������ṩ�˸ú���������ʹ�ñ������ṩ�İ汾
/// </summary>
/// <param name="str">����ת���ַ���</param>
/// <returns>��ת����ַ���</returns>
char* MyStrrev(char* str)
{
	int j = strlen(str); //the length of string
	for (int i = 0; i < j / 2; i++) //swap head and tail
	{
		char t = str[i];
		str[i] = str[j - i - 1];
		str[j - i - 1] = t;
	}
	return str;
}

/// <summary>
/// ���ַ����е�ĳһ���ַ��滻Ϊ��һ���ַ�
/// </summary>
/// <param name="str">�滻���ַ���</param>
/// <param name="ch">���滻���ַ�</param>
/// <param name="repCh">�滻����ַ�</param>
/// <returns>�滻���ַ�����</returns>
int ReplaceChar(char* str, char ch, char repCh)
{
	int i = 0;
	int sum = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			str[i] = repCh;
			sum++;
		}
		i++;
	}
	return sum;
}


/// <summary>
/// ��������ָ���Ľ��ƣ�2<=radix<=16) �ֽ�Ϊ�ַ���
/// </summary>
/// <param name="num">num, the decomposed character string���ֽ���Ž�����ַ���</param>
/// <param name="n">n, the integer will be decomposed�����ֽ������</param>
/// <param name="radix">radix, the specified base��ָ���Ľ���</param>
/// <returns>the pointer of the decomposed character string,
///that is the pointer of num��ָ��ֽ����ַ�����ָ�룬Ҳ����ָ��num��ָ��</returns>
char* IntToString(char* num, int n, int radix)
{
	int i = 0;
	while (n)
	{
		int m = n % radix;
		if (0 <= m && m <= 9) //convert it to ASCII code
		{
			num[i++] = m + '0';
		}
		else //convert it to 'A'-'F' over 10
		{
			num[i++] = m - 10 + 'A';
		}
		n = n / radix; //the next number
	}
	num[i] = 0;
	_strrev(num); //reverse the string
	return num;
}


/// <summary>
/// ��һ���ַ�����ָ���ַ��ָ�Ϊ�����ַ����洢����ά������
/// Separate a string into several strings according
/// to the specified characters and
/// store them in a two - dimensional array
/// </summary>
/// <param name="split">the 2-D array stored the substrings
/// ��ŷֽ�����2ά����</param>
/// <param name="str">the original character string��ԭʼ�ַ���</param>
/// <param name="x">the separated character���ָ��ַ�</param>
/// <returns>the number of separator strings���ָ�����ַ�����Ŀ</returns>��

int SplitString(char split[][100], char* str, char x)
{
	RemoveCharAtEnd(str, x);
	RemoveCharAtBegin(str, x);
	int sum = 0;
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if (str[i] == x) //meet the separated character
		{
			split[sum][j] = 0; //the end of this line
			sum++;
			j = 0;
			while (str[i++] == x); //skip consecutive separators
			i--;
		}
		else
		{
			split[sum][j++] = str[i++]; //copy to the 2-D array
		}
	}
	split[sum][j] = 0;
	return ++sum;
}
