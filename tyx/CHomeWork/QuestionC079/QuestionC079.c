/*��д�ַ�����ת�������ú�����ָ���ַ����е��ַ�����˳��ߵ����С��ú�����ԭ��Ϊ��
char* Mystrrev(char string[]);
���в���string�Ǵ���ת���ַ������ú����ķ���ֵΪ����˳��ߵ�����ַ���ָ�롣
��д���������������������в��ԡ�
������
abcdefghijklmn
nmlkjihgfedcba

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

char* Mystrrev(char* str);

int main()
{
	char str[200];
	(void)scanf("%[^\n]", str);
	printf("%s", Mystrrev(str));
	return 0;
}

/// <summary>
/// ��ת�ַ�����strrev��c99��׼�в��Ǳ�׼�⺯����һЩ��������û�ṩ
///����������ṩ�˸ú���������ʹ�ñ������ṩ�İ汾
/// </summary>
/// <param name="str">����ת���ַ���</param>
/// <returns>��ת����ַ���</returns>
char* Mystrrev(char* str)
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
