/*��̺��������ַ���������С��20���ַ���
���滻���ܷ�������롣
�滻���ܵļ��ܹ����ǣ�
��ԭ������ĸ����ĸ���������ĵ�3����ĸ���滻��
������ĸ��������������ĸ���ɽ���ĸ��������β�νӵġ�
����ĸc����f���滻����ĸy��b���滻��
���������ַ���Ϊ��Study��������ܺ���ַ���Ϊ��Vwxgb����
������
Study
Vwxgb

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
char ShiftChar(char x, int n);

int main()
{
	char str[200];
	(void)scanf("%s", str);
	int i = 0;
	while (str[i])
	{
		str[i++] = ShiftChar(str[i], 3);
	}
	printf("%s", str);
	return 0;
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
