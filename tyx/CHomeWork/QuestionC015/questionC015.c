/// <ID>C105</ID>
/// <date>2020/11</date>
/// <summary>
/// �Ӽ�������һ��λ��������20λ���޷��Ŷ���������������ת��Ϊʮ���ơ�
/// </summary>
/// <input>����������(�ַ�����</input>
/// <output>��Ӧ��ʮ��������������</output>
/// <sample>
/// 1001100101010101
/// 39253
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	char inputBinaryString[50];
	(void)scanf("%s", inputBinaryString);

	int x = 0;
	int i = 0;
	while (inputBinaryString[i])
	{
		x = x * 2 + inputBinaryString[i++] - '0';
	}

	printf("%d", x);
	return 0;
}
