/*��д���������ַ������ַ�����s�У�
���ַ����еĿո����Ϊ���ţ�ÿ1���ո��Ӧ1��Ӣ�Ķ��ţ��� 
����һ�У��ַ����� 
���һ�У��ı����ַ����� 
��û�пո�������ַ�����NotFound����

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int ReplaceChar(char* str, char ch, char repCh);

int main()
{
	char str[200];
	(void)scanf("%[^\n]", str);
	printf("%s", ReplaceChar(str, ' ', ',') == 0 ? "NotFound" : str);
	return 0;
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
