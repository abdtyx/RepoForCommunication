/*һ���ַ����������1���ַ������һ���ַ���ͬ��
��2���ַ��͵�����2����ͬ��...�����Ϊ�����ַ�����
��ƻ��Ĵ�����deed��
����һ���ַ������ж��Ƿ�����ַ�������������ʾYES��������ʾNO��������ַ������Ȳ�����200.
����1��
deed
YES
��2��
good
NO

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main()
{
	char str[220];
	(void)scanf("%s", str);
	char revStr[220];
	strcpy(revStr, str);
	printf("%s", strcmp(str, _strrev(revStr)) == 0 ? "YES" : "NO");
	return 0;
}
