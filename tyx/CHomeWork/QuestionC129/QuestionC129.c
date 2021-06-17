/// <ID>C129</ID>
/// <date>2020/11</date>
/// <summary>
/// ����һ�����ܴ��ո��ַ����ַ���(���Ȳ�����200)��
/// ͳ�����и���Ӣ����ĸ�ĳ��ִ����������ִ�Сд��
/// �����ĸa��z�ĳ��ִ��������ݼ���Ӣ�Ķ��ŷָ�����Ӣ����ĸ��ͳ�ơ�
/// </summary>
/// <input>���ܴ��ո���ַ���</input>
/// <output>26����������Ӣ�Ķ��ŷָ�</output>
/// <sample>
/// EOWfmmdlfo  eor - 035k WOPIEJRmflld 34
/// 0, 0, 0, 2, 3, 3, 0, 0, 1, 1, 1, 3, 3, 0, 4, 1, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main()
{
	char inputStr[200] = {0};
	gets_s(inputStr, 200);
	_strupr(inputStr); //ת��Ϊ��д
	int count[26] = {0};

	int i = 0;
	while (inputStr[i])
	{
		if (inputStr[i] >= 'A' && inputStr[i] <= 'Z')
		{
			count[inputStr[i] - 'A']++;
		}
		i++;
	}

	printf("%d", count[0]);
	for (i = 1; i < 26; i++)
	{
		printf(",%d", count[i]);
	}
	return 0;
}
