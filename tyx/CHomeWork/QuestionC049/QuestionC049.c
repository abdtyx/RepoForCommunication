/// <ID>C049</ID>
/// <date>2020/11</date>
/// <summary>
/// ����һ����дӢ����ĸ��
/// ����������ڵ���ĸ��������ĸA - Z��������β��ӵĻ�״���У�
/// </summary>
/// <input>��дӢ����ĸ</input>
/// <output>����ĸǰ�����ĸ������ĸ������ĸ�������ĸ��������ĸ���޼����</output>
/// <sample>
/// A
/// ZAB
/// </sample>
/// <sample>
/// B
/// ABC
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	char uppercaseLetter;
	(void)scanf("%c", &uppercaseLetter);
	printf("%c%c%c", uppercaseLetter - 1 < 'A' ? 'Z' : uppercaseLetter - 1, uppercaseLetter,
	       uppercaseLetter + 1 > 'Z' ? 'A' : uppercaseLetter + 1);
	return 0;
}
