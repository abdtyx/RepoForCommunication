/// <ID>C085</ID>
/// <date>2020/11</date>
/// <summary>
/// �����ַ������ַ������������Ǻ�*, ȥ���ַ�����β���Ǻţ�* ����
/// �����м���Ǻš� �ַ������Ȳ�����200
/// </summary>
/// <input>����* �ŵ��ַ���</input>
/// <output>��β����* �ŵ��ַ���</output>
/// <sample>
/// ***street**music****
/// street**music
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

char* RemoveCharAtBegin(char* str, char ch);
char* RemoveCharAtEnd(char* str, char ch);

int main()
{
	char str[200];
	(void)scanf("%s", str);
	(void)RemoveCharAtBegin(str, '*');
	printf("%s", RemoveCharAtEnd(str, '*'));
	return 0;
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
