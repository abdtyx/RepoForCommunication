/*��д��������һ���ַ���str��ָ�����ַ�chɾȥ�������ظ����ֵ��ַ�����
����д���������е��ò��ԡ�����ԭ��:  void delchar(char* str, char ch); ��
���룺
ռ���С�
��1�У����������ַ�����ע��������ַ������Ȳ��ᳬ��80��
��2�У�����һ���ַ�
�����
ռһ��

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

char* DelChar(char* str, char ch);

int main()
{
	char str[200];
	char ch;

	//����һ���ַ������Իس���β�������س����ٶ���һ���ַ�
	(void)scanf("%[^\n]%*c%c", str, &ch);
	printf("%s", DelChar(str, ch));
	return 0;
}

/// <summary>
/// ���ַ�����ָ�����ַ�ɾ��
/// </summary>
/// <param name="str">��������ַ���</param>
/// <param name="ch">��Ҫɾ�����ַ�</param>
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
