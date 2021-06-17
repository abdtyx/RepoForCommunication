/// <ID>C036</ID>
/// <date>2020/11</date>
/// <summary>
/// K��������ת��������Ǹ�����a����ת��ΪK��������2 <= K <= 32��
/// K������ʹ�õķ�����0��9, A, ...V����ʾ����ĸ�Ǵ�д��
/// </summary>
/// <input>һ��ʮ���ƷǸ�����a��һ��������K���ո�ָ�</input>
/// <output>K���Ʊ�ʾ������</output>
/// <sample>
/// 1234567
/// 55KGF
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

char* IntToString(char* num, int n, int radix);

int main()
{
	int n;
	int k;
	(void)scanf("%d%d", &n, &k);
	char num[100];
	printf("%s", IntToString(num, n, k));
	return 0;
}

/// <summary>
/// ��������ָ���Ľ��ƣ�2<=radix<=32) �ֽ�Ϊ�ַ���
/// </summary>
/// <param name="num">num, the decomposed character string���ֽ���Ž�����ַ���</param>
/// <param name="n">n, the integer will be decomposed�����ֽ������</param>
/// <param name="radix">radix, the specified base��ָ���Ľ���</param>
/// <returns>the pointer of the decomposed character string,
/// that is the pointer of num��ָ��ֽ����ַ�����ָ�룬Ҳ����ָ��num��ָ��</returns>
char* IntToString(char* num, int n, int radix)
{
	int i = 0;
	if (n == 0)
	{
		strcpy(num, "0");
	}
	else
	{
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
	}
	return num;
}
