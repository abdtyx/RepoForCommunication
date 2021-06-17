/// <ID>C088</ID>
/// <date>2020/11</date>
/// <summary>
/// ���ַ����ײ���* ��ȫ���Ƶ��ַ�����β����
/// �м�����* �ţ������м��* �Ų������ַ������Ȳ�����200.
/// </summary>
/// <input>�ַ���</input>
/// <output>�ƶ���Ľ��</output>
/// <sample>
/// *** street***** music***
/// street***** music******
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

int main()
{
	char starStr[200];
	(void)scanf("%s", starStr);

	int i = 0;
	while (starStr[i++] == '*'); //����ǰ��һ���ж��ٸ�*
	strcpy(starStr, starStr + i - 1); //��ȥ��ʼ��*

	int len = strlen(starStr);
	for (int m = 0; m < i - 1; m++) //����ͬ������*��ӵ�β��
	{
		starStr[m + len] = '*';
	}
	starStr[len + i - 1] = 0; //���ý�β���

	printf("%s", starStr);
	return 0;
}
