/*����һ���ַ����ַ����еĵ�һ��λ�ò�������λ�á�
λ�ô�0��ʼ
���������ʽ��
���룺�����ҵ��ַ�������Ҫ���ҵ��ַ������ܺ��пո�
������ʱ�������ҵ��ַ�����������ҵ��ַ���* �Ÿ�����
���������ַ���* ��Ҫ���ҵ��ַ���
������ַ���λ��
�����ж����ͬ���ַ���ֻ���ҵ�һ������û����� - 1����

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

int Search(char* str, char ch);

#include<stdio.h>

int main()
{
	char inStr[100];
	gets_s(inStr, 100);

	int i = 0;
	while (inStr[i++] != '*');

	char ch = inStr[i];
	inStr[i - 1] = 0;
	printf("%d", Search(inStr, ch));
	return 0;
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
