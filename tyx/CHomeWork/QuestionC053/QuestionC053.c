/// <ID>C053</ID>
/// <date>2020/11</date>
/// <summary>
/// ������4����ĸ���ɵ�Ӣ�ĵ��ʣ������¸�ʽ�����ĸ��
/// ����ĸ��ASCII���Լ�����ĸ�ĺ���ַ�
/// ÿ���������֮����һ���ո�ָ���
/// </summary>
/// <input>4����ĸ���ɵ�Ӣ�ĵ���</input>
/// <output>��4�У�ÿ�������ĸ������ĸ��ASCII�룬����ĸ����ַ����ո�ָ���ÿ�е����û�пո�</output>
/// <sample>
/// love
/// l 108 m
/// o 111 p
/// v 118 w
/// e 101 f
/// </sample>
/// <sample>
/// zoom
/// z 122 {
///	o 111 p
/// o 111 p
/// m 109 n
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	char letter01, letter02, letter03, letter04;
	(void)scanf("%c%c%c%c", &letter01, &letter02, &letter03, &letter04);
	printf("%c %d %c\n", letter01, letter01, letter01 + 1);
	printf("%c %d %c\n", letter02, letter02, letter02 + 1);
	printf("%c %d %c\n", letter03, letter03, letter03 + 1);
	printf("%c %d %c\n", letter04, letter04, letter04 + 1);
	return 0;
}
